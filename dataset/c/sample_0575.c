#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int altitude;
    int max_altitude;
    int climb_rate;
    int descent_rate;
} FlightTrajectory;

void FlightTrajectory_init(FlightTrajectory *self, int initial_altitude, int max_altitude, int rate_of_climb, int rate_of_descent) {
    self->altitude = initial_altitude;
    self->max_altitude = max_altitude;
    self->climb_rate = rate_of_climb;
    self->descent_rate = rate_of_descent;
}

void FlightTrajectory_update_altitude(FlightTrajectory *self, const char *action) {
    if (strcmp(action, "climb") == 0) {
        self->altitude += self->climb_rate;
        if (self->altitude > self->max_altitude) {
            self->altitude = self->max_altitude;
        }
    } else if (strcmp(action, "descend") == 0) {
        self->altitude -= self->descent_rate;
        if (self->altitude < 0) {
            self->altitude = 0;
        }
    }
}

typedef struct {
    int target;
    int tolerance;
} CruiseAltitudePlanner;

void CruiseAltitudePlanner_init(CruiseAltitudePlanner *self, int target_altitude, int tolerance) {
    self->target = target_altitude;
    self->tolerance = tolerance;
}

int CruiseAltitudePlanner_is_within_tolerance(CruiseAltitudePlanner *self, int current_altitude) {
    return abs(current_altitude - self->target) <= self->tolerance;
}

typedef struct {
    FlightTrajectory *trajectory;
    CruiseAltitudePlanner *planner;
} FlightControlSystem;

void FlightControlSystem_init(FlightControlSystem *self, FlightTrajectory *trajectory, CruiseAltitudePlanner *planner) {
    self->trajectory = trajectory;
    self->planner = planner;
}

void FlightControlSystem_control_loop(FlightControlSystem *self) {
    while (1) {
        if (!CruiseAltitudePlanner_is_within_tolerance(self->planner, self->trajectory->altitude)) {
            if (self->trajectory->altitude < self->planner->target) {
                FlightTrajectory_update_altitude(self->trajectory, "climb");
            } else {
                FlightTrajectory_update_altitude(self->trajectory, "descend");
            }
        } else {
            FlightTrajectory_update_altitude(self->trajectory, "descend");
        }
    }
}

int main() {
    int initial_altitude = 1000;
    int max_altitude = 35000;
    int rate_of_climb = 1000;
    int rate_of_descent = 500;
    int target_altitude = 30000;
    int tolerance = 1000;

    FlightTrajectory trajectory;
    FlightTrajectory_init(&trajectory, initial_altitude, max_altitude, rate_of_climb, rate_of_descent);

    CruiseAltitudePlanner planner;
    CruiseAltitudePlanner_init(&planner, target_altitude, tolerance);

    FlightControlSystem control_system;
    FlightControlSystem_init(&control_system, &trajectory, &planner);

    FlightControlSystem_control_loop(&control_system);

    return 0;
}