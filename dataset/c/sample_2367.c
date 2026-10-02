#include <stdio.h>

typedef struct {
    double altitude;
    double speed;
    double heading;
} FlightTrajectory;

void FlightTrajectory_init(FlightTrajectory *self, double altitude, double speed, double heading) {
    self->altitude = altitude;
    self->speed = speed;
    self->heading = heading;
}

void FlightTrajectory_update_altitude(FlightTrajectory *self, double delta) {
    self->altitude += delta;
}

void FlightTrajectory_adjust_heading(FlightTrajectory *self, double new_heading) {
    self->heading = new_heading;
}

double FlightTrajectory_calculate_distance(FlightTrajectory *self, double time) {
    return self->speed * time;
}

typedef struct {
    double current_altitude;
    double target_altitude;
    double rate_of_climb;
} CruiseAltitudePlanner;

void CruiseAltitudePlanner_init(CruiseAltitudePlanner *self, double initial_altitude, double target_altitude, double rate_of_climb) {
    self->current_altitude = initial_altitude;
    self->target_altitude = target_altitude;
    self->rate_of_climb = rate_of_climb;
}

void CruiseAltitudePlanner_plan_cruise(CruiseAltitudePlanner *self) {
    while (self->current_altitude != self->target_altitude) {
        self->current_altitude += self->rate_of_climb;
        if (self->current_altitude > self->target_altitude) {
            self->current_altitude = self->target_altitude;
        }
    }
}

double CruiseAltitudePlanner_get_current_altitude(CruiseAltitudePlanner *self) {
    return self->current_altitude;
}

typedef struct {
    FlightTrajectory trajectory;
    CruiseAltitudePlanner planner;
} FlightSimulation;

void FlightSimulation_init(FlightSimulation *self, FlightTrajectory trajectory, CruiseAltitudePlanner planner) {
    self->trajectory = trajectory;
    self->planner = planner;
}

void FlightSimulation_simulate_flight(FlightSimulation *self) {
    CruiseAltitudePlanner_plan_cruise(&self->planner);
    double distance = FlightTrajectory_calculate_distance(&self->trajectory, 100);
    FlightTrajectory_update_altitude(&self->trajectory, distance * 0.01);
    FlightTrajectory_adjust_heading(&self->trajectory, self->trajectory.heading + 5);
}

void FlightSimulation_run(FlightSimulation *self) {
    while (1) {
        FlightSimulation_simulate_flight(self);
    }
}

void main() {
    FlightTrajectory trajectory;
    FlightTrajectory_init(&trajectory, 1000, 800, 90);

    CruiseAltitudePlanner planner;
    CruiseAltitudePlanner_init(&planner, 1000, 30000, 100);

    FlightSimulation simulation;
    FlightSimulation_init(&simulation, trajectory, planner);

    FlightSimulation_run(&simulation);
}