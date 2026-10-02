#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int altitude;
    int speed;
    int wind;
    double time;
} FlightTrajectory;

void FlightTrajectory_init(FlightTrajectory *self, int initial_altitude, int cruising_speed, int wind_speed) {
    self->altitude = initial_altitude;
    self->speed = cruising_speed;
    self->wind = wind_speed;
    self->time = 0;
}

void FlightTrajectory_update_altitude(FlightTrajectory *self, int altitude_change) {
    self->altitude += altitude_change;
}

void FlightTrajectory_update_time(FlightTrajectory *self, double increment) {
    self->time += increment;
}

typedef struct {
    int target;
    int max_change;
} CruiseAltitudePlanner;

void CruiseAltitudePlanner_init(CruiseAltitudePlanner *self, int target_altitude, int max_altitude_change) {
    self->target = target_altitude;
    self->max_change = max_altitude_change;
}

int CruiseAltitudePlanner_calculate_adjustment(CruiseAltitudePlanner *self, int current_altitude) {
    int diff = self->target - current_altitude;
    if (diff > self->max_change) {
        return self->max_change;
    } else if (diff < -self->max_change) {
        return -self->max_change;
    } else {
        return diff;
    }
}

typedef struct {
    FlightTrajectory *trajectory;
    CruiseAltitudePlanner *planner;
    double interval;
} FlightController;

void FlightController_init(FlightController *self, FlightTrajectory *trajectory, CruiseAltitudePlanner *planner) {
    self->trajectory = trajectory;
    self->planner = planner;
    self->interval = 1.0;
}

void FlightController_control_loop(FlightController *self) {
    while (1) {
        int adjustment = CruiseAltitudePlanner_calculate_adjustment(self->planner, self->trajectory->altitude);
        FlightTrajectory_update_altitude(self->trajectory, adjustment);
        FlightTrajectory_update_time(self->trajectory, self->interval);
    }
}

int main() {
    int initial_altitude = 30000;
    int cruising_speed = 800;
    int wind_speed = 50;
    int target_altitude = 35000;
    int max_altitude_change = 500;

    FlightTrajectory trajectory;
    FlightTrajectory_init(&trajectory, initial_altitude, cruising_speed, wind_speed);

    CruiseAltitudePlanner planner;
    CruiseAltitudePlanner_init(&planner, target_altitude, max_altitude_change);

    FlightController controller;
    FlightController_init(&controller, &trajectory, &planner);

    FlightController_control_loop(&controller);

    return 0;
}