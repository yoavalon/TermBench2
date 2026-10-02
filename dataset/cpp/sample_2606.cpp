#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> generate_sequence(int n) {
    std::vector<int> sequence;
    for (int i = 0; i < n; ++i) {
        sequence.push_back(i * i + i + 1);
    }
    return sequence;
}

std::vector<std::vector<int>> align_sequences(const std::vector<int>& seq1, const std::vector<int>& seq2) {
    int len1 = seq1.size();
    int len2 = seq2.size();
    std::vector<std::vector<int>> alignment(len1 + 1, std::vector<int>(len2 + 1, 0));
    for (int i = 0; i <= len1; ++i) {
        for (int j = 0; j <= len2; ++j) {
            if (i == 0 || j == 0) {
                alignment[i][j] = 0;
            } else if (seq1[i - 1] == seq2[j - 1]) {
                alignment[i][j] = alignment[i - 1][j - 1] + 1;
            } else {
                alignment[i][j] = std::max(alignment[i - 1][j], alignment[i][j - 1]);
            }
        }
    }
    return alignment;
}

std::vector<int> find_longest_common_subsequence(const std::vector<int>& seq1, const std::vector<int>& seq2) {
    std::vector<std::vector<int>> alignment_matrix = align_sequences(seq1, seq2);
    int len1 = seq1.size();
    int len2 = seq2.size();
    std::vector<int> lcs;
    while (len1 > 0 && len2 > 0) {
        if (seq1[len1 - 1] == seq2[len2 - 1]) {
            lcs.push_back(seq1[len1 - 1]);
            len1 -= 1;
            len2 -= 1;
        } else if (alignment_matrix[len1 - 1][len2] > alignment_matrix[len1][len2 - 1]) {
            len1 -= 1;
        } else {
            len2 -= 1;
        }
    }
    std::reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    std::vector<int> seq1 = generate_sequence(10);
    std::vector<int> seq2 = generate_sequence(12);
    std::vector<int> lcs = find_longest_common_subsequence(seq1, seq2);
    for (int num : lcs) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}