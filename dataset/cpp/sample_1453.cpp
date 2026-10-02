#include <iostream>
#include <vector>
#include <string>

class SequenceAligner {
public:
    SequenceAligner(const std::string& seq1, const std::string& seq2) : seq1(seq1), seq2(seq2) {
        matrix.resize(seq1.length() + 1, std::vector<int>(seq2.length() + 1, 0));
        traceback.resize(seq1.length() + 1, std::vector<int>(seq2.length() + 1, 0));
    }

    void fill_matrix() {
        for (size_t i = 1; i <= seq1.length(); ++i) {
            for (size_t j = 1; j <= seq2.length(); ++j) {
                int match = matrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1]);
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

    std::pair<std::string, std::string> align_sequences() {
        std::string aligned_seq1 = "", aligned_seq2 = "";
        size_t i = seq1.length(), j = seq2.length();
        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && traceback[i][j] == 1) {
                aligned_seq1 = seq1[i - 1] + aligned_seq1;
                aligned_seq2 = seq2[j - 1] + aligned_seq2;
                i -= 1;
                j -= 1;
            } else if (i > 0 && (j == 0 || traceback[i][j] == 2)) {
                aligned_seq1 = seq1[i - 1] + aligned_seq1;
                aligned_seq2 = '-' + aligned_seq2;
                i -= 1;
            } else {
                aligned_seq1 = '-' + aligned_seq1;
                aligned_seq2 = seq2[j - 1] + aligned_seq2;
                j -= 1;
            }
        }
        return {aligned_seq1, aligned_seq2};
    }

private:
    std::string seq1, seq2;
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> traceback;
};

void main() {
    std::string seq1 = "GATTACA";
    std::string seq2 = "CGATTACG";
    SequenceAligner aligner(seq1, seq2);
    aligner.fill_matrix();
    auto [aligned_seq1, aligned_seq2] = aligner.align_sequences();
    std::cout << aligned_seq1 << std::endl;
    std::cout << aligned_seq2 << std::endl;
}