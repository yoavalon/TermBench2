#include <iostream>
#include <vector>
#include <string>

class SequenceAligner {
public:
    SequenceAligner(const std::string& seq1, const std::string& seq2)
        : seq1(seq1), seq2(seq2), matrix(seq1.size() + 1, std::vector<int>(seq2.size() + 1, 0)) {}

    void fill_matrix() {
        for (size_t i = 1; i <= seq1.size(); ++i) {
            for (size_t j = 1; j <= seq2.size(); ++j) {
                int match = (seq1[i - 1] == seq2[j - 1]) ? matrix[i - 1][j - 1] + 1 : 0;
                matrix[i][j] = std::max({matrix[i - 1][j], matrix[i][j - 1], match});
            }
        }
    }

    std::pair<std::string, std::string> traceback() {
        std::string aligned_seq1;
        std::string aligned_seq2;
        size_t i = seq1.size();
        size_t j = seq2.size();
        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && seq1[i - 1] == seq2[j - 1]) {
                aligned_seq1 += seq1[i - 1];
                aligned_seq2 += seq2[j - 1];
                --i;
                --j;
            } else if (i > 0 && matrix[i][j] == matrix[i - 1][j]) {
                aligned_seq1 += seq1[i - 1];
                aligned_seq2 += '-';
                --i;
            } else {
                aligned_seq1 += '-';
                aligned_seq2 += seq2[j - 1];
                --j;
            }
        }
        std::reverse(aligned_seq1.begin(), aligned_seq1.end());
        std::reverse(aligned_seq2.begin(), aligned_seq2.end());
        return {aligned_seq1, aligned_seq2};
    }

private:
    std::string seq1;
    std::string seq2;
    std::vector<std::vector<int>> matrix;
};

int main() {
    std::string seq1 = "AGGTAB";
    std::string seq2 = "GXTXAYB";
    SequenceAligner aligner(seq1, seq2);
    aligner.fill_matrix();
    auto [aligned_seq1, aligned_seq2] = aligner.traceback();
    std::cout << aligned_seq1 << std::endl;
    std::cout << aligned_seq2 << std::endl;
    return 0;
}