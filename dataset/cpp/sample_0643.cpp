#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>

std::vector<double> permute_p_values(std::vector<int> data, int target, int perm_count, int depth = 0) {
    if (depth == perm_count) {
        return {};
    }
    std::shuffle(data.begin(), data.end(), std::default_random_engine(static_cast<unsigned int>(std::time(nullptr))));
    double mean = std::accumulate(data.begin(), data.end(), 0.0) / data.size();
    std::vector<double> result = {mean};
    result.insert(result.end(), permute_p_values(data, target, perm_count, depth + 1).begin(), permute_p_values(data, target, perm_count, depth + 1).end());
    return result;
}

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    int target = 3;
    int perm_count = 10;
    std::vector<double> results = permute_p_values(data, target, perm_count);
    for (double result : results) {
        std::cout << result << " ";
    }
    return 0;
}