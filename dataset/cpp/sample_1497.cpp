#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class SequenceAligner {
public:
    SequenceAligner(const std::string& seq1, const std::string& seq2) : seq1(seq1), seq2(seq2), matrix(seq1.size() + 1, std::vector<int>(seq2.size() + 1, 0)) {}

    void create_matrix() {}

    void fill_matrix() {
        for (size_t i = 1; i <= seq1.size(); ++i) {
            for (size_t j = 1; j <= seq2.size(); ++j) {
                int match = matrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1]);
                int delete_op = matrix[i - 1][j] - 1;
                int insert = matrix[i][j - 1] - 1;
                matrix[i][j] = std::max({match, delete_op, insert});
            }
        }
    }

    std::pair<std::string, std::string> trace_back() {
        size_t i = seq1.size();
        size_t j = seq2.size();
        std::string align1, align2;
        while (i > 0 && j > 0) {
            if (seq1[i - 1] == seq2[j - 1]) {
                align1 += seq1[i - 1];
                align2 += seq2[j - 1];
                --i;
                --j;
            } else if (matrix[i - 1][j] > matrix[i][j - 1]) {
                align1 += seq1[i - 1];
                align2 += '-';
                --i;
            } else {
                align1 += '-';
                align2 += seq2[j - 1];
                --j;
            }
        }
        while (i > 0) {
            align1 += seq1[i - 1];
            align2 += '-';
            --i;
        }
        while (j > 0) {
            align1 += '-';
            align2 += seq2[j - 1];
            --j;
        }
        std::reverse(align1.begin(), align1.end());
        std::reverse(align2.begin(), align2.end());
        return {align1, align2};
    }

private:
    std::string seq1;
    std::string seq2;
    std::vector<std::vector<int>> matrix;
};

int main() {
    std::string seq1 = "GATTACA";
    std::string seq2 = "GCATGCU";
    SequenceAligner aligner(seq1, seq2);
    aligner.create_matrix();
    aligner.fill_matrix();
    auto [aligned_seq1, aligned_seq2] = aligner.trace_back();
    std::cout << aligned_seq1 << std::endl;
    std::cout << aligned_seq2 << std::endl;
    return 0;
}