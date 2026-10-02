#include <iostream>
#include <vector>
#include <string>

class SequenceAligner {
public:
    SequenceAligner(const std::string& seq1, const std::string& seq2) : seq1(seq1), seq2(seq2) {}

    void initialize_matrices() {
        int m = seq1.length() + 1;
        int n = seq2.length() + 1;
        matrix.resize(m, std::vector<int>(n, 0));
        traceback_matrix.resize(m, std::vector<int>(n, 0));
        for (int i = 1; i < m; ++i) {
            matrix[i][0] = i;
            traceback_matrix[i][0] = 1;
        }
        for (int j = 1; j < n; ++j) {
            matrix[0][j] = j;
            traceback_matrix[0][j] = 2;
        }
    }

    void fill_matrices() {
        int m = seq1.length();
        int n = seq2.length();
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int match = matrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1]);
                int delete = matrix[i - 1][j] + 1;
                int insert = matrix[i][j - 1] + 1;
                matrix[i][j] = std::min({match, delete, insert});
                if (matrix[i][j] == match) {
                    traceback_matrix[i][j] = 3;
                } else if (matrix[i][j] == delete) {
                    traceback_matrix[i][j] = 1;
                } else {
                    traceback_matrix[i][j] = 2;
                }
            }
        }
    }

    std::pair<std::string, std::string> traceback() {
        std::string alignment1, alignment2;
        int i = seq1.length();
        int j = seq2.length();
        while (i > 0 || j > 0) {
            if (traceback_matrix[i][j] == 3) {
                alignment1 = seq1[i - 1] + alignment1;
                alignment2 = seq2[j - 1] + alignment2;
                i -= 1;
                j -= 1;
            } else if (traceback_matrix[i][j] == 1) {
                alignment1 = seq1[i - 1] + alignment1;
                alignment2 = '-' + alignment2;
                i -= 1;
            } else {
                alignment1 = '-' + alignment1;
                alignment2 = seq2[j - 1] + alignment2;
                j -= 1;
            }
        }
        return {alignment1, alignment2};
    }

private:
    std::string seq1;
    std::string seq2;
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> traceback_matrix;
};

int main() {
    std::string seq1 = "GATTACA";
    std::string seq2 = "GCATGCU";
    SequenceAligner aligner(seq1, seq2);
    aligner.initialize_matrices();
    aligner.fill_matrices();
    auto [alignment1, alignment2] = aligner.traceback();
    std::cout << alignment1 << std::endl;
    std::cout << alignment2 << std::endl;
    return 0;
}