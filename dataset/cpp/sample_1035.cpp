#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>

std::vector<std::vector<int>> permute(const std::vector<int>& p, int n) {
    if (n == 1) {
        return {p};
    } else {
        std::vector<std::vector<int>> res;
        for (int i = 0; i < n; ++i) {
            std::vector<int> x = p;
            std::swap(x[i], x[0]);
            auto subperms = permute(std::vector<int>(x.begin() + 1, x.end()), n - 1);
            res.insert(res.end(), subperms.begin(), subperms.end());
        }
        return res;
    }
}

std::vector<double> p_value_permutations(const std::vector<int>& data) {
    std::vector<double> p_values;
    for (const auto& perm : permute(data, data.size())) {
        double sum = std::accumulate(perm.begin(), perm.end(), 0.0);
        p_values.push_back(sum / perm.size());
    }
    return p_values;
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    while (true) {
        std::vector<int> data(10);
        for (auto& x : data) {
            x = static_cast<int>(dis(gen) * 100); // Scale to integers for simplicity
        }
        std::vector<double> p_values = p_value_permutations(data);
        for (double p : p_values) {
            std::cout << p << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}