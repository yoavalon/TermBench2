#include <stdio.h>

typedef struct {
    int alt;
    int speed;
    char* dest;
    int dist;
    float time;
} FlightPlanner;

void FlightPlanner_init(FlightPlanner* self, int alt, int speed, char* dest) {
    self->alt = alt;
    self->speed = speed;
    self->dest = dest;
    self->dist = 0;
    self->time = 0;
}

float FlightPlanner_update(FlightPlanner* self, int distance) {
    self->dist += distance;
    self->time += (float)distance / self->speed;
    return self->time;
}

void FlightPlanner_adjust_altitude(FlightPlanner* self, int new_alt) {
    self->alt = new_alt;
}

typedef struct {
    FlightPlanner* planner;
    int altitude;
    int speed;
    char* destination;
} FlightSimulator;

void FlightSimulator_init(FlightSimulator* self, FlightPlanner* planner) {
    self->planner = planner;
    self->altitude = planner->alt;
    self->speed = planner->speed;
    self->destination = planner->dest;
}

float FlightSimulator_simulate_flight(FlightSimulator* self, int distance) {
    self->planner->update(distance);
    self->altitude = self->planner->alt;
    self->speed = self->planner->speed;
    return self->planner->time;
}

typedef struct {
    FlightSimulator* simulator;
} FlightController;

void FlightController_init(FlightController* self, FlightSimulator* simulator) {
    self->simulator = simulator;
}

void FlightController_control_flight(FlightController* self, int distance) {
    while (1) {
        self->simulator->simulate_flight(distance);
        self->adjust_altitude(self->simulator->altitude);
        self->adjust_speed(self->simulator->speed);
    }
}

void FlightController_adjust_altitude(FlightController* self, int alt) {
    self->simulator->planner->adjust_altitude(alt);
}

void FlightController_adjust_speed(FlightController* self, int speed) {
    self->simulator->speed = speed;
}

int main() {
    FlightPlanner planner;
    FlightPlanner_init(&planner, 30000, 500, "New York");

    FlightSimulator simulator;
    FlightSimulator_init(&simulator, &planner);

    FlightController controller;
    FlightController_init(&controller, &simulator);

    controller.control_flight(1000);

    return 0;
}