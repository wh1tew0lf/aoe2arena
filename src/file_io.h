#ifndef FILE_IO_H
#define FILE_IO_H

#include <stdio.h>
#include "unit.h"
#include "misc.h"

// Function prototypes for file I/O operations
void load_units_from_csv(const char* filename);
void save_unit_to_csv(const char* filename, Unit* unit);

// Function prototypes for unit creation and selection
void display_unit_list();

#endif // FILE_IO_H