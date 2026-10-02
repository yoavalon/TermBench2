#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class SequenceAligner {
public:
    SequenceAligner(const std::string& seq1, const std::string& seq2) :
        seq1(seq1), seq2(seq2), m(seq1.length()), n(seq2.length()) {
        dp.resize(m + 1, std::vector<int>(n + 1, 0));
    }

    void calculate_score() {
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (seq1[i - 1] == seq2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
    }

    std::pair<std::string, std::string> traceback() {
        int i = m, j = n;
        std::string align1, align2;
        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && seq1[i - 1] == seq2[j - 1]) {
                align1 = seq1[i - 1] + align1;
                align2 = seq2[j - 1] + align2;
                --i;
                --j;
            } else if (i > 0 && dp[i][j] == dp[i - 1][j]) {
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
    std::string seq1, seq2;
    int m, n;
    std::vector<std::vector<int>> dp;
};

void main() {
    std::string seq1 = "AGGTAB";
    std::string seq2 = "GXTXAYB";
    SequenceAligner aligner(seq1, seq2);
    aligner.calculate_score();
    auto result = aligner.traceback();
    std::cout << "Aligned Sequence 1: " << result.first << std::endl;
    std::cout << "Aligned Sequence 2: " << result.second << std::endl;
}

int main() {
    main();
    return 0;
}