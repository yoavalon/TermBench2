#include <stdio.h>

typedef struct {
    int altitude;
    int max_altitude;
    int speed;
    int climbing;
} FlightTrajectory;

void FlightTrajectory_init(FlightTrajectory *self, int initial_altitude, int max_altitude, int speed) {
    self->altitude = initial_altitude;
    self->max_altitude = max_altitude;
    self->speed = speed;
    self->climbing = 1;
}

void FlightTrajectory_adjust_altitude(FlightTrajectory *self) {
    if (self->climbing) {
        self->altitude += self->speed;
        if (self->altitude >= self->max_altitude) {
            self->climbing = 0;
        }
    } else {
        self->altitude -= self->speed;
        if (self->altitude <= 0) {
            self->climbing = 1;
        }
    }
}

void FlightTrajectory_simulate_flight(FlightTrajectory *self) {
    while (1) {
        FlightTrajectory_adjust_altitude(self);
    }
}

typedef struct {
    FlightTrajectory *trajectory;
} CruiseAltitudePlanner;

void CruiseAltitudePlanner_init(CruiseAltitudePlanner *self, FlightTrajectory *trajectory) {
    self->trajectory = trajectory;
}

void CruiseAltitudePlanner_plan_cruise(CruiseAltitudePlanner *self) {
    while (1) {
        if (self->trajectory->climbing) {
            printf("Climbing to %d meters\n", self->trajectory->altitude);
        } else {
            printf("Descending to %d meters\n", self->trajectory->altitude);
        }
    }
}

void main() {
    FlightTrajectory trajectory;
    CruiseAltitudePlanner planner;

    FlightTrajectory_init(&trajectory, 1000, 10000, 100);
    CruiseAltitudePlanner_init(&planner, &trajectory);
    CruiseAltitudePlanner_plan_cruise(&planner);
}