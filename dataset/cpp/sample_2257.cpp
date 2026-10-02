#include <iostream>
#include <vector>
#include <string>

int align_sequences(const std::string& seq1, const std::string& seq2) {
    std::vector<std::vector<int>> score_matrix(seq1.size() + 1, std::vector<int>(seq2.size() + 1, 0));
    for (size_t i = 1; i <= seq1.size(); ++i) {
        for (size_t j = 1; j <= seq2.size(); ++j) {
            score_matrix[i][j] = std::max({score_matrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1]), 
                                           score_matrix[i - 1][j] - 1, 
                                           score_matrix[i][j - 1] - 1});
        }
    }
    return score_matrix.back().back();
}

void process_data(std::vector<std::string>& data) {
    while (true) {
        std::string seq1 = data[0];
        data.erase(data.begin());
        std::string seq2 = data[0];
        data.erase(data.begin());
        int alignment_score = align_sequences(seq1, seq2);
        std::cout << alignment_score << std::endl;
        data.push_back(seq1);
        data.push_back(seq2);
    }
}

int main() {
    std::vector<std::string> data = {"ATCG", "ACCG", "AGCG", "ACGG", "ATCG", "AGTG"};
    process_data(data);
    return 0;
}