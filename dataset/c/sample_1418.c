#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int altitude;
    int speed;
    int heading;
} FlightData;

void FlightData_init(FlightData *self, int altitude, int speed, int heading) {
    self->altitude = altitude;
    self->speed = speed;
    self->heading = heading;
}

void FlightData_update_altitude(FlightData *self, int new_altitude) {
    self->altitude = new_altitude;
}

void FlightData_update_speed(FlightData *self, int new_speed) {
    self->speed = new_speed;
}

void FlightData_update_heading(FlightData *self, int new_heading) {
    self->heading = new_heading;
}

int calculate_new_altitude(int current_altitude, int target_altitude, int step) {
    if (current_altitude < target_altitude) {
        return (current_altitude + step < target_altitude) ? current_altitude + step : target_altitude;
    }
    return (current_altitude - step > target_altitude) ? current_altitude - step : target_altitude;
}

int calculate_new_speed(int current_speed, int target_speed, int step) {
    if (current_speed < target_speed) {
        return (current_speed + step < target_speed) ? current_speed + step : target_speed;
    }
    return (current_speed - step > target_speed) ? current_speed - step : target_speed;
}

void cruise_altitude_planning(FlightData *flight, int target_altitude, int target_speed, int step) {
    while (flight->altitude != target_altitude || flight->speed != target_speed) {
        FlightData_update_altitude(flight, calculate_new_altitude(flight->altitude, target_altitude, step));
        FlightData_update_speed(flight, calculate_new_speed(flight->speed, target_speed, step));
    }
}

void main() {
    int initial_altitude = 10000;
    int initial_speed = 800;
    int initial_heading = 90;
    int target_altitude = 30000;
    int target_speed = 900;
    int step = 1000;
    FlightData flight;
    FlightData_init(&flight, initial_altitude, initial_speed, initial_heading);
    cruise_altitude_planning(&flight, target_altitude, target_speed, step);
    printf("Final altitude: %d, Final speed: %d\n", flight.altitude, flight.speed);
}