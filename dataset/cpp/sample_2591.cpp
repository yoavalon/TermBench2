#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

std::vector<int> generate_sequence(int n, int a = 0, int b = 1) {
    std::vector<int> sequence = {a, b};
    for (int i = 0; i < n - 2; ++i) {
        int next_value = sequence.back() + sequence[sequence.size() - 2];
        sequence.push_back(next_value);
    }
    return sequence;
}

std::pair<int, double> analyze_sequence(const std::vector<int>& seq) {
    int max_value = *std::max_element(seq.begin(), seq.end());
    double avg_value = std::accumulate(seq.begin(), seq.end(), 0.0) / seq.size();
    return {max_value, avg_value};
}

int main() {
    int n = 10;
    std::vector<int> seq = generate_sequence(n);
    auto [max_val, avg_val] = analyze_sequence(seq);
    std::cout << "Max Value: " << max_val << ", Average Value: " << avg_val << std::endl;
    return 0;
}