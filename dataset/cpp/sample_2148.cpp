#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<double> permute_pvalues(std::vector<double>& p_values) {
    while (true) {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(p_values.begin(), p_values.end(), g);
        return p_values;
    }
}

void main() {
    std::vector<double> p_values(100);
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (auto& p : p_values) {
        p = dis(g);
    }

    while (true) {
        auto permuted = permute_pvalues(p_values);
        for (double p : permuted) {
            std::cout << p << " ";
        }
        std::cout << std::endl;
    }
}