#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unit.h"
#include "misc.h"

// Function to load units from CSV file
void load_units_from_csv(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open %s\n", filename);
        printf("Creating default units file...\n");
        
        // Create default units file
        FILE* new_file = fopen(filename, "w");
        if (new_file != NULL) {
            fprintf(new_file, "name,class,health,attack,melee_armor,ranged_armor,min_range,max_range,movement_speed,reload_time\n");
            fprintf(new_file, "Militia,infantry,40,4,1,0,0,1,0.95,1.5\n");
            fprintf(new_file, "Archer,archer,30,7,0,2,3,10,0.95,1.5\n");
            fprintf(new_file, "Knight,cavalry,150,15,2,1,0,1,1.2,1.5\n");
            fprintf(new_file, "Trebuchet,siege,250,60,1,1,5,15,0.7,3.0\n");
            fclose(new_file);
            printf("Default units file created.\n");
        }
        return;
    }
    
    char line[MAX_LINE_LENGTH];
    // Skip header line
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return;
    }
    
    int unit_count = 0;
    Unit units[20];
    while (fgets(line, sizeof(line), file) != NULL && unit_count < MAX_UNITS) {
        // Parse CSV line
        char* token;
        
        token = strtok(line, ",");
        if (token == NULL) continue;
        strncpy(units[unit_count].name, token, MAX_UNIT_NAME - 1);
        units[unit_count].name[MAX_UNIT_NAME - 1] = '\0';
        
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        // strncpy(units[unit_count].type, token, MAX_CLASS_NAME - 1);
        // units[unit_count].type[MAX_CLASS_NAME - 1] = '\0';
        
        token = strtok(NULL, ",");
        if (token != NULL) units[unit_count].health = atoi(token);
        
        token = strtok(NULL, ",");
        if (token != NULL) units[unit_count].attack = atoi(token);
        
        token = strtok(NULL, ",");
        if (token != NULL) units[unit_count].melee_armor = atoi(token);
        
        token = strtok(NULL, ",");
        if (token != NULL) units[unit_count].ranged_armor = atoi(token);
        
        token = strtok(NULL, ",");
        if (token != NULL) units[unit_count].min_range = atoi(token);
        
        token = strtok(NULL, ",");
        if (token != NULL) units[unit_count].max_range = atoi(token);
        
        token = strtok(NULL, ",");
        if (token != NULL) units[unit_count].movement_speed = atof(token);
        
        token = strtok(NULL, ",");
        if (token != NULL) units[unit_count].reload_time = atof(token);
        
        unit_count++;
    }
    
    fclose(file);
    printf("Loaded %d units from %s\n", unit_count, filename);
}

// Function to save a unit to CSV file
void save_unit_to_csv(const char* filename, Unit* unit) {
    FILE* file = fopen(filename, "a");
    if (file != NULL) {
        fprintf(file, "%s,%s,%d,%d,%d,%d,%d,%d,%f,%f\n",
                unit->name, unit_type_str(unit->type), unit->health, unit->attack,
                unit->melee_armor, unit->ranged_armor, unit->min_range,
                unit->max_range, unit->movement_speed, unit->reload_time);
        fclose(file);
    }
}