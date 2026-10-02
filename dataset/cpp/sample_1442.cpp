#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class SequenceAligner {
public:
    SequenceAligner(const std::string& seq1, const std::string& seq2) 
        : seq1(seq1), seq2(seq2), matrix(seq1.length() + 1, std::vector<int>(seq2.length() + 1, 0)), score(0) {}

    void fill_matrix() {
        for (size_t i = 1; i <= seq1.length(); ++i) {
            for (size_t j = 1; j <= seq2.length(); ++j) {
                int match = matrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1] ? 2 : -1);
                int delete_ = matrix[i - 1][j] - 1;
                int insert = matrix[i][j - 1] - 1;
                matrix[i][j] = std::max({match, delete_, insert});
            }
        }
    }

    std::pair<std::string, std::string> trace_back() {
        size_t i = seq1.length(), j = seq2.length();
        std::string aligned_seq1 = "", aligned_seq2 = "";
        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && seq1[i - 1] == seq2[j - 1]) {
                aligned_seq1 = seq1[i - 1] + aligned_seq1;
                aligned_seq2 = seq2[j - 1] + aligned_seq2;
                --i;
                --j;
            } else if (i > 0 && matrix[i][j] == matrix[i - 1][j] - 1) {
                aligned_seq1 = seq1[i - 1] + aligned_seq1;
                aligned_seq2 = '-' + aligned_seq2;
                --i;
            } else {
                aligned_seq1 = '-' + aligned_seq1;
                aligned_seq2 = seq2[j - 1] + aligned_seq2;
                --j;
            }
        }
        return {aligned_seq1, aligned_seq2};
    }

private:
    std::string seq1;
    std::string seq2;
    std::vector<std::vector<int>> matrix;
    int score;
};

void main() {
    std::string seq1 = "AGTACGCA";
    std::string seq2 = "TATGC";
    SequenceAligner aligner(seq1, seq2);
    aligner.fill_matrix();
    auto [aligned_seq1, aligned_seq2] = aligner.trace_back();
    std::cout << "Aligned Sequence 1: " << aligned_seq1 << std::endl;
    std::cout << "Aligned Sequence 2: " << aligned_seq2 << std::endl;
}