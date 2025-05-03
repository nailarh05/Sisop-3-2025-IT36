#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "shop.h"

#define PORT 8080
#define MAX 1024
#define MAX_CLIENT 100

typedef struct {
    int socket;
    int gold;
    int base_damage;
    Weapon* equipped;
    Weapon* inventory[10];
    int inv_count;
    int enemies_defeated;
} Player;

Player players[MAX_CLIENT];
int player_count = 0;

Player* get_player(int sock) {
    for (int i = 0; i < player_count; i++) {
        if (players[i].socket == sock) return &players[i];
    }
    players[player_count].socket = sock;
    players[player_count].gold = 100;
    players[player_count].base_damage = 10;
    players[player_count].equipped = &weapon_list[0];
    players[player_count].inventory[0] = &weapon_list[0];
    players[player_count].inv_count = 1;
    players[player_count].enemies_defeated = 0;
    return &players[player_count++];
}

void* handle_client(void* arg) {
    int sock = *(int*)arg;
    char buffer[MAX];
    Player* p = get_player(sock);

    while (1) {
        int len = recv(sock, buffer, MAX, 0);
        if (len <= 0) break;
        buffer[len] = '\0';
        int choice = atoi(buffer);

        char response[MAX*2] = "";
        if (choice == 1) {
            sprintf(response, "Gold: %d\nEquipped: %s\nBase Damage: %d\nEnemies Defeated: %d\n%s",
                p->gold, p->equipped->name, p->base_damage + p->equipped->damage, p->enemies_defeated,
                p->equipped->has_passive ? p->equipped->passive : "");
        } else if (choice == 2) {
            get_shop_display(response);
        } else if (choice == 3) {
            strcpy(response, "Inventory:\n");
            for (int i = 0; i < p->inv_count; i++) {
                char line[100];
                sprintf(line, "%s%s\n", p->inventory[i]->name,
                    p->inventory[i]->has_passive ? (char[100]){sprintf((char[100]){}, " (Passive: %s)", p->inventory[i]->passive), (char[100]){}} : "");
                strcat(response, line);
            }
        } else if (choice == 4) {
            int enemy_hp = rand() % 151 + 50;
            while (enemy_hp > 0) {
                int damage = p->base_damage + p->equipped->damage + (rand() % 6);
                if (rand() % 100 < 20) damage *= 2; // critical hit
                enemy_hp -= damage;
                if (enemy_hp <= 0) {
                    int reward = rand() % 51 + 50;
                    p->gold += reward;
                    p->enemies_defeated++;
                    sprintf(response, "You dealt %d damage and defeated the enemy! Gold +%d\n", damage, reward);
                    break;
                } else {
                    sprintf(response, "You dealt %d damage. Enemy HP left: %d\n", damage, enemy_hp);
                }
                send(sock, response, strlen(response), 0);
                recv(sock, buffer, MAX, 0); // wait for next attack or exit
                if (strcmp(buffer, "exit") == 0) {
                    strcpy(response, "Exited battle mode.\n");
                    break;
                }
            }
        } else if (choice == 5) {
            break;
        } else {
            strcpy(response, "Invalid Option!\n");
        }
        send(sock, response, strlen(response), 0);
    }
    close(sock);
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    init_shop();

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 10);
    printf("Server started on port %d\n", PORT);

    while ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen))) {
        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, &new_socket);
    }

    return 0;
}
