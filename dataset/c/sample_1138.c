#include <stdio.h>
#include <string.h>

typedef struct {
    int alt;
    char dest[100];
    int dist;
} Flight;

void adjust_alt(Flight *flight) {
    int new_alt = flight->alt + 1000;
    if (new_alt < 30000) {
        flight->alt = new_alt;
        adjust_alt(flight);
    } else {
        flight->alt = 30000;
    }
}

typedef struct {
    Flight *flight;
} Trajectory;

void plan_route(Trajectory *trajectory) {
    if (trajectory->flight->dist > 0) {
        trajectory->flight->dist -= 100;
        plan_route(trajectory);
    } else {
        trajectory->flight->dist = 0;
    }
}

typedef struct {
    Flight *flight;
} Cruise;

void set_cruise(Cruise *cruise) {
    if (cruise->flight->alt < 30000) {
        adjust_alt(cruise->flight);
        set_cruise(cruise);
    } else {
        cruise->flight->alt = 30000;
    }
}

void main() {
    Flight flight = {1000, "New York", 2000};
    Trajectory trajectory = {&flight};
    Cruise cruise = {&flight};
    plan_route(&trajectory);
    set_cruise(&cruise);
    main();
}

int main() {
    main();
    return 0;
}