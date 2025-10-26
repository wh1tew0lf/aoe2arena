#include "battle.h"
#include <stdio.h>

float MAX_BATTLE_TIME = 100.0f;

void battle(Unit unit1, Unit unit2) {
    printf("Battle between %s and %s\n", unit1.name, unit2.name);
    float timeQuant = 0.01f; // May be we can found max common divider
    float unit1LastAttackTime = 0.0f;
    float unit2LastAttackTime = 0.0f;
    int unit1damage = unit1.attack > unit2.melee_armor ? unit1.attack - unit2.melee_armor : 1;
    int unit2damage = unit2.attack > unit1.melee_armor ? unit2.attack - unit1.melee_armor : 1;
    for(float battleTime = 0.0f; battleTime < MAX_BATTLE_TIME && unit1.health > 0 && unit2.health; battleTime += timeQuant) {
        if (unit1LastAttackTime <= battleTime) {
            unit2.health -= unit1damage;
            unit1LastAttackTime = battleTime + unit1.reload_time;
            printf("Time %f: Unit1 %s attack with %i. Unit2 %s has %i health\n", battleTime, unit1.name, unit1damage, unit2.name, unit2.health);
        }

        if (unit2LastAttackTime <= battleTime) {
            unit1.health -= unit2damage;
            unit2LastAttackTime = battleTime + unit2.reload_time;
            printf("Time %f: Unit2 %s attack with %i. Unit1 %s has %i health\n", battleTime, unit2.name, unit2damage, unit1.name, unit1.health);
        }
    }

    if (unit1.health > 0 && unit2.health <= 0) {
        printf("Unit1 %s win!\n", unit1.name);
    }

    if (unit2.health > 0 && unit1.health <= 0) {
        printf("Unit2 %s win!\n", unit2.name);
    }

    if (unit1.health <= 0 && unit2.health <= 0) {
        printf("There is no winner, both died\n");
    }

    if (unit1.health > 0 && unit2.health > 0) {
        printf("There is no winner, both are alive and it is strange\n");
    }
}