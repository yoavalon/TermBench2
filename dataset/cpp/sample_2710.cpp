#include <iostream>
#include <tuple>

std::tuple<double, double, double> simulate() {
    static double x = 1.0, y = 0.0, z = 0.0;
    while (true) {
        double new_x = y;
        double new_y = z;
        double new_z = 3.9 * x * (1 - x) + z;
        x = new_x;
        y = new_y;
        z = new_z;
        yield std::make_tuple(x, y, z);
    }
}

int main() {
    for (auto [state_x, state_y, state_z] : simulate()) {
        std::cout << "(" << state_x << ", " << state_y << ", " << state_z << ")" << std::endl;
    }
    return 0;
}