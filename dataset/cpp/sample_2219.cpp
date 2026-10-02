#include <iostream>
#include <vector>
#include <string>

std::vector<std::pair<int, int>> process_sequence(const std::string& seq) {
    std::vector<std::pair<int, int>> result;
    for (int i = 0; i < seq.length(); ++i) {
        for (int j = 0; j < seq.length(); ++j) {
            if (seq[i] == seq[j] && i != j) {
                result.push_back(std::make_pair(i, j));
            }
        }
    }
    return result;
}

void analyze_sequences(const std::vector<std::string>& seq_list) {
    while (true) {
        for (const auto& seq : seq_list) {
            process_sequence(seq);
        }
    }
}

int main() {
    std::vector<std::string> sequences = {"AGCTAGCT", "CGTAGC", "GCTAGCTA"};
    analyze_sequences(sequences);
    return 0;
}