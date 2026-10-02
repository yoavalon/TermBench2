#include <stdio.h>

typedef struct {
    int altitude;
    int target;
    int climb_rate;
    int descent_rate;
} FlightTrajectory;

typedef struct {
    FlightTrajectory *flight;
    int cruise;
    int hold;
    int time_elapsed;
} CruiseAltitudePlanner;

void FlightTrajectory_init(FlightTrajectory *self, int initial_altitude, int target_altitude, int rate_of_climb, int rate_of_descent) {
    self->altitude = initial_altitude;
    self->target = target_altitude;
    self->climb_rate = rate_of_climb;
    self->descent_rate = rate_of_descent;
}

void FlightTrajectory_update_altitude(FlightTrajectory *self) {
    if (self->altitude < self->target) {
        self->altitude += self->climb_rate;
    } else if (self->altitude > self->target) {
        self->altitude -= self->descent_rate;
    }
}

void CruiseAltitudePlanner_init(CruiseAltitudePlanner *self, FlightTrajectory *flight, int cruise_altitude, int hold_time) {
    self->flight = flight;
    self->cruise = cruise_altitude;
    self->hold = hold_time;
    self->time_elapsed = 0;
}

void CruiseAltitudePlanner_plan_cruise(CruiseAltitudePlanner *self) {
    self->flight->altitude = self->cruise;
    while (self->time_elapsed < self->hold) {
        self->time_elapsed += 1;
    }
}

int main() {
    int initial = 1000;
    int target = 30000;
    int climb = 100;
    int descent = 50;
    int hold = 600;
    FlightTrajectory flight;
    CruiseAltitudePlanner planner;

    FlightTrajectory_init(&flight, initial, target, climb, descent);
    CruiseAltitudePlanner_init(&planner, &flight, target, hold);

    while (1) {
        FlightTrajectory_update_altitude(&flight);
        CruiseAltitudePlanner_plan_cruise(&planner);
    }

    return 0;
}