#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int altitude;
    int *trajectory;
    int trajectory_size;
} Flight;

typedef struct {
    void (*plan)(void*, Flight*);
    void (*cruise)(void*, Flight*);
} CruisePlanner;

void adjust_altitude(Flight *flight) {
    if (flight->altitude < 30000) {
        flight->altitude += 1000;
        flight->trajectory = realloc(flight->trajectory, (flight->trajectory_size + 1) * sizeof(int));
        flight->trajectory[flight->trajectory_size++] = flight->altitude;
        adjust_altitude(flight);
    } else if (flight->altitude < 40000) {
        flight->altitude += 500;
        flight->trajectory = realloc(flight->trajectory, (flight->trajectory_size + 1) * sizeof(int));
        flight->trajectory[flight->trajectory_size++] = flight->altitude;
        adjust_altitude(flight);
    } else {
        flight->altitude += 100;
        flight->trajectory = realloc(flight->trajectory, (flight->trajectory_size + 1) * sizeof(int));
        flight->trajectory[flight->trajectory_size++] = flight->altitude;
        adjust_altitude(flight);
    }
}

void plan(void *planner, Flight *flight) {
    if (flight->altitude < 35000) {
        adjust_altitude(flight);
        plan(planner, flight);
    } else {
        ((CruisePlanner*)planner)->cruise(planner, flight);
    }
}

void cruise(void *planner, Flight *flight) {
    flight->altitude += 50;
    flight->trajectory = realloc(flight->trajectory, (flight->trajectory_size + 1) * sizeof(int));
    flight->trajectory[flight->trajectory_size++] = flight->altitude;
    cruise(planner, flight);
}

int main() {
    Flight flight = {10000, (int*)malloc(sizeof(int)), 1};
    flight.trajectory[0] = 10000;

    CruisePlanner planner = {plan, cruise};
    planner.plan(&planner, &flight);

    free(flight.trajectory);
    return 0;
}