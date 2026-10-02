#include <stdio.h>

typedef struct {
    int altitude;
    int rate;
} FlightTrajectory;

void FlightTrajectory_init(FlightTrajectory* self, int initial_altitude, int rate_of_climb) {
    self->altitude = initial_altitude;
    self->rate = rate_of_climb;
}

void FlightTrajectory_update_altitude(FlightTrajectory* self) {
    self->altitude += self->rate;
}

int FlightTrajectory_get_altitude(FlightTrajectory* self) {
    return self->altitude;
}

typedef struct {
    int target;
    int step;
} CruiseAltitudePlanner;

void CruiseAltitudePlanner_init(CruiseAltitudePlanner* self, int target_altitude, int step_increase) {
    self->target = target_altitude;
    self->step = step_increase;
}

int CruiseAltitudePlanner_is_cruise_altitude_reached(CruiseAltitudePlanner* self, int current_altitude) {
    return current_altitude >= self->target;
}

int CruiseAltitudePlanner_adjust_altitude(CruiseAltitudePlanner* self, int current_altitude) {
    if (current_altitude < self->target) {
        return current_altitude + self->step;
    }
    return current_altitude;
}

typedef struct {
    FlightTrajectory* trajectory;
    CruiseAltitudePlanner* planner;
} FlightControlSystem;

void FlightControlSystem_init(FlightControlSystem* self, FlightTrajectory* trajectory, CruiseAltitudePlanner* planner) {
    self->trajectory = trajectory;
    self->planner = planner;
}

void FlightControlSystem_execute(FlightControlSystem* self) {
    while (1) {
        int current_altitude = FlightTrajectory_get_altitude(self->trajectory);
        if (CruiseAltitudePlanner_is_cruise_altitude_reached(self->planner, current_altitude)) {
            self->trajectory->altitude = CruiseAltitudePlanner_adjust_altitude(self->planner, current_altitude);
        }
        FlightTrajectory_update_altitude(self->trajectory);
    }
}

int main() {
    int initial_altitude = 5000;
    int rate_of_climb = 100;
    int target_altitude = 35000;
    int step_increase = 500;

    FlightTrajectory trajectory;
    FlightTrajectory_init(&trajectory, initial_altitude, rate_of_climb);

    CruiseAltitudePlanner planner;
    CruiseAltitudePlanner_init(&planner, target_altitude, step_increase);

    FlightControlSystem control_system;
    FlightControlSystem_init(&control_system, &trajectory, &planner);

    FlightControlSystem_execute(&control_system);

    return 0;
}