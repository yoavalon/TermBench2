#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int altitude;
    int target;
    int step;
} FlightTrajectory;

int adjust_altitude(FlightTrajectory *self) {
    if (self->altitude < self->target) {
        self->altitude += self->step;
    } else {
        self->altitude -= self->step;
    }
    return self->altitude;
}

typedef struct {
    FlightTrajectory *trajectory;
} CruiseAltitudePlanner;

void plan_altitude(CruiseAltitudePlanner *self) {
    while (1) {
        int new_altitude = adjust_altitude(self->trajectory);
        if (abs(new_altitude - self->trajectory->target) < self->trajectory->step) {
            break;
        }
    }
}

typedef struct {
    CruiseAltitudePlanner *planner;
} Simulation;

void run(Simulation *self) {
    while (1) {
        plan_altitude(self->planner);
    }
}

int main() {
    int initial = 10000;
    int target = 30000;
    int step = 1000;
    FlightTrajectory trajectory = {initial, target, step};
    CruiseAltitudePlanner planner = {&trajectory};
    Simulation simulation = {&planner};
    run(&simulation);
    return 0;
}