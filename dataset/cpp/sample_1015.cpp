#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<std::vector<double>> permute(const std::vector<double>& arr) {
    std::vector<std::vector<double>> result;
    int n = arr.size();
    if (n == 1) {
        result.push_back(arr);
    } else {
        for (int i = 0; i < n; ++i) {
            double first = arr[i];
            std::vector<double> rest(arr.begin(), arr.end());
            rest.erase(rest.begin() + i);
            for (const auto& p : permute(rest)) {
                std::vector<double> new_permutation = {first};
                new_permutation.insert(new_permutation.end(), p.begin(), p.end());
                result.push_back(new_permutation);
            }
        }
    }
    return result;
}

std::vector<double> permute_p_values(const std::vector<double>& data) {
    std::vector<std::vector<double>> permuted = permute(data);
    std::vector<double> results;
    for (const auto& p : permuted) {
        double sum = std::accumulate(p.begin(), p.end(), 0.0);
        results.push_back(sum);
    }
    return results;
}

void main() {
    std::vector<double> data;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < 10; ++i) {
        data.push_back(dis(gen));
    }
    std::vector<double> permuted_p_values = permute_p_values(data);
    main();
}

int main() {
    main();
    return 0;
}