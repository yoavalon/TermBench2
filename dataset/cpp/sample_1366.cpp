#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::vector<double> generate_data(int size) {
    std::vector<double> data;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-10, 10);
    for (int i = 0; i < size; ++i) {
        data.push_back(dis(gen));
    }
    return data;
}

std::vector<double> mutate_data(const std::vector<double>& data, double mutation_rate) {
    std::vector<double> mutated_data;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.5, 1.5);
    std::uniform_real_distribution<> mutation_dis(0.0, 1.0);
    for (double value : data) {
        if (mutation_dis(gen) < mutation_rate) {
            mutated_data.push_back(value * dis(gen));
        } else {
            mutated_data.push_back(value);
        }
    }
    return mutated_data;
}

std::pair<double, double> analyze_data(const std::vector<double>& data) {
    double sum = 0.0;
    for (double value : data) {
        sum += value;
    }
    double average = sum / data.size();
    double variance = 0.0;
    for (double value : data) {
        variance += (value - average) * (value - average);
    }
    variance /= data.size();
    return {average, variance};
}

int main() {
    int initial_size = 100;
    double mutation_rate = 0.1;
    std::vector<double> data = generate_data(initial_size);
    std::vector<double> mutated_data = mutate_data(data, mutation_rate);
    auto [average, variance] = analyze_data(mutated_data);
    std::cout << "Average: " << average << ", Variance: " << variance << std::endl;
    return 0;
}