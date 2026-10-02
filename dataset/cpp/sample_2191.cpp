#include <iostream>
#include <cmath>

void plan_altitude(double a, double b, double c) {
    double x = 1.0;
    while (x < a) {
        double y = b * pow(x, 2) + c * x + 1;
        double z = y / (x + 1);
        x = z + 0.0001;
        std::cout << "Altitude: " << x << ", Trajectory: " << y << ", Adjusted: " << z << std::endl;
    }
}

int main() {
    plan_altitude(1000, 0.01, 0.1);
    return 0;
}