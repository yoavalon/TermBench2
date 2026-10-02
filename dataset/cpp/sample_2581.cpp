#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

double calculate_similarity(const std::string& seq1, const std::string& seq2) {
    int score = 0;
    int length = std::min(seq1.length(), seq2.length());
    for (int i = 0; i < length; ++i) {
        if (seq1[i] == seq2[i]) {
            ++score;
        }
    }
    return static_cast<double>(score) / length;
}

std::pair<std::pair<std::string, std::string>, double> find_best_alignment(const std::vector<std::string>& sequences) {
    double max_score = 0.0;
    std::pair<std::string, std::string> best_pair;
    for (size_t i = 0; i < sequences.size(); ++i) {
        for (size_t j = i + 1; j < sequences.size(); ++j) {
            double score = calculate_similarity(sequences[i], sequences[j]);
            if (score > max_score) {
                max_score = score;
                best_pair = {sequences[i], sequences[j]};
            }
        }
    }
    return {best_pair, max_score};
}

int main() {
    std::vector<std::string> sequences = {"ATCG", "ATCC", "AGCG", "ACCG"};
    auto [best_pair, max_score] = find_best_alignment(sequences);
    std::cout << "Best alignment: (" << best_pair.first << ", " << best_pair.second << ") with score: " << max_score << std::endl;
    return 0;
}