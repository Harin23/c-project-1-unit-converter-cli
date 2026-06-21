# Project 1: Unit Converter CLI

**Module:** 1.1 — First C Program, Variables, and Types  
**Estimated time:** 3–4 hours

## Description

Build a menu-driven command-line unit converter that supports length, mass, and temperature conversions.

## Requirements

### Functional

1. Display a main menu on each iteration:
   ```
   Unit Converter
   1. Length (meters <-> feet)
   2. Mass (kg <-> pounds)
   3. Temperature (C <-> F)
   4. Quit
   Choice:
   ```
2. For each conversion type, ask whether the user is converting from unit A to B or B to A.
3. Read a numeric value and print the converted result with two decimal places.
4. Loop until the user chooses Quit.

### Conversion Formulas

| Type | Formulas |
|------|----------|
| Length | `feet = meters * 3.28084`; inverse for meters |
| Mass | `pounds = kg * 2.20462`; inverse for kg |
| Temperature | `F = C * 9.0 / 5.0 + 32.0`; `C = (F - 32.0) * 5.0 / 9.0` |

### Error Handling

- Invalid menu choice: print error message, re-display menu
- Non-numeric input: print error message, re-prompt (do not crash)

## Technical Requirements

- Single file: `unit_converter.c`
- Compile: `gcc -Wall -Wextra -std=c11 -o unit_converter unit_converter.c`
- Use `double` for all conversion values

## Rubric

| Criterion | Points |
|-----------|--------|
| All three conversion types work correctly | 30 |
| Bidirectional conversion (both directions) | 20 |
| Menu loops until quit | 15 |
| Invalid input handled gracefully | 20 |
| Compiles with zero warnings | 15 |
| **Total** | **100** |

## Test Cases

1. Convert 100 meters → feet → back to meters (should recover ~100)
2. Enter `abc` at numeric prompt — program should not crash
3. Enter menu option 9 — error message, menu redisplays
4. Quit with option 4 — program exits with code 0

## Extension (Optional)

Add kilometers ↔ miles as a fourth menu option.
