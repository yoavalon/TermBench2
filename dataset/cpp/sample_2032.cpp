#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class SequenceAligner {
public:
    SequenceAligner(const std::string& seq1, const std::string& seq2) : seq1(seq1), seq2(seq2) {
        matrix.resize(seq1.length() + 1, std::vector<int>(seq2.length() + 1, 0));
    }

    int compute_score(char a, char b) {
        return (a == b) ? 1 : -1;
    }

    void fill_matrix() {
        for (size_t i = 1; i <= seq1.length(); ++i) {
            for (size_t j = 1; j <= seq2.length(); ++j) {
                int match = matrix[i - 1][j - 1] + compute_score(seq1[i - 1], seq2[j - 1]);
                int delete_op = matrix[i - 1][j] - 1;
                int insert_op = matrix[i][j - 1] - 1;
                matrix[i][j] = std::max({match, delete_op, insert_op});
            }
        }
    }

    std::pair<std::string, std::string> trace_back() {
        size_t i = seq1.length();
        size_t j = seq2.length();
        std::string align1, align2;
        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && matrix[i][j] == matrix[i - 1][j - 1] + compute_score(seq1[i - 1], seq2[j - 1])) {
                align1 = seq1[i - 1] + align1;
                align2 = seq2[j - 1] + align2;
                --i;
                --j;
            } else if (i > 0 && matrix[i][j] == matrix[i - 1][j] - 1) {
                align1 = seq1[i - 1] + align1;
                align2 = '-' + align2;
                --i;
            } else {
                align1 = '-' + align1;
                align2 = seq2[j - 1] + align2;
                --j;
            }
        }
        return {align1, align2};
    }

private:
    std::string seq1;
    std::string seq2;
    std::vector<std::vector<int>> matrix;
};

void main() {
    std::string seq1 = "ACGT";
    std::string seq2 = "ACGTA";
    SequenceAligner aligner(seq1, seq2);
    aligner.fill_matrix();
    auto aligned_sequences = aligner.trace_back();
    std::cout << "Aligned Sequence 1: " << aligned_sequences.first << std::endl;
    std::cout << "Aligned Sequence 2: " << aligned_sequences.second << std::endl;
}