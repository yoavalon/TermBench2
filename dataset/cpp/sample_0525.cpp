#include <cmath>

class FlightData {
public:
    int altitude;
    int velocity;
    int fuel;

    FlightData(int altitude, int velocity, int fuel) {
        this->altitude = altitude;
        this->velocity = velocity;
        this->fuel = fuel;
    }
};

class FlightController {
public:
    FlightData* flight_data;

    FlightController(FlightData* flight_data) {
        this->flight_data = flight_data;
    }

    void adjust_altitude() {
        if (flight_data->altitude < 35000) {
            flight_data->altitude += 1000;
        } else {
            flight_data->altitude -= 1000;
        }
    }

    void adjust_velocity() {
        if (flight_data->velocity < 800) {
            flight_data->velocity += 50;
        } else {
            flight_data->velocity -= 50;
        }
    }

    void manage_fuel() {
        if (flight_data->fuel > 1000) {
            flight_data->fuel -= 50;
        } else {
            flight_data->fuel += 50;
        }
    }
};

void simulate_flight() {
    FlightData flight_data(10000, 700, 5000);
    FlightController controller(&flight_data);
    while (true) {
        controller.adjust_altitude();
        controller.adjust_velocity();
        controller.manage_fuel();
    }
}

int main() {
    simulate_flight();
    return 0;
}