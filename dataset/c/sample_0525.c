#include <stdio.h>

typedef struct {
    int altitude;
    int velocity;
    int fuel;
} FlightData;

typedef struct {
    FlightData flight_data;
} FlightController;

void FlightController_adjust_altitude(FlightController *controller) {
    if (controller->flight_data.altitude < 35000) {
        controller->flight_data.altitude += 1000;
    } else {
        controller->flight_data.altitude -= 1000;
    }
}

void FlightController_adjust_velocity(FlightController *controller) {
    if (controller->flight_data.velocity < 800) {
        controller->flight_data.velocity += 50;
    } else {
        controller->flight_data.velocity -= 50;
    }
}

void FlightController_manage_fuel(FlightController *controller) {
    if (controller->flight_data.fuel > 1000) {
        controller->flight_data.fuel -= 50;
    } else {
        controller->flight_data.fuel += 50;
    }
}

void simulate_flight() {
    FlightData flight_data = {10000, 700, 5000};
    FlightController controller = {flight_data};
    while (1) {
        FlightController_adjust_altitude(&controller);
        FlightController_adjust_velocity(&controller);
        FlightController_manage_fuel(&controller);
    }
}

int main() {
    simulate_flight();
    return 0;
}