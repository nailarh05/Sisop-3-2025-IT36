#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_ORDER 100
#define MAX_NAME 64
#define MAX_ADDRESS 128

typedef struct {
    char name[MAX_NAME];
    char address[MAX_ADDRESS];
    char type[10];
    char status[64];
} Order;

Order *orders;
int *order_count;

void write_log(const char *agent, const char *name, const char *address) {
    FILE *log = fopen("delivery.log", "a");
    if (!log) return;

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    fprintf(log, "[%02d/%02d/%04d %02d:%02d:%02d] [%s] Express package delivered to %s in %s\n",
            t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,
            t->tm_hour, t->tm_min, t->tm_sec, agent, name, address);

    fclose(log);
}

void *agent_thread(void *arg) {
    char *agent_name = (char *) arg;

    while (1) {
        for (int i = 0; i < *order_count; ++i) {
            if (strcmp(orders[i].type, "Express") == 0 &&
                strcmp(orders[i].status, "Pending") == 0) {
                // tandai sebagai delivered
                snprintf(orders[i].status, sizeof(orders[i].status), "Agent %s", agent_name);
                write_log(agent_name, orders[i].name, orders[i].address);
                sleep(1);
            }
        }
        sleep(1);
    }

    return NULL;
}

int main() {
    key_t key = ftok("sharedfile", 65);
    int shmid = shmget(key, sizeof(Order) * MAX_ORDER + sizeof(int), 0666);
    orders = (Order *) shmat(shmid, NULL, 0);
    order_count = (int *)(orders + MAX_ORDER);

    pthread_t tid[3];
    char *agents[] = {"A", "B", "C"};

    for (int i = 0; i < 3; ++i)
        pthread_create(&tid[i], NULL, agent_thread, agents[i]);

    for (int i = 0; i < 3; ++i)
        pthread_join(tid[i], NULL);

    shmdt(orders);
    return 0;
}
