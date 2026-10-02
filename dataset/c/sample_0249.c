#include <stdio.h>

typedef struct {
    int altitude;
    int max_altitude;
    int speed;
} FlightTrajectory;

void update_altitude(FlightTrajectory *self, int time) {
    self->altitude += self->speed * time;
    if (self->altitude > self->max_altitude) {
        self->altitude = self->max_altitude;
    }
}

typedef struct {
    FlightTrajectory *trajectory;
    int target_altitude;
} CruiseAltitudePlanner;

void adjust_altitude(CruiseAltitudePlanner *self, int current_time) {
    if (self->trajectory->altitude < self->target_altitude) {
        int time_to_adjust = (self->target_altitude - self->trajectory->altitude) / self->trajectory->speed;
        if (current_time >= time_to_adjust) {
            update_altitude(self->trajectory, time_to_adjust);
        }
    }
}

typedef struct {
    FlightTrajectory *trajectory;
    int target_altitude;
} TerminationChecker;

int check(TerminationChecker *self) {
    return self->trajectory->altitude >= self->target_altitude;
}

void main() {
    int initial_altitude = 1000;
    int max_altitude = 30000;
    int speed = 1500;
    FlightTrajectory trajectory = {initial_altitude, max_altitude, speed};
    CruiseAltitudePlanner planner = {&trajectory, max_altitude};
    TerminationChecker checker = {&trajectory, max_altitude};
    int current_time = 0;
    int time_step = 10;
    while (!check(&checker)) {
        adjust_altitude(&planner, current_time);
        current_time += time_step;
    }
    printf('Cruise altitude reached.\n');
}