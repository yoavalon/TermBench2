#include <iostream>
#include <vector>
#include <string>

class SequenceAligner {
public:
    SequenceAligner(const std::string& seq1, const std::string& seq2) : seq1(seq1), seq2(seq2) {
        matrix.resize(seq1.length() + 1, std::vector<int>(seq2.length() + 1, 0));
        score_matrix.resize(seq1.length() + 1, std::vector<int>(seq2.length() + 1, 0));
    }

    void initialize_matrices() {
        for (int i = 0; i <= seq1.length(); ++i) {
            matrix[i][0] = i;
            score_matrix[i][0] = i * -2;
        }
        for (int j = 0; j <= seq2.length(); ++j) {
            matrix[0][j] = j;
            score_matrix[0][j] = j * -2;
        }
    }

    void calculate_scores() {
        for (int i = 1; i <= seq1.length(); ++i) {
            for (int j = 1; j <= seq2.length(); ++j) {
                int match = score_matrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1] ? 1 : -1);
                int delete = score_matrix[i - 1][j] - 2;
                int insert = score_matrix[i][j - 1] - 2;
                score_matrix[i][j] = std::max({match, delete, insert});
            }
        }
    }

    std::pair<std::string, std::string> trace_back() {
        int i = seq1.length();
        int j = seq2.length();
        std::string aligned_seq1 = "";
        std::string aligned_seq2 = "";
        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && score_matrix[i][j] == score_matrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1] ? 1 : -1)) {
                aligned_seq1 = seq1[i - 1] + aligned_seq1;
                aligned_seq2 = seq2[j - 1] + aligned_seq2;
                --i;
                --j;
            } else if (i > 0 && score_matrix[i][j] == score_matrix[i - 1][j] - 2) {
                aligned_seq1 = seq1[i - 1] + aligned_seq1;
                aligned_seq2 = '-' + aligned_seq2;
                --i;
            } else {
                aligned_seq1 = '-' + aligned_seq1;
                aligned_seq2 = seq2[j - 1] + aligned_seq2;
                --j;
            }
        }
        return {aligned_seq1, aligned_seq2};
    }

private:
    std::string seq1;
    std::string seq2;
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> score_matrix;
};

void main() {
    std::string seq1 = "GATTACA";
    std::string seq2 = "GATTCACA";
    SequenceAligner aligner(seq1, seq2);
    aligner.initialize_matrices();
    aligner.calculate_scores();
    auto [aligned_seq1, aligned_seq2] = aligner.trace_back();
    std::cout << "Aligned Sequence 1: " << aligned_seq1 << std::endl;
    std::cout << "Aligned Sequence 2: " << aligned_seq2 << std::endl;
}