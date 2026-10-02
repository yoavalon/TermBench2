#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class GenomicAligner {
public:
    GenomicAligner(const std::string& seq1, const std::string& seq2) : seq1(seq1), seq2(seq2) {
        matrix.resize(seq1.length() + 1, std::vector<int>(seq2.length() + 1, 0));
    }

    void _fill_matrix() {
        for (size_t i = 1; i <= seq1.length(); ++i) {
            for (size_t j = 1; j <= seq2.length(); ++j) {
                if (seq1[i - 1] == seq2[j - 1]) {
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
                } else {
                    matrix[i][j] = std::max(matrix[i - 1][j], matrix[i][j - 1]);
                }
            }
        }
    }

    std::pair<std::string, std::string> _traceback() {
        std::string alignment1;
        std::string alignment2;
        size_t i = seq1.length();
        size_t j = seq2.length();
        while (i > 0 && j > 0) {
            if (seq1[i - 1] == seq2[j - 1]) {
                alignment1 += seq1[i - 1];
                alignment2 += seq2[j - 1];
                --i;
                --j;
            } else if (matrix[i - 1][j] > matrix[i][j - 1]) {
                alignment1 += seq1[i - 1];
                alignment2 += '-';
                --i;
            } else {
                alignment1 += '-';
                alignment2 += seq2[j - 1];
                --j;
            }
        }
        std::reverse(alignment1.begin(), alignment1.end());
        std::reverse(alignment2.begin(), alignment2.end());
        return {alignment1, alignment2};
    }

    std::pair<std::string, std::string> align() {
        _fill_matrix();
        return _traceback();
    }

private:
    std::string seq1;
    std::string seq2;
    std::vector<std::vector<int>> matrix;
};

void main() {
    std::string seq1 = "AGTACGCA";
    std::string seq2 = "TGACGTCA";
    GenomicAligner aligner(seq1, seq2);
    auto result = aligner.align();
    std::cout << "Alignment 1: " << result.first << std::endl;
    std::cout << "Alignment 2: " << result.second << std::endl;
}