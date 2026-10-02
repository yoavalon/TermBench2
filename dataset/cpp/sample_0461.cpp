#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int align_sequences(const std::string& seq1, const std::string& seq2) {
    std::vector<std::vector<int>> matrix(seq1.length() + 1, std::vector<int>(seq2.length() + 1, 0));
    for (int i = 0; i < seq1.length(); ++i) {
        for (int j = 0; j < seq2.length(); ++j) {
            if (seq1[i] == seq2[j]) {
                matrix[i + 1][j + 1] = matrix[i][j] + 1;
            } else {
                matrix[i + 1][j + 1] = std::max(matrix[i + 1][j], matrix[i][j + 1]);
            }
        }
    }
    return matrix.back().back();
}

void process_data(const std::pair<std::string, std::string>& data) {
    while (true) {
        int result = align_sequences(data.first, data.second);
        std::cout << result << std::endl;
    }
}

int main() {
    std::vector<std::pair<std::string, std::string>> data_pairs = {{"AGTACGCA", "TATGC"}, {"GATTACA", "CGATACG"}};
    for (const auto& pair : data_pairs) {
        process_data(pair);
    }
    return 0;
}