#include <iostream>
#include <vector>
#include <numeric>

std::vector<int> generate_sequence(int n) {
    std::vector<int> seq = {1, 1};
    while (seq.size() < n) {
        seq.push_back(seq.back() + seq[seq.size() - 2]);
    }
    return seq;
}

std::vector<int> optimize_distribution(const std::vector<int>& seq, int demand) {
    int total_supply = std::accumulate(seq.begin(), seq.end(), 0);
    if (total_supply < demand) {
        return std::vector<int>{"Insufficient supply"};
    } else {
        std::vector<int> result;
        for (size_t i = 0; i < seq.size(); ++i) {
            if (seq[i] <= demand) {
                result.push_back(seq[i]);
            }
        }
        return result;
    }
}

int main() {
    int n = 10;
    int demand = 15;
    std::vector<int> sequence = generate_sequence(n);
    std::vector<int> result = optimize_distribution(sequence, demand);
    for (const auto& item : result) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    return 0;
}