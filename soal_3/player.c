#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX 1024

void menu(int sockfd) {
    char buffer[MAX];
    int choice;

    while (1) {
        printf("\n=== Main Menu ===\n");
        printf("1. Show Stats\n");
        printf("2. Shop\n");
        printf("3. Inventory\n");
        printf("4. Battle\n");
        printf("5. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        sprintf(buffer, "%d", choice);
        send(sockfd, buffer, strlen(buffer), 0);

        if (choice == 5) break;

        int valread = recv(sockfd, buffer, sizeof(buffer), 0);
        buffer[valread] = '\0';
        printf("%s\n", buffer);
    }
}

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    menu(sockfd);
    close(sockfd);
    return 0;
}
