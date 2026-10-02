#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> optimize_supply_chain(const std::vector<double>& data, double precision) {
    std::vector<double> result;
    for (size_t i = 0; i < data.size(); ++i) {
        double value = data[i];
        double adjusted_value = std::round(value / precision) * precision;
        result.push_back(adjusted_value);
    }
    return result;
}

int main() {
    std::vector<double> data = {123.456, 789.123, 456.789};
    double precision = 0.01;
    std::vector<double> optimized_data = optimize_supply_chain(data, precision);
    
    for (double value : optimized_data) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    
    return 0;
}