#include <iostream>

void simulate_boundary_conditions(int& temp, int& pressure, int iterations) {
    for (int _ = 0; _ < iterations; ++_) {
        if (temp > 500) {
            temp -= 50;
        }
        if (pressure < 100) {
            pressure += 20;
        }
    }
}

int main() {
    int temp = 550;
    int pressure = 90;
    int iterations = 10;
    simulate_boundary_conditions(temp, pressure, iterations);
    std::cout << "Final temperature: " << temp << ", Final pressure: " << pressure << std::endl;
    return 0;
}