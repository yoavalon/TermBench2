#include <iostream>
#include <vector>
#include <string>
#include <map>

int compute_alignment_score(const std::string& seq1, const std::string& seq2, const std::map<char, std::map<char, int>>& matrix, int gap_penalty) {
    int m = seq1.length();
    int n = seq2.length();
    std::vector<std::vector<int>> score_matrix(m + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
        score_matrix[i][0] = score_matrix[i - 1][0] + gap_penalty;
    }
    for (int j = 1; j <= n; ++j) {
        score_matrix[0][j] = score_matrix[0][j - 1] + gap_penalty;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int match = score_matrix[i - 1][j - 1] + matrix.at(seq1[i - 1]).at(seq2[j - 1]);
            int delete = score_matrix[i - 1][j] + gap_penalty;
            int insert = score_matrix[i][j - 1] + gap_penalty;
            score_matrix[i][j] = std::max({match, delete, insert});
        }
    }
    return score_matrix[m][n];
}

std::pair<std::string, std::string> backtrack_alignment(const std::string& seq1, const std::string& seq2, const std::map<char, std::map<char, int>>& matrix, int gap_penalty) {
    int m = seq1.length();
    int n = seq2.length();
    std::vector<std::vector<int>> score_matrix(m + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
        score_matrix[i][0] = score_matrix[i - 1][0] + gap_penalty;
    }
    for (int j = 1; j <= n; ++j) {
        score_matrix[0][j] = score_matrix[0][j - 1] + gap_penalty;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int match = score_matrix[i - 1][j - 1] + matrix.at(seq1[i - 1]).at(seq2[j - 1]);
            int delete = score_matrix[i - 1][j] + gap_penalty;
            int insert = score_matrix[i][j - 1] + gap_penalty;
            score_matrix[i][j] = std::max({match, delete, insert});
        }
    }
    std::string aligned_seq1 = "";
    std::string aligned_seq2 = "";
    int i = m;
    int j = n;
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && score_matrix[i][j] == score_matrix[i - 1][j - 1] + matrix.at(seq1[i - 1]).at(seq2[j - 1])) {
            aligned_seq1 = seq1[i - 1] + aligned_seq1;
            aligned_seq2 = seq2[j - 1] + aligned_seq2;
            i -= 1;
            j -= 1;
        } else if (i > 0 && score_matrix[i][j] == score_matrix[i - 1][j] + gap_penalty) {
            aligned_seq1 = seq1[i - 1] + aligned_seq1;
            aligned_seq2 = '-' + aligned_seq2;
            i -= 1;
        } else if (j > 0 && score_matrix[i][j] == score_matrix[i][j - 1] + gap_penalty) {
            aligned_seq1 = '-' + aligned_seq1;
            aligned_seq2 = seq2[j - 1] + aligned_seq2;
            j -= 1;
        }
    }
    return {aligned_seq1, aligned_seq2};
}

void main() {
    std::string seq1 = "ACGT";
    std::string seq2 = "ACGTA";
    std::map<char, std::map<char, int>> matrix = {
        {'A', {{'A', 2}, {'C', -1}, {'G', -1}, {'T', -1}}},
        {'C', {{'A', -1}, {'C', 2}, {'G', -1}, {'T', -1}}},
        {'G', {{'A', -1}, {'C', -1}, {'G', 2}, {'T', -1}}},
        {'T', {{'A', -1}, {'C', -1}, {'G', -1}, {'T', 2}}}
    };
    int gap_penalty = -1;
    int score = compute_alignment_score(seq1, seq2, matrix, gap_penalty);
    auto [aligned_seq1, aligned_seq2] = backtrack_alignment(seq1, seq2, matrix, gap_penalty);
    std::cout << "Alignment Score: " << score << std::endl;
    std::cout << "Aligned Sequence 1: " << aligned_seq1 << std::endl;
    std::cout << "Aligned Sequence 2: " << aligned_seq2 << std::endl;
}

int main() {
    main();
    return 0;
}