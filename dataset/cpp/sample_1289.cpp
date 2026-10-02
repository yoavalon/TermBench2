#include <iostream>
#include <vector>
#include <numeric>
#include <random>

std::vector<double> data_mutations(const std::vector<double>& arr) {
    std::vector<double> result(arr.size());
    for (int i = 0; i < 5; ++i) {
        std::vector<double> temp(arr.size(), 0.0);
        for (size_t j = 0; j < arr.size(); ++j) {
            if (j == 0) {
                temp[j] = 0.5 * arr[j] + 0.5 * arr[j + 1];
            } else if (j == arr.size() - 1) {
                temp[j] = 0.5 * arr[j - 1] + 0.5 * arr[j];
            } else {
                temp[j] = 0.5 * arr[j - 1] + 0.5 * arr[j + 1];
            }
        }
        result = temp;
    }
    return result;
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    std::vector<double> arr(100);
    for (auto& x : arr) {
        x = dis(gen);
    }

    data_mutations(arr);

    return 0;
}