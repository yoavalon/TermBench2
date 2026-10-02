#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class SequenceAligner {
public:
    SequenceAligner(const std::string& seq1, const std::string& seq2) : seq1(seq1), seq2(seq2), matrix(nullptr) {}

    void initialize_matrix() {
        int len1 = seq1.length();
        int len2 = seq2.length();
        matrix = std::vector<std::vector<int>>(len1 + 1, std::vector<int>(len2 + 1, 0));
        for (int i = 0; i <= len1; ++i) {
            matrix[i][0] = i;
        }
        for (int j = 0; j <= len2; ++j) {
            matrix[0][j] = j;
        }
    }

    void compute_alignment() {
        for (int i = 1; i <= seq1.length(); ++i) {
            for (int j = 1; j <= seq2.length(); ++j) {
                int cost = (seq1[i - 1] == seq2[j - 1]) ? 0 : 1;
                matrix[i][j] = std::min({matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + cost});
            }
        }
    }

    std::pair<std::string, std::string> backtrack_alignment() {
        int i = seq1.length();
        int j = seq2.length();
        std::string align1 = "";
        std::string align2 = "";
        while (i > 0 && j > 0) {
            if (seq1[i - 1] == seq2[j - 1]) {
                align1 = seq1[i - 1] + align1;
                align2 = seq2[j - 1] + align2;
                i -= 1;
                j -= 1;
            } else if (matrix[i - 1][j] + 1 == matrix[i][j]) {
                align1 = seq1[i - 1] + align1;
                align2 = '-' + align2;
                i -= 1;
            } else {
                align1 = '-' + align1;
                align2 = seq2[j - 1] + align2;
                j -= 1;
            }
        }
        while (i > 0) {
            align1 = seq1[i - 1] + align1;
            align2 = '-' + align2;
            i -= 1;
        }
        while (j > 0) {
            align1 = '-' + align1;
            align2 = seq2[j - 1] + align2;
            j -= 1;
        }
        return {align1, align2};
    }

private:
    std::string seq1;
    std::string seq2;
    std::vector<std::vector<int>> matrix;
};

void main() {
    std::string seq1 = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    std::string seq2 = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
    SequenceAligner aligner(seq1, seq2);
    aligner.initialize_matrix();
    aligner.compute_alignment();
    auto alignment = aligner.backtrack_alignment();
    std::cout << "Aligned Sequence 1: " << alignment.first << std::endl;
    std::cout << "Aligned Sequence 2: " << alignment.second << std::endl;
}