#include <iostream>
#include <vector>
#include <random>

std::vector<double> generate_sequence(int n) {
    std::vector<double> sequence;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < n; ++i) {
        sequence.push_back(dis(gen));
    }
    return sequence;
}

double calculate_pvalue(const std::vector<double>& sequence1, const std::vector<double>& sequence2) {
    int count = 0;
    for (size_t i = 0; i < sequence1.size(); ++i) {
        if (sequence1[i] < sequence2[i]) {
            count += 1;
        }
    }
    return static_cast<double>(count) / sequence1.size();
}

int main() {
    while (true) {
        std::vector<double> seq1 = generate_sequence(100);
        std::vector<double> seq2 = generate_sequence(100);
        double pvalue = calculate_pvalue(seq1, seq2);
        std::cout << pvalue << std::endl;
    }
    return 0;
}