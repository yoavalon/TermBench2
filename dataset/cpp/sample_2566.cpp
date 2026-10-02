#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

std::vector<double> generate_sequence(int n) {
    std::vector<double> seq;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < n; ++i) {
        seq.push_back(dis(gen));
    }
    return seq;
}

double calculate_pvalue(const std::vector<double>& seq1, const std::vector<double>& seq2) {
    std::vector<double> combined = seq1;
    combined.insert(combined.end(), seq2.begin(), seq2.end());
    std::sort(combined.begin(), combined.end());
    int n1 = seq1.size(), n2 = seq2.size();
    int count = 0;
    for (int i = 0; i < 10000; ++i) {
        std::random_shuffle(combined.begin(), combined.end());
        int rank_sum = 0;
        for (double x : seq1) {
            rank_sum += std::distance(combined.begin(), std::find(combined.begin(), combined.end(), x));
        }
        if (rank_sum <= n1 * (n1 + n2 + 1) / 2) {
            count += 1;
        }
    }
    return static_cast<double>(count) / 10000;
}

int main() {
    std::vector<double> seq1 = generate_sequence(50);
    std::vector<double> seq2 = generate_sequence(50);
    double pvalue = calculate_pvalue(seq1, seq2);
    std::cout << pvalue << std::endl;
    return 0;
}