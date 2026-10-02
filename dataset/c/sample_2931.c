#include <stdio.h>

typedef struct {
    int altitude;
    int climb_rate;
} FlightPlanner;

void FlightPlanner_init(FlightPlanner *self, int initial_altitude, int rate_of_climb) {
    self->altitude = initial_altitude;
    self->climb_rate = rate_of_climb;
}

void FlightPlanner_update_altitude(FlightPlanner *self, int time_step) {
    self->altitude += self->climb_rate * time_step;
}

int FlightPlanner_get_altitude(FlightPlanner *self) {
    return self->altitude;
}

typedef struct {
    int target;
} CruiseControl;

void CruiseControl_init(CruiseControl *self, int target_altitude) {
    self->target = target_altitude;
}

int CruiseControl_adjust_altitude(CruiseControl *self, int current_altitude) {
    if (current_altitude < self->target) {
        return 100;
    } else if (current_altitude > self->target) {
        return -50;
    } else {
        return 0;
    }
}

typedef struct {
    FlightPlanner planner;
    CruiseControl controller;
    int time_step;
} FlightSimulator;

void FlightSimulator_init(FlightSimulator *self, int initial_altitude, int target_altitude) {
    FlightPlanner_init(&self->planner, initial_altitude, 50);
    CruiseControl_init(&self->controller, target_altitude);
    self->time_step = 1;
}

void FlightSimulator_simulate_flight(FlightSimulator *self) {
    while (1) {
        int current_altitude = FlightPlanner_get_altitude(&self->planner);
        int adjustment = CruiseControl_adjust_altitude(&self->controller, current_altitude);
        self->planner.climb_rate = adjustment;
        FlightPlanner_update_altitude(&self->planner, self->time_step);
    }
}

int main() {
    FlightSimulator simulator;
    FlightSimulator_init(&simulator, 1000, 35000);
    FlightSimulator_simulate_flight(&simulator);
    return 0;
}