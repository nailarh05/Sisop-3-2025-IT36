
// hunter.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdbool.h>
#include <pthread.h>

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
    bool notification_enabled;
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

typedef struct {
    SharedDungeonData *dungeon_data;
    bool *notification_enabled;
    bool *running;
} NotificationArgs;

void *notificationThread(void *arg) {
    NotificationArgs *args = (NotificationArgs *)arg;
    while (*(args->running)) {
        if (*(args->notification_enabled)) {
            system("clear");
            printf("\n=== Notifikasi Dungeon (Setiap 3 Detik) ===\n");
            for (int i = 0; i < MAX_DUNGEONS; i++) {
                Dungeon *d = &args->dungeon_data->dungeons[i];
                if (d->is_used) {
                    printf("[%d] %s | Level Min: %d | EXP: %d | ATK: %d | HP: %d | DEF: %d\n",
                        i + 1, d->name, d->level_min, d->reward_exp,
                        d->reward_atk, d->reward_hp, d->reward_def);
                }
            }
        }
        sleep(3);
    }
    return NULL;
}

void listDungeon(SharedDungeonData *dungeon_data) {
    printf("\n=== Daftar Dungeon ===\n");
    for (int i = 0; i < MAX_DUNGEONS; i++) {
        if (dungeon_data->dungeons[i].is_used) {
            printf("[%d] %s | Level Min: %d | EXP: %d | ATK: %d | HP: %d | DEF: %d\n",
                   i + 1, dungeon_data->dungeons[i].name,
                   dungeon_data->dungeons[i].level_min,
                   dungeon_data->dungeons[i].reward_exp,
                   dungeon_data->dungeons[i].reward_atk,
                   dungeon_data->dungeons[i].reward_hp,
                   dungeon_data->dungeons[i].reward_def);
        }
    }
}


void raid(Hunter *user, SharedDungeonData *dungeon_data) {
    if (user->is_banned) {
        printf("Akun Anda dibanned. Anda tidak dapat melakukan raid.\n");
        return;
    }

    int pilihan;
    listDungeon(dungeon_data);
    printf("\nPilih nomor dungeon untuk di-raid: ");
    scanf("%d", &pilihan);
    int idx = pilihan - 1;

    if (idx < 0 || idx >= MAX_DUNGEONS || !dungeon_data->dungeons[idx].is_used) {
        printf("Dungeon tidak tersedia.\n");
        return;
    }

    Dungeon *d = &dungeon_data->dungeons[idx];
    if (user->level < d->level_min) {
        printf("Level Anda belum cukup untuk dungeon ini.\n");
        return;
    }

    printf("\nRaid berhasil! Anda mendapatkan hadiah dari dungeon.\n");
    user->exp += d->reward_exp;
    user->atk += d->reward_atk;
    user->hp += d->reward_hp;
    user->def += d->reward_def;

    if (user->exp >= 500) {
        user->level++;
        user->exp = 0;
        printf("Level up! Level Anda sekarang %d.\n", user->level);
    }

    d->is_used = false; // Dungeon dihapus
}


void battle(Hunter *user, SharedHunterData *hunter_data) {
    if (user->is_banned) {
        printf("Akun Anda dibanned. Anda tidak dapat bertarung.\n");
        return;
    }

    printf("\n=== Daftar Hunter Aktif ===\n");
    int count = 0;
    for (int i = 0; i < MAX_HUNTERS; i++) {
        if (&hunter_data->hunters[i] != user && hunter_data->hunters[i].is_used && !hunter_data->hunters[i].is_banned) {
            printf("[%d] %s\n", i, hunter_data->hunters[i].username);
            count++;
        }
    }
    if (count == 0) {
        printf("Tidak ada hunter lain yang tersedia.\n");
        return;
    }

    int target_idx;
    printf("Pilih nomor hunter yang ingin dilawan: ");
    scanf("%d", &target_idx);

    if (target_idx < 0 || target_idx >= MAX_HUNTERS || !hunter_data->hunters[target_idx].is_used) {
        printf("Target tidak valid.\n");
        return;
    }

    Hunter *opponent = &hunter_data->hunters[target_idx];

    int user_power = user->atk + user->hp + user->def;
    int opponent_power = opponent->atk + opponent->hp + opponent->def;

    if (user_power >= opponent_power) {
        printf("Anda menang melawan %s!\n", opponent->username);
        user->atk += opponent->atk;
        user->hp += opponent->hp;
        user->def += opponent->def;
        opponent->is_used = false;
    } else {
        printf("Anda kalah dari %s. Anda akan dihapus dari sistem.\n", opponent->username);
        opponent->atk += user->atk;
        opponent->hp += user->hp;
        opponent->def += user->def;
        user->is_used = false;
    }
}



void menuHunter(Hunter *user, SharedHunterData *hunter_data, SharedDungeonData *dungeon_data) {
    int choice;
    bool running = true;
    pthread_t notif_thread;
    // NotificationArgs args = { dungeon_data, &user->notification_enabled, &running };
    // pthread_create(&notif_thread, NULL, notificationThread, &args);

    do {
        printf("\n=== Hunter System ===\n");
        printf("Halo, %s\n", user->username);
        printf("Level: %d | EXP: %d | ATK: %d | HP: %d | DEF: %d\n",
               user->level, user->exp, user->atk, user->hp, user->def);
        printf("1. List Dungeon\n");
        printf("2. Raid\n");
        printf("3. Battle\n");
        printf("4. Toggle Notification (%s)\n", user->notification_enabled ? "ON" : "OFF");
        printf("5. Exit\n");
        printf("Pilih: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                listDungeon(dungeon_data);
                break;
            case 2:
                raid(user, dungeon_data);
                break;
            case 3:
                battle(user, hunter_data);
                break;
            case 4:
                user->notification_enabled = !user->notification_enabled;
                printf("Notifikasi sekarang: %s\n", user->notification_enabled ? "ON" : "OFF");
                break;
            case 5:
                running = false;
                // pthread_join(notif_thread, NULL);
                printf("Keluar dari sistem hunter...\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (choice != 5);
}

void registerHunter(SharedHunterData *data) {
    char username[USERNAME_LENGTH], password[PASSWORD_LENGTH];
    printf("=== Registrasi Hunter ===\n");
    printf("Username: "); scanf("%s", username);
    printf("Password: "); scanf("%s", password);

    for (int i = 0; i < MAX_HUNTERS; i++) {
        if (data->hunters[i].is_used && strcmp(data->hunters[i].username, username) == 0) {
            printf("Username sudah digunakan!\n");
            return;
        }
    }

    for (int i = 0; i < MAX_HUNTERS; i++) {
        if (!data->hunters[i].is_used) {
            strcpy(data->hunters[i].username, username);
            strcpy(data->hunters[i].password, password);
            data->hunters[i].level = 1;
            data->hunters[i].exp = 0;
            data->hunters[i].atk = 10;
            data->hunters[i].hp = 100;
            data->hunters[i].def = 5;
            data->hunters[i].is_banned = false;
            data->hunters[i].is_used = true;
            data->hunters[i].notification_enabled = true;
            printf("Registrasi berhasil!\n");
            return;
        }
    }
    printf("Hunter penuh! Registrasi gagal.\n");
}

void loginHunter(SharedHunterData *hunter_data, SharedDungeonData *dungeon_data) {
    char username[USERNAME_LENGTH], password[PASSWORD_LENGTH];
    printf("=== Login Hunter ===\n");
    printf("Username: "); scanf("%s", username);
    printf("Password: "); scanf("%s", password);

    for (int i = 0; i < MAX_HUNTERS; i++) {
        if (hunter_data->hunters[i].is_used && strcmp(hunter_data->hunters[i].username, username) == 0) {
            if (strcmp(hunter_data->hunters[i].password, password) == 0) {
                if (hunter_data->hunters[i].is_banned) {
                    printf("Akun Anda telah dibanned.\n");
                    return;
                }
                printf("Login berhasil! Selamat datang, %s\n", username);
                menuHunter(&hunter_data->hunters[i], hunter_data, dungeon_data);
                return;
            } else {
                printf("Password salah!\n");
                return;
            }
        }
    }
    printf("Hunter tidak ditemukan!\n");
}

int main() {
    int shmid_hunter = shmget(SHM_HUNTER_KEY, sizeof(SharedHunterData), 0666);
    if (shmid_hunter == -1) {
        printf("Sistem belum aktif. Jalankan system.c terlebih dahulu.\n");
        return 1;
    }

    SharedHunterData *hunter_data = (SharedHunterData *)shmat(shmid_hunter, NULL, 0);
    if (hunter_data == (void *)-1) {
        perror("shmat hunter");
        return 1;
    }

    if (!hunter_data->system_active) {
        printf("Sistem belum aktif sepenuhnya.\n");
        return 1;
    }

    int shmid_dungeon = shmget(SHM_DUNGEON_KEY, sizeof(SharedDungeonData), 0666);
    if (shmid_dungeon == -1) {
        printf("Gagal mengakses data dungeon.\n");
        return 1;
    }

    SharedDungeonData *dungeon_data = (SharedDungeonData *)shmat(shmid_dungeon, NULL, 0);
    if (dungeon_data == (void *)-1) {
        perror("shmat dungeon");
        return 1;
    }

    int choice;
    do {
        printf("\n=== Menu Hunter ===\n");
        printf("1. Registrasi\n");
        printf("2. Login\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerHunter(hunter_data);
                break;
            case 2:
                loginHunter(hunter_data, dungeon_data);
                break;
            case 0:
                printf("Keluar dari hunter...\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (choice != 0);

    shmdt(hunter_data);
    shmdt(dungeon_data);
    return 0;
}
