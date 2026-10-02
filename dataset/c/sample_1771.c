#include <stdio.h>

typedef struct {
    int current_altitude;
    int target_altitude;
    int rate_of_climb;
    int rate_of_descent;
} FlightTrajectory;

void FlightTrajectory_init(FlightTrajectory *self, int initial_altitude, int target_altitude, int rate_of_climb, int rate_of_descent) {
    self->current_altitude = initial_altitude;
    self->target_altitude = target_altitude;
    self->rate_of_climb = rate_of_climb;
    self->rate_of_descent = rate_of_descent;
}

void FlightTrajectory_climb(FlightTrajectory *self) {
    if (self->current_altitude < self->target_altitude) {
        self->current_altitude += self->rate_of_climb;
        if (self->current_altitude > self->target_altitude) {
            self->current_altitude = self->target_altitude;
        }
    }
}

void FlightTrajectory_descend(FlightTrajectory *self) {
    if (self->current_altitude > self->target_altitude) {
        self->current_altitude -= self->rate_of_descent;
        if (self->current_altitude < self->target_altitude) {
            self->current_altitude = self->target_altitude;
        }
    }
}

void FlightTrajectory_adjust_altitude(FlightTrajectory *self) {
    if (self->current_altitude < self->target_altitude) {
        FlightTrajectory_climb(self);
    } else if (self->current_altitude > self->target_altitude) {
        FlightTrajectory_descend(self);
    }
}

typedef struct {
    FlightTrajectory *trajectory;
    int cruise_altitude;
    int altitude_changes[1000]; // Assuming a max of 1000 altitude changes for simplicity
    int log_index;
} CruiseAltitudeManager;

void CruiseAltitudeManager_init(CruiseAltitudeManager *self, FlightTrajectory *trajectory) {
    self->trajectory = trajectory;
    self->cruise_altitude = trajectory->target_altitude;
    self->log_index = 0;
}

void CruiseAltitudeManager_update_cruise_altitude(CruiseAltitudeManager *self, int new_altitude) {
    self->cruise_altitude = new_altitude;
    self->trajectory->target_altitude = new_altitude;
}

void CruiseAltitudeManager_log_altitude_change(CruiseAltitudeManager *self) {
    self->altitude_changes[self->log_index++] = self->trajectory->current_altitude;
}

void CruiseAltitudeManager_manage_cruise(CruiseAltitudeManager *self) {
    FlightTrajectory_adjust_altitude(self->trajectory);
    CruiseAltitudeManager_log_altitude_change(self);
}

typedef struct {
    FlightTrajectory trajectory;
    CruiseAltitudeManager cruise_manager;
} FlightSimulation;

void FlightSimulation_init(FlightSimulation *self, int initial_altitude, int target_altitude, int rate_of_climb, int rate_of_descent) {
    FlightTrajectory_init(&self->trajectory, initial_altitude, target_altitude, rate_of_climb, rate_of_descent);
    CruiseAltitudeManager_init(&self->cruise_manager, &self->trajectory);
}

void FlightSimulation_simulate_flight(FlightSimulation *self) {
    while (1) {
        CruiseAltitudeManager_manage_cruise(&self->cruise_manager);
    }
}

int main() {
    FlightSimulation flight_sim;
    FlightSimulation_init(&flight_sim, 5000, 35000, 500, 300);
    FlightSimulation_simulate_flight(&flight_sim);
    return 0;
}