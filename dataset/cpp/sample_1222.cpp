#include <iostream>
#include <vector>
#include <algorithm>

int genomic_align(const std::string& seq1, const std::string& seq2) {
    int m = seq1.length(), n = seq2.length();
    std::vector<std::vector<int>> score(m + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int match = score[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1]);
            int delete_op = score[i - 1][j] - 1;
            int insert = score[i][j - 1] - 1;
            score[i][j] = std::max({match, delete_op, insert});
        }
    }
    return score[m][n];
}

int main() {
    std::string seq1 = "ATCG";
    std::string seq2 = "ACGT";
    std::cout << genomic_align(seq1, seq2) << std::endl;
    return 0;
}