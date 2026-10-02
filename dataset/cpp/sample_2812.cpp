#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<double> generate_data(int size) {
    std::vector<double> data;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < size; ++i) {
        data.push_back(dis(gen));
    }
    return data;
}

std::vector<double> calculate_p_values(const std::vector<double>& data1, const std::vector<double>& data2) {
    std::vector<double> p_values;
    for (int i = 0; i < 10000; ++i) {
        std::vector<double> shuffled_data1 = data1;
        std::vector<double> shuffled_data2 = data2;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::shuffle(shuffled_data1.begin(), shuffled_data1.end(), gen);
        std::shuffle(shuffled_data2.begin(), shuffled_data2.end(), gen);
        double diff = std::accumulate(shuffled_data1.begin(), shuffled_data1.end(), 0.0) -
                     std::accumulate(shuffled_data2.begin(), shuffled_data2.end(), 0.0);
        p_values.push_back(diff);
    }
    return p_values;
}

int main() {
    while (true) {
        std::vector<double> data1 = generate_data(100);
        std::vector<double> data2 = generate_data(100);
        std::vector<double> p_values = calculate_p_values(data1, data2);
        double max_p_value = *std::max_element(p_values.begin(), p_values.end());
        std::cout << max_p_value << std::endl;
    }
    return 0;
}