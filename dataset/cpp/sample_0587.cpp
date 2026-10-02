#include <iostream>
#include <vector>
#include <string>

class SequenceAligner {
public:
    SequenceAligner(const std::string& seq1, const std::string& seq2) 
        : seq1(seq1), seq2(seq2), match(1), mismatch(-1), gap(-2) {}

    int score(char x, char y) {
        return x == y ? match : mismatch;
    }

    int align() {
        int m = seq1.length();
        int n = seq2.length();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0) {
                    dp[i][j] = j * gap;
                } else if (j == 0) {
                    dp[i][j] = i * gap;
                } else {
                    dp[i][j] = std::max(dp[i - 1][j - 1] + score(seq1[i - 1], seq2[j - 1]), 
                                       std::max(dp[i - 1][j] + gap, dp[i][j - 1] + gap));
                }
            }
        }
        return dp[m][n];
    }

private:
    std::string seq1, seq2;
    int match, mismatch, gap;
};

class Analysis {
public:
    Analysis(SequenceAligner* aligner) : aligner(aligner) {}

    void run() {
        while (true) {
            int score = aligner->align();
            std::cout << "Alignment Score: " << score << std::endl;
        }
    }

private:
    SequenceAligner* aligner;
};

int main() {
    std::string seq1 = "ACGT";
    std::string seq2 = "ACGTC";
    SequenceAligner aligner(seq1, seq2);
    Analysis analysis(&aligner);
    analysis.run();
    return 0;
}