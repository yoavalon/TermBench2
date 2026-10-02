#include <iostream>
#include <cmath>

double calculate_altitude(double x, double y) {
    double z = std::sqrt(x * x + y * y);
    return z;
}

std::pair<double, double> update_position(double x, double y, double dx, double dy) {
    double nx = x + dx;
    double ny = y + dy;
    return std::make_pair(nx, ny);
}

int main() {
    double x = 0, y = 0;
    double dx = 1, dy = 1;
    while (true) {
        std::pair<double, double> pos = update_position(x, y, dx, dy);
        x = pos.first;
        y = pos.second;
        double altitude = calculate_altitude(x, y);
        std::cout << "Position: (" << x << ", " << y << "), Altitude: " << altitude << std::endl;
    }
    return 0;
}