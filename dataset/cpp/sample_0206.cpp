#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class SequenceAligner {
public:
    SequenceAligner(const std::string& seq1, const std::string& seq2) : seq1(seq1), seq2(seq2) {
        matrix.resize(seq1.size() + 1, std::vector<int>(seq2.size() + 1, 0));
    }

    void initialize_matrix() {
        for (size_t i = 0; i <= seq1.size(); ++i) {
            matrix[i][0] = i;
        }
        for (size_t j = 0; j <= seq2.size(); ++j) {
            matrix[0][j] = j;
        }
    }

    void compute_similarity() {
        for (size_t i = 1; i <= seq1.size(); ++i) {
            for (size_t j = 1; j <= seq2.size(); ++j) {
                int match = matrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1]);
                int delete_op = matrix[i - 1][j] + 1;
                int insert_op = matrix[i][j - 1] + 1;
                matrix[i][j] = std::min({match, delete_op, insert_op});
            }
        }
    }

    std::pair<std::string, std::string> trace_back() {
        size_t i = seq1.size(), j = seq2.size();
        std::string aligned_seq1, aligned_seq2;
        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && matrix[i][j] == matrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1])) {
                aligned_seq1 += seq1[i - 1];
                aligned_seq2 += seq2[j - 1];
                --i;
                --j;
            } else if (i > 0 && matrix[i][j] == matrix[i - 1][j] + 1) {
                aligned_seq1 += seq1[i - 1];
                aligned_seq2 += '-';
                --i;
            } else {
                aligned_seq1 += '-';
                aligned_seq2 += seq2[j - 1];
                --j;
            }
        }
        std::reverse(aligned_seq1.begin(), aligned_seq1.end());
        std::reverse(aligned_seq2.begin(), aligned_seq2.end());
        return {aligned_seq1, aligned_seq2};
    }

private:
    std::string seq1, seq2;
    std::vector<std::vector<int>> matrix;
};

int main() {
    std::string seq1 = "AGGTAB";
    std::string seq2 = "GXTXAYB";
    SequenceAligner aligner(seq1, seq2);
    aligner.initialize_matrix();
    aligner.compute_similarity();
    auto [aligned_seq1, aligned_seq2] = aligner.trace_back();
    std::cout << "Aligned Sequence 1: " << aligned_seq1 << std::endl;
    std::cout << "Aligned Sequence 2: " << aligned_seq2 << std::endl;
    return 0;
}