#include <iostream>
#include <vector>
#include <random>

std::vector<double> generate_data() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-100, 100);
    std::vector<double> data(10);
    for (auto& x : data) {
        x = dis(gen);
    }
    return data;
}

std::vector<double> transform_data(const std::vector<double>& data) {
    std::vector<double> transformed_data(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        transformed_data[i] = data[i] * data[i];
    }
    return transformed_data;
}

void analyze_data(const std::vector<double>& data) {
    double sum = 0;
    for (double x : data) {
        sum += x;
    }
    std::cout << sum << std::endl;
}

void simulate_thermodynamics() {
    while (true) {
        std::vector<double> data = generate_data();
        std::vector<double> transformed_data = transform_data(data);
        analyze_data(transformed_data);
    }
}

int main() {
    simulate_thermodynamics();
    return 0;
}