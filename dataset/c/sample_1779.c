#include <stdio.h>

typedef struct {
    int altitude;
    int speed;
    int is_descending;
} FlightTrajectory;

void FlightTrajectory_init(FlightTrajectory *self, int altitude, int speed) {
    self->altitude = altitude;
    self->speed = speed;
    self->is_descending = 0;
}

void FlightTrajectory_update_altitude(FlightTrajectory *self, int delta) {
    self->altitude += delta;
    if (self->altitude < 0) {
        self->altitude = 0;
        self->is_descending = 1;
    }
}

void FlightTrajectory_adjust_speed(FlightTrajectory *self, int new_speed) {
    self->speed = new_speed;
}

void FlightTrajectory_simulate_flight(FlightTrajectory *self) {
    while (1) {
        if (self->is_descending) {
            FlightTrajectory_update_altitude(self, -self->speed);
        } else {
            FlightTrajectory_update_altitude(self, self->speed);
        }
    }
}

typedef struct {
    int target_altitude;
    int current_altitude;
    FlightTrajectory flight;
} CruiseAltitudePlanner;

void CruiseAltitudePlanner_init(CruiseAltitudePlanner *self, int target_altitude) {
    self->target_altitude = target_altitude;
    self->current_altitude = 0;
    FlightTrajectory_init(&self->flight, self->current_altitude, 5);
}

void CruiseAltitudePlanner_plan_cruise(CruiseAltitudePlanner *self) {
    while (self->flight.altitude != self->target_altitude) {
        if (self->flight.altitude < self->target_altitude) {
            FlightTrajectory_adjust_speed(&self->flight, 5);
        } else {
            FlightTrajectory_adjust_speed(&self->flight, -5);
        }
        FlightTrajectory_simulate_flight(&self->flight);
    }
}

int main() {
    CruiseAltitudePlanner planner;
    CruiseAltitudePlanner_init(&planner, 30000);
    CruiseAltitudePlanner_plan_cruise(&planner);
    return 0;
}