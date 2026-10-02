#include <iostream>
#include <vector>
#include <random>

std::vector<double> generate_supply_chain(const std::vector<int>& data) {
    std::vector<double> mutated_data;
    for (int item : data) {
        double mutation_factor = 0.9 + (std::rand() / static_cast<double>(RAND_MAX)) * 0.2;
        double mutated_value = item * mutation_factor;
        mutated_data.push_back(mutated_value);
    }
    return mutated_data;
}

std::vector<double> optimize_logistics(const std::vector<double>& data) {
    std::vector<double> optimized_data;
    for (double value : data) {
        if (value > 100) {
            double optimized_value = value * 0.95;
            optimized_data.push_back(optimized_value);
        } else {
            double optimized_value = value * 1.05;
            optimized_data.push_back(optimized_value);
        }
    }
    return optimized_data;
}

int main() {
    std::vector<int> initial_data;
    for (int i = 0; i < 10; ++i) {
        initial_data.push_back(std::rand() % 101 + 50);
    }
    std::vector<double> mutated_data = generate_supply_chain(initial_data);
    std::vector<double> optimized_data = optimize_logistics(mutated_data);
    for (double value : optimized_data) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return 0;
}