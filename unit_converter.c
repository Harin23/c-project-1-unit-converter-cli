#include <stdio.h>

void length_converter ( double *p_meters, double *p_feet) {
    const double RATIO = 3.28084;

    if (*p_meters == 0.0) {
        *p_meters = *p_feet / RATIO;
        return;
    }

    if (*p_feet == 0.0) {
        *p_feet = *p_meters * RATIO;
    }
}

void mass_converter ( double *p_kg, double *p_lbs) {
    const double RATIO = 2.2046226218;

    if (*p_lbs == 0.0) {
        *p_lbs = *p_kg * RATIO;
        return;
    }

    if (*p_kg == 0.0) {
        *p_kg = *p_lbs / RATIO;
    }
}

void temperature_converter ( double *p_c, double *p_f) {
    if (*p_f == 0.0) {
        *p_f = *p_c * (9.0/5.0) + 32.0;
        return;
    }

    if (*p_c == 0.0) {
        *p_c = ((*p_f) - 32.0) * (5.0/9.0);
    }
}

void clearStdinBuffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {};
}


enum { MENU_LENGTH = 1, MENU_MASS, MENU_TEMP, MENU_QUIT };

int main () {
    int menu_option = 0;
    int from_unit =0;
    double a=0, b=0;

    const char *a_units[3] = { "m", "kg", "C" };
    const char *b_units[3] = { "ft", "lbs", "F" };

    while (menu_option != MENU_QUIT) {
        printf("Unit Converter\n1. Length (meters <-> feet)\n2. Mass (kg <-> pounds)\n3. Temperature (C <-> F)\n4. Quit\nChoice:");
        scanf("%d", &menu_option);

        if (menu_option == MENU_QUIT) return 0;
        if (menu_option != MENU_LENGTH && menu_option != MENU_MASS && menu_option != MENU_TEMP) {
            clearStdinBuffer(); //todo prob should clear buffer only if scanf fails
            printf("Invalid selection\n\n");
            menu_option=0;
            continue;
        };

        printf("Converting from unit A or B? Type 0 for A and 1 for B:");
        scanf("%d", &from_unit);

        if (from_unit == 0) {
            b=0;
        }else if (from_unit == 1) {
            a=0;
        }else {
            clearStdinBuffer(); //todo prob should clear buffer only if scanf fails
            printf("Invalid selection\n\n");
            from_unit=0;
            continue;
        }

        printf("Enter amount:");
        scanf("%lf", from_unit ? &b : &a);

        if (menu_option == MENU_LENGTH) length_converter(&a, &b);
        else if (menu_option == MENU_MASS) mass_converter(&a, &b);
        else if (menu_option == MENU_TEMP) temperature_converter(&a, &b);

        printf("Unit A: %lf [%s] and B: %lf [%s]\n\n", a, a_units[menu_option - 1], b, b_units[menu_option - 1] );
    }

    return 0;
}