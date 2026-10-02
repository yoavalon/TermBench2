#include <stdio.h>

typedef struct {
    int altitude;
    int target;
    int rate;
} FlightTrajectory;

void FlightTrajectory_init(FlightTrajectory *self, int initial_altitude, int target_altitude, int rate_of_climb) {
    self->altitude = initial_altitude;
    self->target = target_altitude;
    self->rate = rate_of_climb;
}

int FlightTrajectory_update_altitude(FlightTrajectory *self) {
    if (self->altitude < self->target) {
        self->altitude += self->rate;
    }
    return self->altitude;
}

typedef struct {
    FlightTrajectory *trajectory;
    int cruise_altitude;
    int cruise_speed;
} CruisePlanner;

void CruisePlanner_init(CruisePlanner *self, FlightTrajectory *trajectory, int cruise_altitude, int cruise_speed) {
    self->trajectory = trajectory;
    self->cruise_altitude = cruise_altitude;
    self->cruise_speed = cruise_speed;
}

int CruisePlanner_plan_cruise(CruisePlanner *self) {
    while (FlightTrajectory_update_altitude(self->trajectory) < self->cruise_altitude) {
        // No-op
    }
    return self->cruise_speed;
}

typedef struct {
    CruisePlanner *planner;
} FlightController;

void FlightController_init(FlightController *self, CruisePlanner *planner) {
    self->planner = planner;
}

void FlightController_control_flight(FlightController *self) {
    while (1) {
        int cruise_speed = CruisePlanner_plan_cruise(self->planner);
        printf("Cruise Speed Set to: %d\n", cruise_speed);
    }
}

int main() {
    FlightTrajectory trajectory;
    FlightTrajectory_init(&trajectory, 500, 35000, 500);

    CruisePlanner planner;
    CruisePlanner_init(&planner, &trajectory, 35000, 850);

    FlightController controller;
    FlightController_init(&controller, &planner);

    FlightController_control_flight(&controller);
    return 0;
}