# Age of Empires 2 Unit Battle Simulator

A console-based battle simulator for Age of Empires 2 units written in C.

## Features

- **Unit Management**: 
  - Predefined units (Militia, Archer, Knight, Trebuchet)
  - Custom unit creation
  - All 10 characteristics: health, class, attack, armor, range, speed, reload time

- **Battle System**:
  - Turn-based combat
  - Realistic damage calculation based on armor
  - Detailed battle logging
  - Win/loss determination

## Building

To build the project, simply run:

```bash
make
```

To run the application:

```bash
make run
```

## Usage

1. Run the program: `./aoe2arena`
2. Select the first unit:
   - Choose from predefined library or create a new unit
3. Select the second unit:
   - Choose from predefined library or create a new unit
4. Watch the battle unfold in the console
5. See battle results and choose to fight again

## File Structure

- `src/main.c` - Main application logic
- `data/units.csv` - Unit database (predefined units)
- `Makefile` - Build configuration

## Unit Characteristics

Each unit has the following characteristics:
1. **Health** - Total hit points
2. **Class** - Type: infantry, archer, cavalry, or siege
3. **Attack** - Base damage value
4. **Melee Armor** - Protection against melee attacks
5. **Ranged Armor** - Protection against ranged attacks
6. **Minimum Range** - Minimum distance for ranged attacks
7. **Maximum Range** - Maximum distance for ranged attacks
8. **Movement Speed** - Unit movement speed (not used in current implementation)
9. **Reload Time** - Time between attacks (not used in current implementation)
10. **Name** - Unit identifier

## Adding New Units

To add new units, you can:
1. Create a new unit through the interface
2. Manually edit `data/units.csv` with comma-separated values following the format:
   ```
   name,class,health,attack,melee_armor,ranged_armor,min_range,max_range,movement_speed,reload_time
   ```

## Requirements

- C compiler (GCC recommended)
- Make build system

## License

## Testing

The project includes a CUnit test suite.

- Build and run the tests:

```bash
make test
```

- The test binary `run_tests` will be compiled and executed automatically.
- Test results are displayed in the console.

The test suite covers loading units, unit selection, and battle simulation.
This project is created for educational purposes.