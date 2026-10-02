#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, int> initialize_sequence(const std::string& seq) {
    return {{"sequence", seq}, {"position", 0}};
}

int align_sequences(const std::string& seq1, const std::string& seq2) {
    auto seq1_data = initialize_sequence(seq1);
    auto seq2_data = initialize_sequence(seq2);
    while (seq1_data["position"] < seq1_data["sequence"].length() && seq2_data["position"] < seq2_data["sequence"].length()) {
        if (seq1_data["sequence"][seq1_data["position"]] == seq2_data["sequence"][seq2_data["position"]]) {
            seq1_data["position"] += 1;
            seq2_data["position"] += 1;
        } else {
            seq1_data["position"] += 1;
        }
    }
    return seq1_data["position"];
}

int main() {
    std::string sequence1 = "AGCTAGCTAGCT";
    std::string sequence2 = "AGCTAGCTAGCT";
    int result = align_sequences(sequence1, sequence2);
    std::cout << result << std::endl;
    return 0;
}