#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

std::vector<std::vector<int>> permute(const std::vector<int>& data, int i, int length) {
    std::vector<std::vector<int>> results;
    if (i == length) {
        results.push_back(data);
    } else {
        for (int j = i; j < length; ++j) {
            std::vector<int> swapped = data;
            std::swap(swapped[i], swapped[j]);
            auto sub_results = permute(swapped, i + 1, length);
            results.insert(results.end(), sub_results.begin(), sub_results.end());
        }
    }
    return results;
}

double calculate_p_value(int observed, const std::vector<int>& samples) {
    int count = 0;
    for (int sample : samples) {
        if (sample >= observed) {
            ++count;
        }
    }
    return static_cast<double>(count) / samples.size();
}

std::vector<int> generate_samples(const std::vector<int>& data, int n) {
    std::vector<int> samples;
    std::random_device rd;
    std::mt19937 gen(rd());
    for (int _ = 0; _ < n; ++_) {
        auto permuted_data = permute(data, 0, data.size());
        std::uniform_int_distribution<> dis(0, permuted_data.size() - 1);
        int sample = std::accumulate(permuted_data[dis(gen)].begin(), permuted_data[dis(gen)].end(), 0);
        samples.push_back(sample);
    }
    return samples;
}

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    int observed = std::accumulate(data.begin(), data.end(), 0);
    int n = 10000;
    std::vector<int> samples = generate_samples(data, n);
    double p_value = calculate_p_value(observed, samples);
    std::cout << p_value << std::endl;
    return 0;
}