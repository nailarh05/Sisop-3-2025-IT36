#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>

#define SERVER_IP "127.0.0.1"
#define PORT 8080
#define BUFFER_SIZE 1024 * 1024
#define SECRETS_DIR "secrets"

int connect_to_server();
void display_menu();
void decrypt_text_file(int server_socket);
void download_file(int server_socket);
void read_text_file(const char *filename, char *content, size_t max_size);
void clear_screen();
void print_header();

int main() {
    int choice;
    int server_socket;
    char buffer[BUFFER_SIZE] = {0};
    
    mkdir("secrets", 0777);
    
    while (1) {
        clear_screen();
        print_header();
        display_menu();
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                server_socket = connect_to_server();
                if (server_socket < 0) {
                    printf("Failed to connect to server. Press Enter to continue...");
                    getchar();
                    continue;
                }
                
                decrypt_text_file(server_socket);
                close(server_socket);
                
                printf("\nPress Enter to continue...");
                getchar();
                break;
                
            case 2:
                server_socket = connect_to_server();
                if (server_socket < 0) {
                    printf("Failed to connect to server. Press Enter to continue...");
                    getchar();
                    continue;
                }
                
                download_file(server_socket);
                close(server_socket);
                
                printf("\nPress Enter to continue...");
                getchar();
                break;
                
            case 3:
                server_socket = connect_to_server();
                if (server_socket >= 0) {
                    sprintf(buffer, "EXIT");
                    send(server_socket, buffer, strlen(buffer), 0);
                    close(server_socket);
                }
                printf("Exiting program...\n");
                return 0;
                
            default:
                printf("Invalid choice. Press Enter to continue...");
                getchar();
        }
    }
    
    return 0;
}

void clear_screen() {
    printf("\033[2J\033[H");
}

void print_header() {
    printf("\n");
    printf("  _______ _            _                               _          __   _____             _   _    _     _\n");
    printf(" |__   __| |          | |                             | |        / _| |  __ \           | | | |  (_)   | |\n");
    printf("    | |  | |__   ___  | |     ___  __ _  ___ _ __   __| |   ___ | |_  | |__) |___   ___ | |_| | ___  __| |___\n");
    printf("    | |  | '_ \ / _ \ | |    / _ \/ _` |/ _ \ '_ \ / _` |  / _ \|  _| |  _  ∕/ _ \ / _ \| __| |/ / |/ _` / __|\n");
    printf("    | |  | | | |  __/ | |___|  __/ (_| |  __/ | | | (_| | | (_) | |   | | \ \ (_) | (_) | |_|   <| | (_| \__ \\n");
    printf("    |_|  |_| |_|\___| |______\___|\__, |\___|_| |_|\__,_|  \___/|_|   |_|  \_\___/ \___/ \__|_|\_\_|\__,_|___/\n");
    printf("                                   __/ |\n");
    printf("                                  |___/\n");
    printf("\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("                       Finding the legendary hacker from Semarang...\n");
    printf("--------------------------------------------------------------------------------------------------\n\n");
}

void display_menu() {
    printf("MENU:\n");
    printf("1. Decrypt secret text file\n");
    printf("2. Download JPEG file from server\n");
    printf("3. Exit\n");
}

int connect_to_server() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return -1;
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    if (inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr) <= 0) {
        printf("Invalid address or address not supported\n");
        return -1;
    }
    
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed\n");
        return -1;
    }
    
    return sock;
}

void decrypt_text_file(int server_socket) {
    char filename[256] = {0};
    char buffer[BUFFER_SIZE] = {0};
    char command[BUFFER_SIZE + 20] = {0};
    
    DIR *dir;
    struct dirent *ent;
    int file_count = 0;
    
    dir = opendir(SECRETS_DIR);
    if (dir == NULL) {
        printf("Failed to open secrets directory.\n");
        return;
    }
    
    printf("\nAvailable text files:\n");
    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_REG) {
            if (strstr(ent->d_name, ".txt") != NULL) {
                printf("%d. %s\n", ++file_count, ent->d_name);
            }
        }
    }
    closedir(dir);
    
    if (file_count == 0) {
        printf("No text files found in %s directory.\n", SECRETS_DIR);
        return;
    }
    
    printf("\nEnter the filename to decrypt: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;
    
    char filepath[512] = {0};
    snprintf(filepath, sizeof(filepath), "%s/%s", SECRETS_DIR, filename);
    
    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        printf("Error: File '%s' not found.\n", filename);
        return;
    }
    fclose(file);
    
    read_text_file(filepath, buffer, BUFFER_SIZE);
    
    sprintf(command, "DECRYPT %s", buffer);
    send(server_socket, command, strlen(command), 0);
    
    memset(buffer, 0, BUFFER_SIZE);
    if (read(server_socket, buffer, BUFFER_SIZE) <= 0) {
        printf("Failed to read response from server.\n");
        return;
    }
    
    char status[20], output_file[256];
    if (sscanf(buffer, "%19s %255s", status, output_file) != 2) {
        printf("Invalid response from server: %s\n", buffer);
        return;
    }
    
    if (strcmp(status, "SUCCESS") == 0) {
        printf("Decryption successful! File saved as: %s\n", output_file);
    } else {
        printf("Decryption failed: %s\n", buffer);
    }
}

void download_file(int server_socket) {
    char filename[256] = {0};
    char buffer[BUFFER_SIZE] = {0};
    char command[300] = {0};
    
    printf("\nEnter the filename to download (e.g., 1744403652.jpeg): ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;
    
    sprintf(command, "DOWNLOAD %s", filename);
    send(server_socket, command, strlen(command), 0);
    
    memset(buffer, 0, BUFFER_SIZE);
    if (read(server_socket, buffer, BUFFER_SIZE) <= 0) {
        printf("Failed to read response from server.\n");
        return;
    }
    
    if (strncmp(buffer, "ERROR", 5) == 0) {
        printf("Download failed: %s\n", buffer + 6);
        return;
    }
    
    send(server_socket, "ACK", 3, 0);
    
    memset(buffer, 0, BUFFER_SIZE);
    if (read(server_socket, buffer, BUFFER_SIZE) <= 0) {
        printf("Failed to read file size from server.\n");
        return;
    }
    
    long file_size = atol(buffer);
    
    send(server_socket, "ACK", 3, 0);
    
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Failed to create file: %s\n", filename);
        return;
    }
    
    size_t bytes_received = 0;
    size_t total_received = 0;
    
    printf("Downloading %s (%ld bytes)...\n", filename, file_size);
    
    while (total_received < file_size) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_received = read(server_socket, buffer, BUFFER_SIZE);
        
        if (bytes_received <= 0) {
            printf("Download interrupted. Received %zu of %ld bytes.\n", total_received, file_size);
            break;
        }
        
        fwrite(buffer, 1, bytes_received, file);
        total_received += bytes_received;
        
        printf("\rDownloaded: %zu / %ld bytes (%.1f%%)", 
               total_received, file_size, (float)total_received / file_size * 100);
        fflush(stdout);
    }
    
    printf("\nDownload complete! File saved as: %s\n", filename);
    fclose(file);
}

void read_text_file(const char *filename, char *content, size_t max_size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file: %s\n", filename);
        content[0] = '\0';
        return;
    }
    
    size_t bytes_read = fread(content, 1, max_size - 1, file);
    content[bytes_read] = '\0';
    
    fclose(file);
}
