#ifndef UNIT_H
#define UNIT_H

#define MAX_UNITS 100
#define MAX_UNIT_NAME 50
#define MAX_LINE_LENGTH 500

typedef enum {
   INFANTRY,
   ARCHER,
   CAVALRY,
   SIEGE
} UnitType;

typedef struct {
    char name[MAX_UNIT_NAME];
    UnitType type;
    int health;
    int attack;
    int melee_armor;
    int ranged_armor;
    int min_range;
    int max_range;
    int movement_speed;
    int reload_time;
} Unit;

extern Unit units[MAX_UNITS];
extern int unit_count;

#endif // UNIT_H