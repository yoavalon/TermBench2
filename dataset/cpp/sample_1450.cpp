#include <iostream>
#include <vector>
#include <string>

class SequenceAligner {
public:
    SequenceAligner(const std::string& seq1, const std::string& seq2) : seq1(seq1), seq2(seq2), matrix(seq1.size() + 1, std::vector<int>(seq2.size() + 1, 0)) {}

    void build_matrix() {
        for (size_t i = 0; i <= seq1.size(); ++i) {
            for (size_t j = 0; j <= seq2.size(); ++j) {
                if (i == 0 || j == 0) {
                    matrix[i][j] = 0;
                } else if (seq1[i - 1] == seq2[j - 1]) {
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
                } else {
                    matrix[i][j] = std::max(matrix[i - 1][j], matrix[i][j - 1]);
                }
            }
        }
    }

    std::pair<std::string, std::string> trace_back() {
        size_t i = seq1.size();
        size_t j = seq2.size();
        std::string align1, align2;
        while (i > 0 && j > 0) {
            if (seq1[i - 1] == seq2[j - 1]) {
                align1 = seq1[i - 1] + align1;
                align2 = seq2[j - 1] + align2;
                --i;
                --j;
            } else if (matrix[i - 1][j] > matrix[i][j - 1]) {
                align1 = seq1[i - 1] + align1;
                align2 = '-' + align2;
                --i;
            } else {
                align1 = '-' + align1;
                align2 = seq2[j - 1] + align2;
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
    std::string seq1, seq2;
    std::vector<std::vector<int>> matrix;
};

void main() {
    std::string seq1 = "AGGTAB";
    std::string seq2 = "GXTXAYB";
    SequenceAligner aligner(seq1, seq2);
    aligner.build_matrix();
    auto [aligned_seq1, aligned_seq2] = aligner.trace_back();
    std::cout << "Aligned Sequence 1: " << aligned_seq1 << std::endl;
    std::cout << "Aligned Sequence 2: " << aligned_seq2 << std::endl;
}

int main() {
    main();
    return 0;
}