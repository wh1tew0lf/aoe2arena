#include <stdio.h>
#include "unit.h"

int ask_y_or_n(char* question) {
    printf("%s\n", question);
    while (1) {
        int char_count = 0;
        char ch;
        char temp;
        // читаем до перевода строки
        while ((temp = getchar()) != '\n') {
            ++char_count;
            if (char_count > 1) {
                continue;
            }
            // сохраняем предыдущий символ
            if (temp != '\n') {
                ch = temp;
            }
        }
        
        if (char_count == 1 && (ch == 'y' || ch == 'Y')) {
            return 1;
        }
        if (char_count == 1 && (ch == 'n' || ch == 'N')) {
            return 0;
        }
        printf("Некорректный ответ\n%s\n", question);
    }
    return 0;
}

char* unit_type_str(UnitType type) {
    switch (type)
    {
    case INFANTRY: return "Infantry";
    case ARCHER: return "ARCHER";
    case CAVALRY: return "CAVALRY";
    case SIEGE: return "SIEGE";
    
    default:
        return "";
    }
}

// Function to display the list of available units
void display_unit_list(Unit *units, int unit_count) {
    printf("\nAvailable Units:\n");
    printf("----------------\n");
    for (int i = 0; i < unit_count; i++) {
        printf("%d. %s (%s)\n", i + 1, units[i].name, unit_type_str(units[i].type));
    }
    printf("\n");
}