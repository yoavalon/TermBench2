#include <iostream>
#include <vector>
#include <string>

class GenomicAligner {
public:
    GenomicAligner(const std::string& seq1, const std::string& seq2) 
        : seq1(seq1), seq2(seq2), matrix(seq1.length() + 1, std::vector<int>(seq2.length() + 1, 0)) {}

    int _score(char a, char b) {
        return a == b ? 1 : -1;
    }

    void _fill_matrix() {
        for (size_t i = 1; i <= seq1.length(); ++i) {
            for (size_t j = 1; j <= seq2.length(); ++j) {
                int match = matrix[i - 1][j - 1] + _score(seq1[i - 1], seq2[j - 1]);
                int delete_op = matrix[i - 1][j] - 1;
                int insert_op = matrix[i][j - 1] - 1;
                matrix[i][j] = std::max({match, delete_op, insert_op});
            }
        }
    }

    std::pair<std::string, std::string> _traceback(size_t i, size_t j) {
        if (i == 0 || j == 0) {
            return {"", ""};
        }
        if (matrix[i][j] == matrix[i - 1][j - 1] + _score(seq1[i - 1], seq2[j - 1])) {
            auto [s1, s2] = _traceback(i - 1, j - 1);
            return {seq1[i - 1] + s1, seq2[j - 1] + s2};
        } else if (matrix[i][j] == matrix[i - 1][j] - 1) {
            auto [s1, s2] = _traceback(i - 1, j);
            return {seq1[i - 1] + s1, "-" + s2};
        } else {
            auto [s1, s2] = _traceback(i, j - 1);
            return {"-" + s1, seq2[j - 1] + s2};
        }
    }

    std::pair<std::string, std::string> align() {
        _fill_matrix();
        return _traceback(seq1.length(), seq2.length());
    }

private:
    std::string seq1;
    std::string seq2;
    std::vector<std::vector<int>> matrix;
};

void main() {
    std::string seq1 = "ACGTGACGTG";
    std::string seq2 = "GTCGTGTCG";
    GenomicAligner aligner(seq1, seq2);
    auto [aligned_seq1, aligned_seq2] = aligner.align();
    std::cout << "Aligned Sequence 1: " << aligned_seq1 << std::endl;
    std::cout << "Aligned Sequence 2: " << aligned_seq2 << std::endl;
}