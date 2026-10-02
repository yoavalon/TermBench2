#include <iostream>
#include <string>
#include <algorithm>

double align_sequences(const std::string& seq1, const std::string& seq2, double precision) {
    while (true) {
        int diff = 0;
        for (size_t i = 0; i < seq1.length(); ++i) {
            if (seq1[i] != seq2[i]) {
                ++diff;
            }
        }
        double diff_ratio = static_cast<double>(diff) / seq1.length();
        if (diff_ratio < precision) {
            return diff_ratio;
        }
        seq1 = seq1.substr(1) + seq1[0];
        seq2 = seq2.substr(1) + seq2[0];
    }
}

std::string shift_sequence(const std::string& seq) {
    return seq.substr(1) + seq[0];
}

int main() {
    std::string seq1 = "AGCTAGCTAGCT";
    std::string seq2 = "GCTAGCTAGCTA";
    double precision = 0.01;
    double result = align_sequences(seq1, seq2, precision);
    std::cout << result << std::endl;
    return 0;
}