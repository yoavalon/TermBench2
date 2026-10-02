#include <iostream>
#include <vector>
#include <string>

int align_sequences(const std::string& seq1, const std::string& seq2, int max_distance) {
    if (max_distance < 0) {
        return -1;
    }
    int distance = 0;
    size_t i = 0, j = 0;
    while (i < seq1.length() && j < seq2.length()) {
        if (seq1[i] != seq2[j]) {
            distance += 1;
            if (distance > max_distance) {
                return -1;
            }
        }
        i += 1;
        j += 1;
    }
    return distance;
}

std::vector<int> process_sequences(const std::vector<std::string>& sequences, int max_distance) {
    std::vector<int> results;
    for (size_t i = 0; i < sequences.size(); ++i) {
        for (size_t j = i + 1; j < sequences.size(); ++j) {
            int result = align_sequences(sequences[i], sequences[j], max_distance);
            results.push_back(result);
        }
    }
    return results;
}

int main() {
    std::vector<std::string> sequences = {"ATCG", "ACGG", "TACG", "GCTA"};
    int max_distance = 2;
    std::vector<int> results = process_sequences(sequences, max_distance);
    for (int result : results) {
        std::cout << result << " ";
    }
    return 0;
}