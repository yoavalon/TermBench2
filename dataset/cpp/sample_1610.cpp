#include <iostream>
#include <iomanip>

double calculate_altitude(double speed, double wind, double temperature) {
    double base_altitude = 35000;
    double altitude_adjustment = (speed - 600) * 0.5 + (wind - 10) * -0.2 + (temperature - 20) * 0.1;
    return base_altitude + altitude_adjustment;
}

void simulate_flight() {
    double speed = 550;
    double wind = 5;
    double temperature = 15;
    double altitude = calculate_altitude(speed, wind, temperature);
    while (true) {
        speed += 1;
        wind += 0.1;
        temperature -= 0.2;
        altitude = calculate_altitude(speed, wind, temperature);
        if (altitude < 30000) {
            speed -= 2;
        } else if (altitude > 40000) {
            speed -= 1;
        }
        std::cout << "Speed: " << std::fixed << std::setprecision(2) << speed << ", Wind: " << wind << ", Temperature: " << temperature << ", Altitude: " << altitude << std::endl;
    }
}

int main() {
    simulate_flight();
    return 0;
}