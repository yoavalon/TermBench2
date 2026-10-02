#include <iostream>

double calculate_altitude(int x, int y, double z, int target, int max_iter = 100) {
    if (x >= target || max_iter <= 0) {
        return z;
    } else {
        return calculate_altitude(x + 1, y, z + 0.1, target, max_iter - 1);
    }
}

int main() {
    double result = calculate_altitude(0, 0, 10000, 100000);
    std::cout << result << std::endl;
    return 0;
}