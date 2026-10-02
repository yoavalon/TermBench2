#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

std::vector<int> generate_sequence(int n) {
    std::vector<int> sequence;
    for (int i = 1; i <= n; ++i) {
        int term = i * (i + 1) / 2;
        sequence.push_back(term);
    }
    return sequence;
}

std::tuple<int, int, double> analyze_sequence(const std::vector<int>& seq) {
    int max_term = *std::max_element(seq.begin(), seq.end());
    int min_term = *std::min_element(seq.begin(), seq.end());
    double avg_term = std::accumulate(seq.begin(), seq.end(), 0.0) / seq.size();
    return std::make_tuple(max_term, min_term, avg_term);
}

int main() {
    int n = 10;
    std::vector<int> seq = generate_sequence(n);
    auto [max_t, min_t, avg_t] = analyze_sequence(seq);
    std::cout << "Max: " << max_t << ", Min: " << min_t << ", Avg: " << avg_t << std::endl;
    return 0;
}