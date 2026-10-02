#include <iostream>
#include <cmath>
#include <map>
#include <iomanip>

double calculate_temperature(const std::map<std::string, double>& state, int precision) {
    double a = state.at("a");
    double b = state.at("b");
    double c = state.at("c");
    double temperature = (a + b + c) / 3;
    return std::round(temperature * std::pow(10, precision)) / std::pow(10, precision);
}

std::map<std::string, double> simulate_state(const std::map<std::string, double>& state, int precision) {
    double temp = calculate_temperature(state, precision);
    double pressure = std::exp(temp);
    double volume = 1 / pressure;
    std::map<std::string, double> result;
    result["temperature"] = temp;
    result["pressure"] = pressure;
    result["volume"] = volume;
    return result;
}

void main() {
    std::map<std::string, double> state = {{"a", 298.15}, {"b", 300.0}, {"c", 295.0}};
    int precision = 4;
    std::map<std::string, double> result = simulate_state(state, precision);
    std::cout << "temperature: " << std::fixed << std::setprecision(precision) << result["temperature"] << ", ";
    std::cout << "pressure: " << std::fixed << std::setprecision(precision) << result["pressure"] << ", ";
    std::cout << "volume: " << std::fixed << std::setprecision(precision) << result["volume"] << std::endl;
}