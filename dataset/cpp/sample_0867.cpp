#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Alignment {
public:
    Alignment(const std::string& seq1, const std::string& seq2) : seq1(seq1), seq2(seq2) {
        matrix.resize(seq1.size() + 1, std::vector<int>(seq2.size() + 1, 0));
        fill_matrix();
        traceback();
    }

    void fill_matrix() {
        for (size_t i = 1; i <= seq1.size(); ++i) {
            for (size_t j = 1; j <= seq2.size(); ++j) {
                int match = (seq1[i - 1] == seq2[j - 1]) ? matrix[i - 1][j - 1] + 1 : 0;
                int delete_val = matrix[i - 1][j] - 1;
                int insert_val = matrix[i][j - 1] - 1;
                matrix[i][j] = std::max({match, delete_val, insert_val});
            }
        }
    }

    void traceback() {
        size_t i = seq1.size(), j = seq2.size();
        align1 = "", align2 = "";
        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && matrix[i][j] == matrix[i - 1][j - 1] + 1 && seq1[i - 1] == seq2[j - 1]) {
                align1 = seq1[i - 1] + align1;
                align2 = seq2[j - 1] + align2;
                --i;
                --j;
            } else if (i > 0 && (j == 0 || matrix[i][j] == matrix[i - 1][j] - 1)) {
                align1 = seq1[i - 1] + align1;
                align2 = '-' + align2;
                --i;
            } else {
                align1 = '-' + align1;
                align2 = seq2[j - 1] + align2;
                --j;
            }
        }
        result = {align1, align2};
    }

    std::pair<std::string, std::string> result;

private:
    std::string seq1, seq2;
    std::vector<std::vector<int>> matrix;
    std::string align1, align2;
};

void main() {
    std::string seq1 = "AGTACGCA";
    std::string seq2 = "GTTAC";
    Alignment alignment(seq1, seq2);
    std::cout << "Sequence 1: " << alignment.result.first << std::endl;
    std::cout << "Sequence 2: " << alignment.result.second << std::endl;
}