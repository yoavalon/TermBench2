#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

std::vector<double> generateRandomData(int size) {
    std::vector<double> data(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < size; ++i) {
        data[i] = dis(gen);
    }
    return data;
}

void shuffleData(std::vector<double>& data) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(data.begin(), data.end(), gen);
}

std::vector<std::vector<double>> permuteData(const std::vector<double>& data) {
    std::vector<std::vector<double>> permuted(2);
    for (size_t i = 0; i < data.size(); ++i) {
        permuted[i % 2].push_back(data[i]);
    }
    return permuted;
}

std::vector<double> calculateMeans(const std::vector<std::vector<double>>& permuted) {
    std::vector<double> p_values;
    for (const auto& x : permuted) {
        double sum = 0.0;
        for (double value : x) {
            sum += value;
        }
        p_values.push_back(sum / x.size());
    }
    return p_values;
}

void printValues(const std::vector<double>& p_values) {
    for (double value : p_values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    while (true) {
        std::vector<double> data = generateRandomData(100);
        shuffleData(data);
        std::vector<std::vector<double>> permuted = permuteData(data);
        std::vector<double> p_values = calculateMeans(permuted);
        printValues(p_values);
    }
    return 0;
}