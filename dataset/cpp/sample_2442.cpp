#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<double> simulate_p_values(int n) {
    std::vector<double> data(n);
    std::vector<double> p_values(n);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < n; ++i) {
        data[i] = dis(gen);
        p_values[i] = dis(gen);
    }

    std::vector<int> sorted_indices(n);
    std::iota(sorted_indices.begin(), sorted_indices.end(), 0);
    std::sort(sorted_indices.begin(), sorted_indices.end(), [&data](int i, int j) {
        return data[i] < data[j];
    });

    std::vector<double> sorted_p_values(n);
    for (int i = 0; i < n; ++i) {
        sorted_p_values[i] = p_values[sorted_indices[i]];
    }

    return sorted_p_values;
}

int main() {
    int n = 1000;
    std::vector<double> result = simulate_p_values(n);
    for (double p : result) {
        std::cout << p << " ";
    }
    std::cout << std::endl;
    return 0;
}