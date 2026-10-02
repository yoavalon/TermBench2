#include <iostream>
#include <vector>
#include <string>

class SequenceAligner {
public:
    SequenceAligner(const std::string& seq1, const std::string& seq2) 
        : seq1(seq1), seq2(seq2), matrix(seq1.size() + 1, std::vector<int>(seq2.size() + 1, 0)), 
          traceback(seq1.size() + 1, std::vector<int>(seq2.size() + 1, 0)) {}

    void fill_matrix() {
        for (size_t i = 1; i <= seq1.size(); ++i) {
            for (size_t j = 1; j <= seq2.size(); ++j) {
                int match = (seq1[i - 1] == seq2[j - 1]) ? matrix[i - 1][j - 1] + 1 : matrix[i - 1][j - 1] - 1;
                int delete = matrix[i - 1][j] - 1;
                int insert = matrix[i][j - 1] - 1;
                matrix[i][j] = std::max({match, delete, insert});
                if (matrix[i][j] == match) {
                    traceback[i][j] = 1;
                } else if (matrix[i][j] == delete) {
                    traceback[i][j] = 2;
                } else {
                    traceback[i][j] = 3;
                }
            }
        }
    }

    std::pair<std::string, std::string> trace_alignment() {
        size_t i = seq1.size(), j = seq2.size();
        std::string aligned_seq1, aligned_seq2;
        while (i > 0 && j > 0) {
            if (traceback[i][j] == 1) {
                aligned_seq1 = seq1[i - 1] + aligned_seq1;
                aligned_seq2 = seq2[j - 1] + aligned_seq2;
                i -= 1;
                j -= 1;
            } else if (traceback[i][j] == 2) {
                aligned_seq1 = seq1[i - 1] + aligned_seq1;
                aligned_seq2 = '-' + aligned_seq2;
                i -= 1;
            } else {
                aligned_seq1 = '-' + aligned_seq1;
                aligned_seq2 = seq2[j - 1] + aligned_seq2;
                j -= 1;
            }
        }
        while (i > 0) {
            aligned_seq1 = seq1[i - 1] + aligned_seq1;
            aligned_seq2 = '-' + aligned_seq2;
            i -= 1;
        }
        while (j > 0) {
            aligned_seq1 = '-' + aligned_seq1;
            aligned_seq2 = seq2[j - 1] + aligned_seq2;
            j -= 1;
        }
        return {aligned_seq1, aligned_seq2};
    }

private:
    std::string seq1, seq2;
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> traceback;
};

void main() {
    std::string seq1 = "AGCTG";
    std::string seq2 = "ACGT";
    SequenceAligner aligner(seq1, seq2);
    aligner.fill_matrix();
    auto [aligned_seq1, aligned_seq2] = aligner.trace_alignment();
    std::cout << "Aligned Sequence 1: " << aligned_seq1 << std::endl;
    std::cout << "Aligned Sequence 2: " << aligned_seq2 << std::endl;
}

int main() {
    main();
    return 0;
}