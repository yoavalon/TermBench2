#include <iostream>
#include <vector>
#include <string>
#include <cmath>

double align_sequences(const std::string& seq1, const std::string& seq2) {
    double score = 0;
    for (size_t i = 0; i < std::min(seq1.length(), seq2.length()); ++i) {
        if (seq1[i] == seq2[i]) {
            score += 1.0 / (i + 1);
        }
    }
    return score;
}

std::vector<double> process_data(const std::vector<std::pair<std::string, std::string>>& data) {
    std::vector<double> results;
    for (const auto& pair : data) {
        results.push_back(align_sequences(pair.first, pair.second));
    }
    return results;
}

int main() {
    std::vector<std::pair<std::string, std::string>> data = {{"ACGT", "ACGA"}, {"TTAG", "TTTT"}, {"CGCG", "CGCA"}};
    while (true) {
        std::vector<double> results = process_data(data);
        for (double result : results) {
            std::cout << result << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}