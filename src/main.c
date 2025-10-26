#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "unit.h"
#include "misc.h"
#include "battle.h"

int main() {
    printf("=== Age of Empires 2 Unit Battle Simulator ===\n\n");

    printf("%s\n", unit_type_str(INFANTRY));

    int play_again = 1;
    while (play_again) {
        // может сделать цикл - введите юнита и цвет
            // выберите первого юнита
        Unit unit1 = {
            .name = "Крестьянин",
            .type = INFANTRY,
            .health = 25,
            .attack = 3,
            .melee_armor = 0,
            .ranged_armor = 0,
            .min_range = 0,
            .max_range = 1,
            .movement_speed = 0.8f,
            .reload_time = 3.0f
        };
            
            // выберите второго юнита
        Unit unit2 = {
            .name = "Разведчик",
            .type = INFANTRY,
            .health = 50,
            .attack = 3,
            .melee_armor = 0,
            .ranged_armor = 0,
            .min_range = 0,
            .max_range = 1,
            .movement_speed = 0.8f,
            .reload_time = 2.33f
        };
        // расчёт битвы
        battle(unit1, unit2);

        play_again = ask_y_or_n("Ещё раз? y/n: ");
    }
    return 0;
}