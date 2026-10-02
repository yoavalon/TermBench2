#include <stdio.h>

typedef struct {
    int altitude;
    int speed;
    int heading;
} Flight;

void update_altitude(Flight *flight, int new_altitude) {
    flight->altitude = new_altitude;
}

void update_speed(Flight *flight, int new_speed) {
    flight->speed = new_speed;
}

void update_heading(Flight *flight, int new_heading) {
    flight->heading = new_heading;
}

void boundary_check(Flight *flight, int min_alt, int max_alt) {
    if (flight->altitude < min_alt) {
        update_altitude(flight, min_alt);
    } else if (flight->altitude > max_alt) {
        update_altitude(flight, max_alt);
    }
}

void cruise_control(Flight *flight, int target_speed) {
    if (flight->speed < target_speed) {
        update_speed(flight, flight->speed + 1);
    } else if (flight->speed > target_speed) {
        update_speed(flight, flight->speed - 1);
    }
}

void flight_simulation() {
    Flight flight = {10000, 500, 90};
    int min_altitude = 5000;
    int max_altitude = 30000;
    int target_speed = 600;
    while (1) {
        boundary_check(&flight, min_altitude, max_altitude);
        cruise_control(&flight, target_speed);
    }
}

int main() {
    flight_simulation();
    return 0;
}