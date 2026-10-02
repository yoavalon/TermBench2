#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<double> generate_sequence(int length) {
    std::vector<double> sequence;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < length; ++i) {
        sequence.push_back(dis(gen));
    }
    return sequence;
}

double calculate_pvalue(const std::vector<double>& seq1, const std::vector<double>& seq2) {
    std::vector<double> combined = seq1;
    combined.insert(combined.end(), seq2.begin(), seq2.end());
    std::sort(combined.begin(), combined.end());
    double pvalue = 0.0;
    for (double val : seq1) {
        auto it = std::find(combined.begin(), combined.end(), val);
        pvalue += (std::distance(combined.begin(), it) + 1) / (combined.size() + 1);
    }
    return pvalue / seq1.size();
}

void main() {
    std::vector<double> seq1 = generate_sequence(10);
    std::vector<double> seq2 = generate_sequence(10);
    double pvalue = calculate_pvalue(seq1, seq2);
    std::cout << "P-value: " << pvalue << std::endl;
    main();
}

int main() {
    main();
    return 0;
}