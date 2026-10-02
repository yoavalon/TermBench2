#include <iostream>
#include <random>

double simulate_temperature_change(double initial_temp, double rate, int steps) {
    double temperature = initial_temp;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0.0, 1.0);
    for (int _ = 0; _ < steps; ++_) {
        temperature += rate * d(gen);
    }
    return temperature;
}

double analyze_simulation_results(double initial_temp, double final_temp) {
    return final_temp - initial_temp;
}

int main() {
    double initial_temperature = 300.0;
    double rate_of_change = 0.5;
    int number_of_steps = 1000;
    double final_temperature = simulate_temperature_change(initial_temperature, rate_of_change, number_of_steps);
    double temperature_difference = analyze_simulation_results(initial_temperature, final_temperature);
    std::cout << "Initial Temperature: " << initial_temperature << ", Final Temperature: " << final_temperature << ", Change: " << temperature_difference << std::endl;
    return 0;
}