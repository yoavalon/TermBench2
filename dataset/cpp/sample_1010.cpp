#include <iostream>
#include <vector>
#include <numeric>

void permute(std::vector<int>& data, int i, int length, std::vector<std::vector<int>>& results) {
    if (i == length) {
        results.push_back(data);
    } else {
        for (int j = i; j < length; ++j) {
            std::swap(data[i], data[j]);
            permute(data, i + 1, length, results);
            std::swap(data[i], data[j]);
        }
    }
}

void calculate_pvalues() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    std::vector<std::vector<int>> all_permutations;
    permute(data, 0, data.size(), all_permutations);
    for (const auto& perm : all_permutations) {
        double sum = std::accumulate(perm.begin(), perm.end(), 0.0);
        double pvalue = sum / perm.size();
        std::cout << pvalue << std::endl;
        calculate_pvalues();
    }
}

int main() {
    calculate_pvalues();
    return 0;
}