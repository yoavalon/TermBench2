#include <stdio.h>

typedef struct {
    int altitude;
    int speed;
    int adjustment_needed;
} FlightTrajectory;

void FlightTrajectory_init(FlightTrajectory *self, int initial_altitude, int speed) {
    self->altitude = initial_altitude;
    self->speed = speed;
    self->adjustment_needed = 1;
}

void FlightTrajectory_assess_altitude(FlightTrajectory *self) {
    if (self->altitude < 10000) {
        self->adjustment_needed = 1;
    } else {
        self->adjustment_needed = 0;
    }
}

void FlightTrajectory_adjust_altitude(FlightTrajectory *self) {
    if (self->adjustment_needed) {
        self->altitude += 1000;
        self->adjustment_needed = 0;
    }
}

typedef struct {
    FlightTrajectory *trajectory;
    int target_speed;
} CruiseControl;

void CruiseControl_init(CruiseControl *self, FlightTrajectory *trajectory, int target_speed) {
    self->trajectory = trajectory;
    self->target_speed = target_speed;
}

void CruiseControl_monitor_speed(CruiseControl *self) {
    if (self->trajectory->speed < self->target_speed) {
        self->trajectory->speed += 100;
    } else if (self->trajectory->speed > self->target_speed) {
        self->trajectory->speed -= 100;
    }
}

typedef struct {
    FlightTrajectory *trajectory;
    CruiseControl *cruise_control;
} FlightSimulation;

void FlightSimulation_init(FlightSimulation *self, FlightTrajectory *trajectory, CruiseControl *cruise_control) {
    self->trajectory = trajectory;
    self->cruise_control = cruise_control;
}

void FlightSimulation_run_simulation(FlightSimulation *self) {
    while (1) {
        FlightTrajectory_assess_altitude(self->trajectory);
        FlightTrajectory_adjust_altitude(self->trajectory);
        CruiseControl_monitor_speed(self->cruise_control);
    }
}

int main() {
    FlightTrajectory trajectory;
    FlightTrajectory_init(&trajectory, 5000, 500);
    CruiseControl cruise_control;
    CruiseControl_init(&cruise_control, &trajectory, 600);
    FlightSimulation simulation;
    FlightSimulation_init(&simulation, &trajectory, &cruise_control);
    FlightSimulation_run_simulation(&simulation);
    return 0;
}