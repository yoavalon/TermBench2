#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class SequenceAligner {
public:
    SequenceAligner(const std::string& seq1, const std::string& seq2) 
        : seq1(seq1), seq2(seq2), matrix(seq1.size() + 1, std::vector<int>(seq2.size() + 1, 0)) {}

    void fill_matrix() {
        for (size_t i = 1; i <= seq1.size(); ++i) {
            for (size_t j = 1; j <= seq2.size(); ++j) {
                if (seq1[i - 1] == seq2[j - 1]) {
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
                } else {
                    matrix[i][j] = std::max(matrix[i - 1][j], matrix[i][j - 1]);
                }
            }
        }
    }

    std::string trace_back() {
        size_t i = seq1.size();
        size_t j = seq2.size();
        std::string alignment;
        while (i > 0 && j > 0) {
            if (seq1[i - 1] == seq2[j - 1]) {
                alignment += seq1[i - 1];
                i--;
                j--;
            } else if (matrix[i - 1][j] > matrix[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        std::reverse(alignment.begin(), alignment.end());
        return alignment;
    }

private:
    std::string seq1;
    std::string seq2;
    std::vector<std::vector<int>> matrix;
};

void main() {
    std::string seq1 = "AGGTAB";
    std::string seq2 = "GXTXAYB";
    SequenceAligner aligner(seq1, seq2);
    aligner.fill_matrix();
    std::string result = aligner.trace_back();
    std::cout << "Aligned sequence: " << result << std::endl;
}