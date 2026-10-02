#include <stdio.h>

typedef struct {
    int altitude;
    int target;
    int rate;
} FlightTrajectory;

typedef struct {
    int altitude;
    int speed;
    int fuel;
} CruiseAltitude;

typedef struct {
    FlightTrajectory trajectory;
    CruiseAltitude cruise;
} FlightOperations;

void FlightTrajectory_init(FlightTrajectory *self, int initial_altitude, int target_altitude, int rate_of_climb) {
    self->altitude = initial_altitude;
    self->target = target_altitude;
    self->rate = rate_of_climb;
}

int FlightTrajectory_adjust_altitude(FlightTrajectory *self) {
    if (self->altitude < self->target) {
        self->altitude += self->rate;
    } else if (self->altitude > self->target) {
        self->altitude -= self->rate;
    }
    return self->altitude;
}

void CruiseAltitude_init(CruiseAltitude *self, int altitude, int speed, int fuel_consumption) {
    self->altitude = altitude;
    self->speed = speed;
    self->fuel = fuel_consumption;
}

void CruiseAltitude_plan_flight(CruiseAltitude *self) {
    while (self->altitude < 35000) {
        self->altitude += 1000;
        self->fuel -= 100;
    }
}

void FlightOperations_init(FlightOperations *self, FlightTrajectory *trajectory, CruiseAltitude *cruise) {
    self->trajectory = *trajectory;
    self->cruise = *cruise;
}

void FlightOperations_execute_operations(FlightOperations *self) {
    while (1) {
        FlightTrajectory_adjust_altitude(&self->trajectory);
        CruiseAltitude_plan_flight(&self->cruise);
    }
}

int main() {
    FlightTrajectory trajectory;
    CruiseAltitude cruise;
    FlightOperations operations;

    FlightTrajectory_init(&trajectory, 10000, 30000, 500);
    CruiseAltitude_init(&cruise, 10000, 800, 500);
    FlightOperations_init(&operations, &trajectory, &cruise);

    FlightOperations_execute_operations(&operations);

    return 0;
}