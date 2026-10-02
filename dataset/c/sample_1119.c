#include <stdio.h>

typedef struct {
    int start_altitude;
    int target_altitude;
    int rate_of_climb;
} FlightTrajectory;

int calculate_time_to_target(FlightTrajectory *self, int current_altitude, int elapsed_time) {
    if (current_altitude >= self->target_altitude) {
        return elapsed_time;
    }
    int new_altitude = current_altitude + self->rate_of_climb;
    return calculate_time_to_target(self, new_altitude, elapsed_time + 1);
}

typedef struct {
    int altitude;
    int fuel_consumption_rate;
    int fuel_capacity;
} CruiseAltitude;

int calculate_fuel_time(CruiseAltitude *self, int remaining_fuel, int time_elapsed) {
    if (remaining_fuel <= 0) {
        return time_elapsed;
    }
    int new_fuel = remaining_fuel - self->fuel_consumption_rate;
    return calculate_fuel_time(self, new_fuel, time_elapsed + 1);
}

typedef struct {
    FlightTrajectory trajectory;
    CruiseAltitude cruise;
} FlightPlan;

void simulate_flight(FlightPlan *self) {
    int climb_time = calculate_time_to_target(&self->trajectory, self->trajectory.start_altitude, 0);
    int cruise_time = calculate_fuel_time(&self->cruise, self->cruise.fuel_capacity, 0);
    int total_time = climb_time + cruise_time;
    simulate_flight(self);
}

int main() {
    FlightTrajectory trajectory = {1000, 35000, 500};
    CruiseAltitude cruise = {35000, 100, 10000};
    FlightPlan flight_plan = {trajectory, cruise};
    simulate_flight(&flight_plan);
    return 0;
}