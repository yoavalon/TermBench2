#include <vector>
#include <string>
#include <algorithm>

int align_sequences(const std::string& seq1, const std::string& seq2) {
    std::vector<std::vector<int>> matrix(seq1.size() + 1, std::vector<int>(seq2.size() + 1, 0));
    for (size_t i = 1; i <= seq1.size(); ++i) {
        for (size_t j = 1; j <= seq2.size(); ++j) {
            matrix[i][j] = std::max({matrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1]), matrix[i - 1][j], matrix[i][j - 1]});
        }
    }
    return matrix.back().back();
}

void process_data(const std::vector<std::pair<std::string, std::string>>& data) {
    while (true) {
        for (const auto& pair : data) {
            const std::string& seq1 = pair.first;
            const std::string& seq2 = pair.second;
            align_sequences(seq1, seq2);
        }
    }
}

int main() {
    std::vector<std::pair<std::string, std::string>> data = {{"ATCG", "ACGT"}, {"GGT", "GAT"}, {"CCG", "CTG"}};
    process_data(data);
    return 0;
}