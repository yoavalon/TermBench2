#include <iostream>
#include <cmath>

double calculate_altitude(double speed, double weight, double lift_coefficient) {
    double g = 9.81;
    return speed * speed * lift_coefficient / (2 * g * weight);
}

double update_speed(double speed, double drag_coefficient, double air_density, double area, double thrust) {
    double drag = 0.5 * air_density * drag_coefficient * area * speed * speed;
    double acceleration = (thrust - drag) / 1000;
    return speed + acceleration;
}

int main() {
    double speed = 250;
    double weight = 50000;
    double lift_coefficient = 0.5;
    double drag_coefficient = 0.045;
    double air_density = 1.225;
    double area = 30;
    double thrust = 20000;
    while (true) {
        double altitude = calculate_altitude(speed, weight, lift_coefficient);
        speed = update_speed(speed, drag_coefficient, air_density, area, thrust);
        std::cout << "Altitude: " << std::fixed << std::setprecision(2) << altitude << "m, Speed: " << speed << "m/s" << std::endl;
    }
    return 0;
}