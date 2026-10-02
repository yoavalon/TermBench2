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
    int cruise;
} CruiseAltitudePlanner;

void CruiseAltitudePlanner_init(CruiseAltitudePlanner *self, FlightTrajectory *trajectory, int cruise_altitude) {
    self->trajectory = trajectory;
    self->cruise = cruise_altitude;
}

int CruiseAltitudePlanner_plan_cruise(CruiseAltitudePlanner *self) {
    while (self->trajectory->altitude < self->cruise) {
        FlightTrajectory_update_altitude(self->trajectory);
    }
    return self->cruise;
}

typedef struct {
    CruiseAltitudePlanner *planner;
} FlightControl;

void FlightControl_init(FlightControl *self, CruiseAltitudePlanner *planner) {
    self->planner = planner;
}

void FlightControl_execute_flight(FlightControl *self) {
    while (1) {
        int cruise_altitude = CruiseAltitudePlanner_plan_cruise(self->planner);
        printf("Cruise altitude reached: %d meters\n", cruise_altitude);
    }
}

int main() {
    int initial_altitude = 1000;
    int target_altitude = 8000;
    int rate_of_climb = 150;
    int cruise_altitude = 10000;
    FlightTrajectory trajectory;
    FlightTrajectory_init(&trajectory, initial_altitude, target_altitude, rate_of_climb);
    CruiseAltitudePlanner planner;
    CruiseAltitudePlanner_init(&planner, &trajectory, cruise_altitude);
    FlightControl flight_control;
    FlightControl_init(&flight_control, &planner);
    FlightControl_execute_flight(&flight_control);
    return 0;
}