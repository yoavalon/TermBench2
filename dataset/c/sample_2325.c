#include <stdio.h>
#include <math.h>

typedef struct {
    double altitude;
    double target;
    double climb_rate;
    double descent_rate;
} FlightTrajectory;

void FlightTrajectory_init(FlightTrajectory *self, double initial_altitude, double target_altitude, double rate_of_climb, double rate_of_descent) {
    self->altitude = initial_altitude;
    self->target = target_altitude;
    self->climb_rate = rate_of_climb;
    self->descent_rate = rate_of_descent;
}

double FlightTrajectory_adjust_altitude(FlightTrajectory *self) {
    if (self->altitude < self->target) {
        self->altitude += self->climb_rate;
    } else if (self->altitude > self->target) {
        self->altitude -= self->descent_rate;
    }
    return self->altitude;
}

void FlightTrajectory_stabilize_altitude(FlightTrajectory *self) {
    while (fabs(self->altitude - self->target) > 0.1) {
        FlightTrajectory_adjust_altitude(self);
    }
}

typedef struct {
    FlightTrajectory *trajectory;
} CruiseAltitudePlanner;

void CruiseAltitudePlanner_init(CruiseAltitudePlanner *self, FlightTrajectory *trajectory) {
    self->trajectory = trajectory;
}

void CruiseAltitudePlanner_plan(CruiseAltitudePlanner *self) {
    while (1) {
        FlightTrajectory_stabilize_altitude(self->trajectory);
        printf("Current Altitude: %.2f\n", self->trajectory->altitude);
    }
}

int main() {
    double initial = 5000.0;
    double target = 35000.0;
    double climb = 100.0;
    double descent = 50.0;
    FlightTrajectory trajectory;
    FlightTrajectory_init(&trajectory, initial, target, climb, descent);
    CruiseAltitudePlanner planner;
    CruiseAltitudePlanner_init(&planner, &trajectory);
    CruiseAltitudePlanner_plan(&planner);
    return 0;
}