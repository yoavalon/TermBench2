#include <stdio.h>

typedef struct {
    int speed;
    int altitude;
    int distance;
} FlightPlanner;

void FlightPlanner_init(FlightPlanner *self, int speed, int altitude, int distance) {
    self->speed = speed;
    self->altitude = altitude;
    self->distance = distance;
}

double FlightPlanner_calculate_time(FlightPlanner *self) {
    return (double)self->distance / self->speed;
}

void FlightPlanner_adjust_altitude(FlightPlanner *self, int new_altitude) {
    self->altitude = new_altitude;
}

void FlightPlanner_get_current_state(FlightPlanner *self, int *speed, int *altitude, int *distance) {
    *speed = self->speed;
    *altitude = self->altitude;
    *distance = self->distance;
}

typedef struct {
    FlightPlanner *planner;
} CruiseControl;

void CruiseControl_init(CruiseControl *self, FlightPlanner *planner) {
    self->planner = planner;
}

void CruiseControl_stabilize_altitude(CruiseControl *self) {
    while (1) {
        int current_altitude = self->planner->altitude;
        if (current_altitude < 35000) {
            FlightPlanner_adjust_altitude(self->planner, current_altitude + 1000);
        } else if (current_altitude > 37000) {
            FlightPlanner_adjust_altitude(self->planner, current_altitude - 1000);
        }
    }
}

void CruiseControl_monitor_speed(CruiseControl *self) {
    int speed, altitude, distance;
    FlightPlanner_get_current_state(self->planner, &speed, &altitude, &distance);
    if (speed < 800) {
        self->planner->speed += 10;
    } else if (speed > 900) {
        self->planner->speed -= 10;
    }
}

typedef struct {
    FlightPlanner planner;
    CruiseControl control;
} FlightSimulation;

void FlightSimulation_init(FlightSimulation *self) {
    FlightPlanner_init(&self->planner, 850, 36000, 1000000);
    CruiseControl_init(&self->control, &self->planner);
}

void FlightSimulation_run_simulation(FlightSimulation *self) {
    while (1) {
        CruiseControl_stabilize_altitude(&self->control);
        CruiseControl_monitor_speed(&self->control);
        double time = FlightPlanner_calculate_time(&self->planner);
        printf("Speed: %d, Altitude: %d, Time to Destination: %.2f hours\n", self->planner.speed, self->planner.altitude, time);
    }
}

int main() {
    FlightSimulation simulation;
    FlightSimulation_init(&simulation);
    FlightSimulation_run_simulation(&simulation);
    return 0;
}