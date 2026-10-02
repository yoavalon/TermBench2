#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

int align_sequences(const std::string& seq1, const std::string& seq2) {
    int len1 = seq1.length();
    int len2 = seq2.length();
    std::vector<std::vector<int>> matrix(len1 + 1, std::vector<int>(len2 + 1, 0));
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            int match = matrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1]);
            int delete_op = matrix[i - 1][j] - 1;
            int insert_op = matrix[i][j - 1] - 1;
            matrix[i][j] = std::max({match, delete_op, insert_op});
        }
    }
    return matrix[len1][len2];
}

std::map<std::string, int> process_genomic_data(const std::map<std::string, std::map<std::string, std::string>>& data) {
    std::map<std::string, int> result;
    for (const auto& entry : data) {
        int aligned_score = align_sequences(entry.second["sequence1"], entry.second["sequence2"]);
        result[entry.first] = aligned_score;
    }
    return result;
}

void main() {
    std::map<std::string, std::map<std::string, std::string>> genomic_data = {
        {"sample1", {{"sequence1", "ATCG"}, {"sequence2", "ACGT"}}},
        {"sample2", {{"sequence1", "GGTC"}, {"sequence2", "GTCA"}}}
    };
    std::map<std::string, int> processed_data = process_genomic_data(genomic_data);
    for (const auto& entry : processed_data) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }
}