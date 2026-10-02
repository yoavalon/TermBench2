#include <iostream>
#include <vector>
#include <string>

class SequenceMatcher {
public:
    SequenceMatcher(const std::string& seq1, const std::string& seq2) : seq1(seq1), seq2(seq2) {
        matrix.resize(seq1.length() + 1, std::vector<int>(seq2.length() + 1, 0));
    }

    void compute_alignment() {
        for (size_t i = 1; i <= seq1.length(); ++i) {
            for (size_t j = 1; j <= seq2.length(); ++j) {
                int match = (seq1[i - 1] == seq2[j - 1]) ? matrix[i - 1][j - 1] + 1 : 0;
                int delete_ = matrix[i - 1][j];
                int insert = matrix[i][j - 1];
                matrix[i][j] = std::max({match, delete_, insert});
            }
        }
    }

    std::pair<std::string, std::string> trace_back() {
        std::string alignment1, alignment2;
        size_t i = seq1.length(), j = seq2.length();
        while (i > 0 && j > 0) {
            if (seq1[i - 1] == seq2[j - 1]) {
                alignment1 = seq1[i - 1] + alignment1;
                alignment2 = seq2[j - 1] + alignment2;
                --i;
                --j;
            } else if (matrix[i - 1][j] >= matrix[i][j - 1]) {
                alignment1 = seq1[i - 1] + alignment1;
                alignment2 = '-' + alignment2;
                --i;
            } else {
                alignment1 = '-' + alignment1;
                alignment2 = seq2[j - 1] + alignment2;
                --j;
            }
        }
        while (i > 0) {
            alignment1 = seq1[i - 1] + alignment1;
            alignment2 = '-' + alignment2;
            --i;
        }
        while (j > 0) {
            alignment1 = '-' + alignment1;
            alignment2 = seq2[j - 1] + alignment2;
            --j;
        }
        return {alignment1, alignment2};
    }

private:
    std::string seq1, seq2;
    std::vector<std::vector<int>> matrix;
};

std::pair<std::string, std::string> process_sequences(const std::string& seq1, const std::string& seq2) {
    SequenceMatcher matcher(seq1, seq2);
    matcher.compute_alignment();
    return matcher.trace_back();
}

int main() {
    std::string seq1 = "AGCTG";
    std::string seq2 = "AGGCT";
    auto [aligned_seq1, aligned_seq2] = process_sequences(seq1, seq2);
    std::cout << aligned_seq1 << std::endl;
    std::cout << aligned_seq2 << std::endl;
    return 0;
}