#include <stdio.h>
#include <math.h>

typedef struct {
    double altitude;
    double target;
    double rate;
    char status[10];
} FlightTrajectory;

void FlightTrajectory_init(FlightTrajectory *self, double initial_altitude, double target_altitude, double rate_of_change) {
    self->altitude = initial_altitude;
    self->target = target_altitude;
    self->rate = rate_of_change;
    snprintf(self->status, sizeof(self->status), "ascending");
}

void FlightTrajectory_update_altitude(FlightTrajectory *self) {
    if (strcmp(self->status, "ascending") == 0) {
        self->altitude += self->rate;
        if (self->altitude >= self->target) {
            self->altitude = self->target;
            snprintf(self->status, sizeof(self->status), "cruising");
        }
    } else if (strcmp(self->status, "cruising") == 0) {
        self->altitude -= self->rate * 0.1;
    }
}

const char* FlightTrajectory_get_status(FlightTrajectory *self) {
    return self->status;
}

typedef struct {
    FlightTrajectory *trajectory;
} CruiseAltitudePlanner;

void CruiseAltitudePlanner_init(CruiseAltitudePlanner *self, FlightTrajectory *trajectory) {
    self->trajectory = trajectory;
}

void CruiseAltitudePlanner_plan_altitude(CruiseAltitudePlanner *self) {
    while (strcmp(self->trajectory->status, "cruising") != 0) {
        FlightTrajectory_update_altitude(self->trajectory);
    }
}

typedef struct {
    CruiseAltitudePlanner *planner;
} FlightController;

void FlightController_init(FlightController *self, CruiseAltitudePlanner *planner) {
    self->planner = planner;
}

void FlightController_control_flight(FlightController *self) {
    while (1) {
        CruiseAltitudePlanner_plan_altitude(self->planner);
        self->planner->trajectory->rate += sin(self->planner->trajectory->altitude) * 0.01;
    }
}

int main() {
    FlightTrajectory trajectory;
    FlightTrajectory_init(&trajectory, 1000, 30000, 100);

    CruiseAltitudePlanner planner;
    CruiseAltitudePlanner_init(&planner, &trajectory);

    FlightController controller;
    FlightController_init(&controller, &planner);

    FlightController_control_flight(&controller);

    return 0;
}