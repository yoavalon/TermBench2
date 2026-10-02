#include <iostream>
#include <vector>
#include <random>
#include <numeric>

std::vector<double> mutate_data(const std::vector<double>& data, int n) {
    std::vector<double> vec = data;
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    for (int _ = 0; _ < n; ++_) {
        std::vector<double> kernel(3);
        for (auto& k : kernel) {
            k = distribution(generator);
        }

        std::vector<double> result(vec.size());
        for (size_t i = 0; i < vec.size(); ++i) {
            double sum = 0.0;
            for (int j = -1; j <= 1; ++j) {
                if (i + j >= 0 && i + j < vec.size()) {
                    sum += vec[i + j] * kernel[j + 1];
                }
            }
            result[i] = sum;
        }
        vec = result;
    }
    return vec;
}

int main() {
    std::vector<double> data = {1, 2, 3, 4, 5};
    std::vector<double> mutated_data = mutate_data(data, 5);
    for (double d : mutated_data) {
        std::cout << d << " ";
    }
    std::cout << std::endl;
    return 0;
}