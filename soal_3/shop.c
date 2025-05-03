#include "shop.h"
#include <string.h>
#include <stdio.h>

Weapon weapon_list[MAX_WEAPONS];

void init_shop() {
    strcpy(weapon_list[0].name, "Fists"); weapon_list[0].price = 0; weapon_list[0].damage = 5; weapon_list[0].has_passive = 0;
    strcpy(weapon_list[1].name, "Sword"); weapon_list[1].price = 50; weapon_list[1].damage = 15; weapon_list[1].has_passive = 0;
    strcpy(weapon_list[2].name, "Axe"); weapon_list[2].price = 80; weapon_list[2].damage = 20; weapon_list[2].has_passive = 1; strcpy(weapon_list[2].passive, "Extra 5 Gold per Kill");
    strcpy(weapon_list[3].name, "Dagger"); weapon_list[3].price = 30; weapon_list[3].damage = 10; weapon_list[3].has_passive = 1; strcpy(weapon_list[3].passive, "10%% Lifesteal");
    strcpy(weapon_list[4].name, "Hammer"); weapon_list[4].price = 100; weapon_list[4].damage = 25; weapon_list[4].has_passive = 0;
}

void get_shop_display(char* out) {
    strcpy(out, "Available Weapons:\n");
    for (int i = 0; i < MAX_WEAPONS; i++) {
        char line[200];
        sprintf(line, "%s - Price: %d, Damage: %d%s\n", weapon_list[i].name, weapon_list[i].price, weapon_list[i].damage,
                weapon_list[i].has_passive ? (char[100]) { sprintf((char[100]){}, ", Passive: %s", weapon_list[i].passive), (char[100]){} } : "");
        strcat(out, line);
    }
}

Weapon* buy_weapon(const char* name, int* gold) {
    for (int i = 0; i < MAX_WEAPONS; i++) {
        if (strcmp(weapon_list[i].name, name) == 0 && *gold >= weapon_list[i].price) {
            *gold -= weapon_list[i].price;
            return &weapon_list[i];
        }
    }
    return NULL;
}
