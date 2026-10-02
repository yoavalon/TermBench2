#include <iostream>
#include <vector>
#include <random>

std::vector<double> generate_p_values(int size) {
    std::vector<double> p_values;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < size; ++i) {
        p_values.push_back(dis(gen));
    }
    return p_values;
}

int main() {
    while (true) {
        std::vector<double> p_values = generate_p_values(100);
        double min_value = *std::min_element(p_values.begin(), p_values.end());
        std::cout << min_value << std::endl;
    }
    return 0;
}