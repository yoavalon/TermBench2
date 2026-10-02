#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double altitude;
    double speed;
    double time;
} FlightTrajectory;

void FlightTrajectory_init(FlightTrajectory *self, double initial_altitude, double cruise_speed) {
    self->altitude = initial_altitude;
    self->speed = cruise_speed;
    self->time = 0.0;
}

void FlightTrajectory_update_altitude(FlightTrajectory *self, double rate_of_change) {
    self->altitude += rate_of_change;
    self->time += 1.0;
}

double FlightTrajectory_get_altitude(FlightTrajectory *self) {
    return self->altitude;
}

typedef struct {
    double target;
    double max_change;
} CruiseAltitudePlanner;

void CruiseAltitudePlanner_init(CruiseAltitudePlanner *self, double target_altitude, double max_rate_of_change) {
    self->target = target_altitude;
    self->max_change = max_rate_of_change;
}

double CruiseAltitudePlanner_calculate_adjustment(CruiseAltitudePlanner *self, double current_altitude) {
    double difference = self->target - current_altitude;
    double adjustment = fmin(fabs(difference), self->max_change);
    return difference > 0 ? adjustment : -adjustment;
}

typedef struct {
    FlightTrajectory *trajectory;
    CruiseAltitudePlanner *planner;
} FlightController;

void FlightController_init(FlightController *self, FlightTrajectory *trajectory, CruiseAltitudePlanner *planner) {
    self->trajectory = trajectory;
    self->planner = planner;
}

void FlightController_execute(FlightController *self) {
    while (1) {
        double current_altitude = FlightTrajectory_get_altitude(self->trajectory);
        double adjustment = CruiseAltitudePlanner_calculate_adjustment(self->planner, current_altitude);
        FlightTrajectory_update_altitude(self->trajectory, adjustment);
    }
}

int main() {
    FlightTrajectory trajectory;
    FlightTrajectory_init(&trajectory, 5000, 900);
    CruiseAltitudePlanner planner;
    CruiseAltitudePlanner_init(&planner, 35000, 1000);
    FlightController controller;
    FlightController_init(&controller, &trajectory, &planner);
    FlightController_execute(&controller);
    return 0;
}