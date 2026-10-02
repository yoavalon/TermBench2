#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class SequenceAligner {
public:
    SequenceAligner(const std::string& seq1, const std::string& seq2) : seq1(seq1), seq2(seq2), m(seq1.length()), n(seq2.length()) {
        dp.resize(m + 1, std::vector<int>(n + 1, 0));
    }

    void compute_alignment() {
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0) {
                    dp[i][j] = j;
                } else if (j == 0) {
                    dp[i][j] = i;
                } else if (seq1[i - 1] == seq2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + std::min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
                }
            }
        }
    }

    std::pair<std::string, std::string> get_alignment() {
        std::string alignment1 = "";
        std::string alignment2 = "";
        int i = m;
        int j = n;
        while (i > 0 && j > 0) {
            if (seq1[i - 1] == seq2[j - 1]) {
                alignment1 = seq1[i - 1] + alignment1;
                alignment2 = seq2[j - 1] + alignment2;
                i -= 1;
                j -= 1;
            } else if (dp[i - 1][j] < dp[i][j - 1] && dp[i - 1][j] < dp[i - 1][j - 1]) {
                alignment1 = seq1[i - 1] + alignment1;
                alignment2 = '-' + alignment2;
                i -= 1;
            } else {
                alignment1 = '-' + alignment1;
                alignment2 = seq2[j - 1] + alignment2;
                j -= 1;
            }
        }
        while (i > 0) {
            alignment1 = seq1[i - 1] + alignment1;
            alignment2 = '-' + alignment2;
            i -= 1;
        }
        while (j > 0) {
            alignment1 = '-' + alignment1;
            alignment2 = seq2[j - 1] + alignment2;
            j -= 1;
        }
        return {alignment1, alignment2};
    }

private:
    std::string seq1;
    std::string seq2;
    int m;
    int n;
    std::vector<std::vector<int>> dp;
};

void main() {
    std::string seq1 = "AGGTAB";
    std::string seq2 = "GXTXAYB";
    SequenceAligner aligner(seq1, seq2);
    aligner.compute_alignment();
    auto [alignment1, alignment2] = aligner.get_alignment();
    std::cout << "Alignment 1: " << alignment1 << std::endl;
    std::cout << "Alignment 2: " << alignment2 << std::endl;
}