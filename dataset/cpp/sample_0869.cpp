#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class SequenceAligner {
public:
    SequenceAligner(const std::string& seq1, const std::string& seq2) : seq1(seq1), seq2(seq2) {}

    int score(char a, char b) {
        return a == b ? 1 : -1;
    }

    std::pair<std::string, std::string> align() {
        int m = seq1.size();
        int n = seq2.size();
        std::vector<std::vector<int>> matrix(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            matrix[i][0] = i;
        }
        for (int j = 1; j <= n; ++j) {
            matrix[0][j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int match = matrix[i - 1][j - 1] + score(seq1[i - 1], seq2[j - 1]);
                int delete_op = matrix[i - 1][j] + 1;
                int insert = matrix[i][j - 1] + 1;
                matrix[i][j] = std::min({match, delete_op, insert});
            }
        }
        return traceback(matrix, m, n);
    }

    std::pair<std::string, std::string> traceback(const std::vector<std::vector<int>>& matrix, int i, int j) {
        std::string align1, align2;
        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && matrix[i][j] == matrix[i - 1][j - 1] + score(seq1[i - 1], seq2[j - 1])) {
                align1 = seq1[i - 1] + align1;
                align2 = seq2[j - 1] + align2;
                i -= 1;
                j -= 1;
            } else if (i > 0 && matrix[i][j] == matrix[i - 1][j] + 1) {
                align1 = seq1[i - 1] + align1;
                align2 = '-' + align2;
                i -= 1;
            } else {
                align1 = '-' + align1;
                align2 = seq2[j - 1] + align2;
                j -= 1;
            }
        }
        return {align1, align2};
    }

private:
    std::string seq1;
    std::string seq2;
};

void main() {
    std::string seq1 = "AGGTAB";
    std::string seq2 = "GXTXAYB";
    SequenceAligner aligner(seq1, seq2);
    auto result = aligner.align();
    std::cout << "Alignment 1: " << result.first << std::endl;
    std::cout << "Alignment 2: " << result.second << std::endl;
}

int main() {
    main();
    return 0;
}