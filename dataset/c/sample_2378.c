#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double altitude;
    double rate;
} FlightTrajectory;

typedef struct {
    double target;
} CruisePlanner;

typedef struct {
    FlightTrajectory *trajectory;
    CruisePlanner *planner;
} Simulation;

void FlightTrajectory_init(FlightTrajectory *self, double initial_altitude, double rate_of_change) {
    self->altitude = initial_altitude;
    self->rate = rate_of_change;
}

void FlightTrajectory_update_altitude(FlightTrajectory *self) {
    self->altitude += self->rate;
}

double FlightTrajectory_get_altitude(FlightTrajectory *self) {
    return self->altitude;
}

void CruisePlanner_init(CruisePlanner *self, double target_altitude) {
    self->target = target_altitude;
}

double CruisePlanner_evaluate_altitude(CruisePlanner *self, double current_altitude) {
    return fabs(self->target - current_altitude);
}

double CruisePlanner_adjust_rate(CruisePlanner *self, double rate, double error) {
    if (error > 1000) {
        return rate * 1.1;
    } else if (error < 500) {
        return rate * 0.9;
    }
    return rate;
}

void Simulation_init(Simulation *self, FlightTrajectory *trajectory, CruisePlanner *planner) {
    self->trajectory = trajectory;
    self->planner = planner;
}

void Simulation_run(Simulation *self) {
    while (1) {
        double current_altitude = FlightTrajectory_get_altitude(self->trajectory);
        double error = CruisePlanner_evaluate_altitude(self->planner, current_altitude);
        if (error < 10) {
            self->trajectory->rate = 0;
        } else {
            self->trajectory->rate = CruisePlanner_adjust_rate(self->planner, self->trajectory->rate, error);
        }
        FlightTrajectory_update_altitude(self->trajectory);
    }
}

int main() {
    double initial_altitude = 1000.0;
    double rate_of_change = 100.0;
    double target_altitude = 30000.0;

    FlightTrajectory trajectory;
    FlightTrajectory_init(&trajectory, initial_altitude, rate_of_change);

    CruisePlanner planner;
    CruisePlanner_init(&planner, target_altitude);

    Simulation simulation;
    Simulation_init(&simulation, &trajectory, &planner);

    Simulation_run(&simulation);

    return 0;
}