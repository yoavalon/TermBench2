#include <stdio.h>

typedef struct {
    double a;
    double t;
    double r;
    double d;
    double current_altitude;
    int is_ascent;
} FlightTrajectory;

void FlightTrajectory_init(FlightTrajectory *self, double initial_altitude, double target_altitude, double rate_of_climb, double descent_rate) {
    self->a = initial_altitude;
    self->t = target_altitude;
    self->r = rate_of_climb;
    self->d = descent_rate;
    self->current_altitude = initial_altitude;
    self->is_ascent = 1;
}

void FlightTrajectory_adjust_altitude(FlightTrajectory *self) {
    if (self->is_ascent) {
        if (self->current_altitude < self->t) {
            self->current_altitude += self->r;
        } else {
            self->is_ascent = 0;
        }
    } else {
        if (self->current_altitude > self->t) {
            self->current_altitude -= self->d;
        }
    }
}

double FlightTrajectory_get_current_altitude(FlightTrajectory *self) {
    return self->current_altitude;
}

typedef struct {
    FlightTrajectory *trajectory;
} CruiseAltitudePlanner;

void CruiseAltitudePlanner_init(CruiseAltitudePlanner *self, FlightTrajectory *trajectory) {
    self->trajectory = trajectory;
}

void CruiseAltitudePlanner_plan_cruise(CruiseAltitudePlanner *self) {
    while (1) {
        FlightTrajectory_adjust_altitude(self->trajectory);
        double current_altitude = FlightTrajectory_get_current_altitude(self->trajectory);
        if (current_altitude == self->trajectory->t) {
            self->trajectory->is_ascent = 1;
        }
    }
}

typedef struct {
    CruiseAltitudePlanner *planner;
} FlightControlSystem;

void FlightControlSystem_init(FlightControlSystem *self, CruiseAltitudePlanner *planner) {
    self->planner = planner;
}

void FlightControlSystem_execute(FlightControlSystem *self) {
    while (1) {
        CruiseAltitudePlanner_plan_cruise(self->planner);
    }
}

int main() {
    double initial_altitude = 5000.0;
    double target_altitude = 35000.0;
    double rate_of_climb = 100.0;
    double descent_rate = 50.0;

    FlightTrajectory trajectory;
    FlightTrajectory_init(&trajectory, initial_altitude, target_altitude, rate_of_climb, descent_rate);

    CruiseAltitudePlanner planner;
    CruiseAltitudePlanner_init(&planner, &trajectory);

    FlightControlSystem control_system;
    FlightControlSystem_init(&control_system, &planner);

    FlightControlSystem_execute(&control_system);

    return 0;
}