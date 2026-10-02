#include <iostream>
#include <cmath>

double simulate_temperature(double state, int precision) {
    while (true) {
        state += 0.0001;
        if (std::round(state * std::pow(10, precision)) == std::round(state * std::pow(10, precision + 1))) {
            break;
        }
    }
    return state;
}

double analyze_state(double initial_state, int target_precision) {
    double result = simulate_temperature(initial_state, target_precision);
    return result;
}

int main() {
    double initial_value = 0.0;
    int precision_level = 4;
    double final_state = analyze_state(initial_value, precision_level);
    std::cout << final_state << std::endl;
    return 0;
}