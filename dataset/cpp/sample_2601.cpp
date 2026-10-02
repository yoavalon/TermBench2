#include <iostream>
#include <vector>
#include <string>

class SequenceAligner {
public:
    SequenceAligner(const std::string& seq1, const std::string& seq2) : seq1(seq1), seq2(seq2) {
        matrix.resize(seq1.length() + 1, std::vector<int>(seq2.length() + 1, 0));
    }

    void calculate_matrix() {
        for (size_t i = 1; i <= seq1.length(); ++i) {
            for (size_t j = 1; j <= seq2.length(); ++j) {
                int match = matrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1] ? 1 : -1);
                int delete_op = matrix[i - 1][j] - 1;
                int insert_op = matrix[i][j - 1] - 1;
                matrix[i][j] = std::max({match, delete_op, insert_op});
            }
        }
    }

    std::pair<std::string, std::string> traceback() {
        size_t i = seq1.length(), j = seq2.length();
        std::string align1, align2;
        while (i > 0 && j > 0) {
            if (matrix[i][j] == matrix[i - 1][j] - 1) {
                align1 = seq1[i - 1] + align1;
                align2 = '-' + align2;
                --i;
            } else if (matrix[i][j] == matrix[i][j - 1] - 1) {
                align1 = '-' + align1;
                align2 = seq2[j - 1] + align2;
                --j;
            } else {
                align1 = seq1[i - 1] + align1;
                align2 = seq2[j - 1] + align2;
                --i;
                --j;
            }
        }
        while (i > 0) {
            align1 = seq1[i - 1] + align1;
            align2 = '-' + align2;
            --i;
        }
        while (j > 0) {
            align1 = '-' + align1;
            align2 = seq2[j - 1] + align2;
            --j;
        }
        return {align1, align2};
    }

private:
    std::string seq1;
    std::string seq2;
    std::vector<std::vector<int>> matrix;
};

void main() {
    std::string seq1 = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    std::string seq2 = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
    SequenceAligner aligner(seq1, seq2);
    aligner.calculate_matrix();
    auto [aligned_seq1, aligned_seq2] = aligner.traceback();
    std::cout << "Aligned Sequence 1: " << aligned_seq1 << std::endl;
    std::cout << "Aligned Sequence 2: " << aligned_seq2 << std::endl;
}

int main() {
    main();
    return 0;
}