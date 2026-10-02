#include <iostream>
#include <vector>
#include <string>

class SequenceAligner {
public:
    SequenceAligner(const std::string& seq1, const std::string& seq2)
        : seq1(seq1), seq2(seq2), score_matrix(seq1.size() + 1, std::vector<int>(seq2.size() + 1, 0)),
          trace_matrix(seq1.size() + 1, std::vector<int>(seq2.size() + 1, 0)) {}

    void fill_matrices() {
        for (size_t i = 1; i <= seq1.size(); ++i) {
            for (size_t j = 1; j <= seq2.size(); ++j) {
                int match = score_matrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1]);
                int delete_op = score_matrix[i - 1][j] - 1;
                int insert_op = score_matrix[i][j - 1] - 1;
                score_matrix[i][j] = std::max({match, delete_op, insert_op});
                if (score_matrix[i][j] == match) {
                    trace_matrix[i][j] = 1;
                } else if (score_matrix[i][j] == delete_op) {
                    trace_matrix[i][j] = 2;
                } else {
                    trace_matrix[i][j] = 3;
                }
            }
        }
    }

    std::pair<std::string, std::string> trace_back() {
        size_t i = seq1.size();
        size_t j = seq2.size();
        std::string aligned_seq1;
        std::string aligned_seq2;
        while (i > 0 && j > 0) {
            if (trace_matrix[i][j] == 1) {
                aligned_seq1 += seq1[i - 1];
                aligned_seq2 += seq2[j - 1];
                --i;
                --j;
            } else if (trace_matrix[i][j] == 2) {
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
    std::string seq1;
    std::string seq2;
    std::vector<std::vector<int>> score_matrix;
    std::vector<std::vector<int>> trace_matrix;
};

void main() {
    std::string seq1 = "AGGTAB";
    std::string seq2 = "GXTXAYB";
    SequenceAligner aligner(seq1, seq2);
    aligner.fill_matrices();
    auto [aligned_seq1, aligned_seq2] = aligner.trace_back();
    std::cout << "Aligned Sequence 1: " << aligned_seq1 << std::endl;
    std::cout << "Aligned Sequence 2: " << aligned_seq2 << std::endl;
}