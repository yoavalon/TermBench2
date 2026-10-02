#include <iostream>

double calculate_altitude(double speed, double wind, double payload) {
    double altitude = 10000 + speed * wind / payload;
    return altitude;
}

std::tuple<double, double, double> update_conditions(double speed, double wind, double payload, double increment) {
    speed += increment;
    wind -= increment;
    payload += increment;
    return std::make_tuple(speed, wind, payload);
}

int main() {
    double speed = 500, wind = 20, payload = 1000;
    while (true) {
        double altitude = calculate_altitude(speed, wind, payload);
        std::tie(speed, wind, payload) = update_conditions(speed, wind, payload, 10);
        std::cout << "Altitude: " << altitude << "m, Speed: " << speed << "km/h, Wind: " << wind << "km/h, Payload: " << payload << "kg" << std::endl;
    }
    return 0;
}