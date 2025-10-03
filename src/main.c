#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "unit.h"
#include "misc.h"

int main() {
    printf("=== Age of Empires 2 Unit Battle Simulator ===\n\n");

    printf("%s\n", unit_type_str(INFANTRY));

    int play_again = 1;
    while (play_again) {
        // может сделать цикл - введите юнита и цвет
            // выберите первого юнита
            // выберите второго юнита
        // расчёт битвы

        play_again = ask_y_or_n("Ещё раз? y/n: ");
    }
    return 0;
}