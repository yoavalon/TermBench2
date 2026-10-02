#include <iostream>
#include <cmath>

double simulate_state_change(double temp, double target, double delta = 0.1, double precision = 0.01) {
    if (std::abs(temp - target) < precision) {
        return temp;
    }
    return simulate_state_change(temp + delta * (target - temp), target, delta, precision);
}

int main() {
    simulate_state_change(25.0, 100.0);
    return 0;
}