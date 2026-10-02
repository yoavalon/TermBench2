#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class SequenceAligner {
public:
    SequenceAligner(const std::string& seq1, const std::string& seq2) : seq1(seq1), seq2(seq2), max_score(0) {
        initialize_matrices();
    }

    void initialize_matrices() {
        int len1 = seq1.size();
        int len2 = seq2.size();
        score_matrix.resize(len1 + 1, std::vector<int>(len2 + 1, 0));
        traceback_matrix.resize(len1 + 1, std::vector<int>(len2 + 1, 0));
    }

    void fill_matrices() {
        for (int i = 1; i <= seq1.size(); ++i) {
            for (int j = 1; j <= seq2.size(); ++j) {
                int match = score_matrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1] ? 1 : -1);
                int delete_op = score_matrix[i - 1][j] - 1;
                int insert_op = score_matrix[i][j - 1] - 1;
                score_matrix[i][j] = std::max({match, delete_op, insert_op});
                if (score_matrix[i][j] == match) {
                    traceback_matrix[i][j] = 1;
                } else if (score_matrix[i][j] == delete_op) {
                    traceback_matrix[i][j] = 2;
                } else {
                    traceback_matrix[i][j] = 3;
                }
                if (score_matrix[i][j] > max_score) {
                    max_score = score_matrix[i][j];
                    max_position = {i, j};
                }
            }
        }
    }

    std::pair<std::string, std::string> backtrack() {
        std::string aligned_seq1;
        std::string aligned_seq2;
        int i = max_position.first;
        int j = max_position.second;
        while (i > 0 && j > 0) {
            if (traceback_matrix[i][j] == 1) {
                aligned_seq1 += seq1[i - 1];
                aligned_seq2 += seq2[j - 1];
                --i;
                --j;
            } else if (traceback_matrix[i][j] == 2) {
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
    std::vector<std::vector<int>> score_matrix;
    std::vector<std::vector<int>> traceback_matrix;
    int max_score;
    std::pair<int, int> max_position;
};

void main() {
    std::string seq1 = "AGCTG";
    std::string seq2 = "CGTAT";
    SequenceAligner aligner(seq1, seq2);
    aligner.fill_matrices();
    auto [aligned_seq1, aligned_seq2] = aligner.backtrack();
    std::cout << aligned_seq1 << std::endl;
    std::cout << aligned_seq2 << std::endl;
}

int main() {
    main();
    return 0;
}