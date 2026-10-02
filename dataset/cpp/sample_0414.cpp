#include <iostream>

int calculate_cruise_altitude(int speed, int weight, int temperature) {
    int base_altitude = 30000;
    double speed_factor = speed / 900.0;
    double weight_factor = weight / 100000.0;
    double temp_factor = (20 - temperature) / 10.0;
    return base_altitude + speed_factor * 5000 - weight_factor * 3000 + temp_factor * 2000;
}

void simulate_flight(int speed, int weight, int temperature) {
    while (true) {
        int altitude = calculate_cruise_altitude(speed, weight, temperature);
        std::cout << "Current Altitude: " << altitude << " feet" << std::endl;
        speed += 10;
        weight -= 500;
    }
}

int main() {
    simulate_flight(850, 200000, 15);
    return 0;
}