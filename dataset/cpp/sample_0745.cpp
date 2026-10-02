#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void permute(const std::vector<int>& data, int index, std::vector<int>& result, std::vector<std::vector<int>>& results) {
    if (index == data.size()) {
        results.push_back(result);
    } else {
        for (int i = 0; i < data.size(); ++i) {
            if (std::find(result.begin(), result.end(), data[i]) == result.end()) {
                result.push_back(data[i]);
                permute(data, index + 1, result, results);
                result.pop_back();
            }
        }
    }
}

double calculate_pvalue(const std::vector<int>& data1, const std::vector<int>& data2) {
    std::vector<int> combined(data1.begin(), data1.end());
    combined.insert(combined.end(), data2.begin(), data2.end());
    double original_mean_diff = std::accumulate(data1.begin(), data1.end(), 0.0) / data1.size() - 
                               std::accumulate(data2.begin(), data2.end(), 0.0) / data2.size();
    int count_greater = 0;
    std::vector<std::vector<int>> permutations;
    std::vector<int> result;
    permute(combined, 0, result, permutations);
    for (const auto& perm : permutations) {
        std::vector<int> perm1(perm.begin(), perm.begin() + data1.size());
        std::vector<int> perm2(perm.begin() + data1.size(), perm.end());
        double perm_mean_diff = std::accumulate(perm1.begin(), perm1.end(), 0.0) / perm1.size() - 
                               std::accumulate(perm2.begin(), perm2.end(), 0.0) / perm2.size();
        if (perm_mean_diff >= original_mean_diff) {
            count_greater++;
        }
    }
    return static_cast<double>(count_greater) / permutations.size();
}

int main() {
    std::vector<int> data1 = {1, 2, 3, 4};
    std::vector<int> data2 = {5, 6, 7, 8};
    double pvalue = calculate_pvalue(data1, data2);
    std::cout << pvalue << std::endl;
    return 0;
}