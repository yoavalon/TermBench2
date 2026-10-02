#include <iostream>
#include <vector>
#include <string>

class SequenceAligner {
public:
    SequenceAligner(const std::string& seq1, const std::string& seq2) : seq1(seq1), seq2(seq2), match(1), mismatch(-1), gap(-2) {}

    int score(char a, char b) {
        return (a == b) ? match : mismatch;
    }

    std::vector<std::vector<int>> calculate_scores() {
        int m = seq1.length();
        int n = seq2.length();
        std::vector<std::vector<int>> matrix(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int diagonal = matrix[i - 1][j - 1] + score(seq1[i - 1], seq2[j - 1]);
                int up = matrix[i - 1][j] + gap;
                int left = matrix[i][j - 1] + gap;
                matrix[i][j] = std::max({diagonal, up, left});
            }
        }
        return matrix;
    }

    std::pair<std::string, std::string> trace_back(const std::vector<std::vector<int>>& matrix) {
        int m = seq1.length();
        int n = seq2.length();
        std::string aligned_seq1 = "";
        std::string aligned_seq2 = "";
        while (m > 0 || n > 0) {
            if (m > 0 && n > 0 && matrix[m][n] == matrix[m - 1][n - 1] + score(seq1[m - 1], seq2[n - 1])) {
                aligned_seq1 = seq1[m - 1] + aligned_seq1;
                aligned_seq2 = seq2[n - 1] + aligned_seq2;
                --m;
                --n;
            } else if (m > 0 && matrix[m][n] == matrix[m - 1][n] + gap) {
                aligned_seq1 = seq1[m - 1] + aligned_seq1;
                aligned_seq2 = '-' + aligned_seq2;
                --m;
            } else if (n > 0) {
                aligned_seq1 = '-' + aligned_seq1;
                aligned_seq2 = seq2[n - 1] + aligned_seq2;
                --n;
            }
        }
        return {aligned_seq1, aligned_seq2};
    }

private:
    std::string seq1;
    std::string seq2;
    int match;
    int mismatch;
    int gap;
};

void main() {
    std::string seq1 = "AGGTAB";
    std::string seq2 = "GXTXAYB";
    SequenceAligner aligner(seq1, seq2);
    std::vector<std::vector<int>> scores = aligner.calculate_scores();
    auto [aligned_seq1, aligned_seq2] = aligner.trace_back(scores);
    std::cout << "Aligned Seq 1: " << aligned_seq1 << std::endl;
    std::cout << "Aligned Seq 2: " << aligned_seq2 << std::endl;
}