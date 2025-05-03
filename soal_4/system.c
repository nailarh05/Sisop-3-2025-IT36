#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_HUNTER_KEY 1234
#define SHM_DUNGEON_KEY 5678
#define MAX_HUNTERS 100
#define MAX_DUNGEONS 50
#define USERNAME_LENGTH 32
#define PASSWORD_LENGTH 32
#define DUNGEON_NAME_LENGTH 32

typedef struct {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    int level;
    int exp;
    int atk;
    int hp;
    int def;
    bool is_used;
    bool is_banned;
} Hunter;

typedef struct {
    Hunter hunters[MAX_HUNTERS];
    bool system_active;
} SharedHunterData;

typedef struct {
    char name[DUNGEON_NAME_LENGTH];
    int level_min;
    int reward_exp;
    int reward_atk;
    int reward_hp;
    int reward_def;
    int dungeon_id;
    bool is_used;
} Dungeon;

typedef struct {
    Dungeon dungeons[MAX_DUNGEONS];
} SharedDungeonData;

void tampilkanSemuaHunter(SharedHunterData *data) {
    printf("\n=== Daftar Hunter Terdaftar ===\n");
    for (int i = 0; i < MAX_HUNTERS; i++) {
        if (data->hunters[i].is_used) {
            printf("[%d] %s | Lv:%d | EXP:%d | ATK:%d | HP:%d | DEF:%d | Status: %s\n",
                i+1, data->hunters[i].username, data->hunters[i].level,
                data->hunters[i].exp, data->hunters[i].atk,
                data->hunters[i].hp, data->hunters[i].def,
                data->hunters[i].is_banned ? "BANNED" : "AKTIF");
        }
    }
}

void tampilkanSemuaDungeon(SharedDungeonData *dungeon_data) {
    printf("\n=== Daftar Dungeon Tersedia ===\n");
    for (int i = 0; i < MAX_DUNGEONS; i++) {
        if (dungeon_data->dungeons[i].is_used) {
            printf("[%d] %s | Lv Min: %d | EXP:%d | ATK:%d | HP:%d | DEF:%d | ID: %d\n",
                i+1, dungeon_data->dungeons[i].name,
                dungeon_data->dungeons[i].level_min,
                dungeon_data->dungeons[i].reward_exp,
                dungeon_data->dungeons[i].reward_atk,
                dungeon_data->dungeons[i].reward_hp,
                dungeon_data->dungeons[i].reward_def,
                dungeon_data->dungeons[i].dungeon_id);
        }
    }
}

void generateDungeon(SharedDungeonData *dungeon_data) {
    for (int i = 0; i < MAX_DUNGEONS; i++) {
        if (!dungeon_data->dungeons[i].is_used) {
            Dungeon *d = &dungeon_data->dungeons[i];

            sprintf(d->name, "Dungeon-%03d", rand() % 1000);
            d->level_min = (rand() % 5) + 1;
            d->reward_atk = (rand() % 51) + 100;
            d->reward_hp = (rand() % 51) + 50;
            d->reward_def = (rand() % 26) + 25;
            d->reward_exp = (rand() % 151) + 150;
            d->dungeon_id = rand() % 100000;
            d->is_used = true;

            printf("Dungeon baru '%s' telah dibuat!\n", d->name);
            return;
        }
    }
    printf("Slot dungeon penuh!\n");
}

void banHunter(SharedHunterData *data) {
    char username[USERNAME_LENGTH];
    printf("Masukkan username hunter yang ingin diban: ");
    scanf("%s", username);

    for (int i = 0; i < MAX_HUNTERS; i++) {
        if (data->hunters[i].is_used && strcmp(data->hunters[i].username, username) == 0) {
            if (data->hunters[i].is_banned) {
                printf("Hunter '%s' sudah diban sebelumnya.\n", username);
            } else {
                data->hunters[i].is_banned = true;
                printf("Hunter '%s' berhasil diban.\n", username);
            }
            return;
        }
    }
    printf("Hunter dengan username '%s' tidak ditemukan.\n", username);
}

void unbanHunter(SharedHunterData *data) {
    char username[USERNAME_LENGTH];
    printf("Masukkan username hunter yang ingin di-unban: ");
    scanf("%s", username);

    for (int i = 0; i < MAX_HUNTERS; i++) {
        if (data->hunters[i].is_used && strcmp(data->hunters[i].username, username) == 0) {
            if (!data->hunters[i].is_banned) {
                printf("Hunter '%s' tidak dalam status ban.\n", username);
            } else {
                data->hunters[i].is_banned = false;
                printf("Hunter '%s' berhasil di-unban.\n", username);
            }
            return;
        }
    }
    printf("Hunter dengan username '%s' tidak ditemukan.\n", username);
}

void resetStatsHunter(SharedHunterData *data) {
    char username[USERNAME_LENGTH];
    printf("Masukkan username hunter yang ingin di-reset statnya: ");
    scanf("%s", username);

    for (int i = 0; i < MAX_HUNTERS; i++) {
        if (data->hunters[i].is_used && strcmp(data->hunters[i].username, username) == 0) {
            data->hunters[i].level = 1;
            data->hunters[i].exp = 0;
            data->hunters[i].atk = 50;
            data->hunters[i].hp = 100;
            data->hunters[i].def = 25;
            printf("Stats hunter '%s' telah direset ke nilai awal.\n", username);
            return;
        }
    }
    printf("Hunter dengan username '%s' tidak ditemukan.\n", username);
}

int main() {
    srand(time(NULL));

    // Buat shared memory untuk hunter
    int shmid_hunter = shmget(SHM_HUNTER_KEY, sizeof(SharedHunterData), IPC_CREAT | 0666);
    if (shmid_hunter == -1) {
        perror("shmget hunter");
        return 1;
    }

    SharedHunterData *hunter_data = (SharedHunterData *)shmat(shmid_hunter, NULL, 0);
    if ((void *)hunter_data == (void *)-1) {
        perror("shmat hunter");
        return 1;
    }

    // Buat shared memory untuk dungeon
    int shmid_dungeon = shmget(SHM_DUNGEON_KEY, sizeof(SharedDungeonData), IPC_CREAT | 0666);
    if (shmid_dungeon == -1) {
        perror("shmget dungeon");
        return 1;
    }

    SharedDungeonData *dungeon_data = (SharedDungeonData *)shmat(shmid_dungeon, NULL, 0);
    if ((void *)dungeon_data == (void *)-1) {
        perror("shmat dungeon");
        return 1;
    }

    // Inisialisasi sistem aktif
    hunter_data->system_active = true;

    int pilihan;
    do {
        printf("\n=== Sistem Sung Jin-Woo ===\n");
        printf("1. Tampilkan Semua Hunter\n");
        printf("2. Buat Dungeon Baru\n");
        printf("3. Tampilkan Semua Dungeon\n");
        printf("4. Ban Hunter\n");
        printf("5. Unban Hunter\n");
        printf("6. Reset Stats Hunter\n");
        printf("0. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tampilkanSemuaHunter(hunter_data);
                break;
            case 2:
                generateDungeon(dungeon_data);
                break;
            case 3:
                tampilkanSemuaDungeon(dungeon_data);
                break;
            case 4:
                banHunter(hunter_data);
                break;
            case 5:
                unbanHunter(hunter_data);
                break;
            case 6:
                resetStatsHunter(hunter_data);
                break;
            case 0:
                printf("Keluar dari sistem...\n");
                break;
            default:
                printf("Menu tidak valid.\n");
        }
    } while (pilihan != 0);

    // Cleanup: Hapus shared memory
    if (shmdt(hunter_data) == -1) {
        perror("shmdt hunter");
    }

    if (shmdt(dungeon_data) == -1) {
        perror("shmdt dungeon");
    }

    if (shmctl(shmid_hunter, IPC_RMID, NULL) == -1) {
        perror("shmctl hunter");
    }

    if (shmctl(shmid_dungeon, IPC_RMID, NULL) == -1) {
        perror("shmctl dungeon");
    }

    return 0;
}
