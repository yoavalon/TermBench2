#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class SequenceAligner {
public:
    SequenceAligner(const std::string& seq1, const std::string& seq2) : seq1(seq1), seq2(seq2) {
        matrix.resize(seq1.size() + 1, std::vector<int>(seq2.size() + 1, 0));
    }

    void initialize_matrix() {
        for (int i = 0; i <= seq1.size(); ++i) {
            matrix[i][0] = i;
        }
        for (int j = 0; j <= seq2.size(); ++j) {
            matrix[0][j] = j;
        }
    }

    void fill_matrix() {
        for (int i = 1; i <= seq1.size(); ++i) {
            for (int j = 1; j <= seq2.size(); ++j) {
                int cost = (seq1[i - 1] == seq2[j - 1]) ? 0 : 1;
                matrix[i][j] = std::min({matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + cost});
            }
        }
    }

    std::pair<std::string, std::string> trace_back() {
        int i = seq1.size(), j = seq2.size();
        std::string align1, align2;
        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && seq1[i - 1] == seq2[j - 1]) {
                align1 = seq1[i - 1] + align1;
                align2 = seq2[j - 1] + align2;
                --i;
                --j;
            } else if (i > 0 && matrix[i][j] == matrix[i - 1][j] + 1) {
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
    std::string seq1;
    std::string seq2;
    std::vector<std::vector<int>> matrix;
};

void main() {
    std::string seq1 = "AGGTAB";
    std::string seq2 = "GXTXAYB";
    SequenceAligner aligner(seq1, seq2);
    aligner.initialize_matrix();
    aligner.fill_matrix();
    auto aligned_sequences = aligner.trace_back();
    std::cout << "Aligned Sequence 1: " << aligned_sequences.first << std::endl;
    std::cout << "Aligned Sequence 2: " << aligned_sequences.second << std::endl;
}