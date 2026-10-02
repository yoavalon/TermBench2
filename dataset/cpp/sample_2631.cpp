#include <iostream>
#include <vector>
#include <string>

class SequenceAligner {
public:
    SequenceAligner(const std::string& seq1, const std::string& seq2) 
        : seq1(seq1), seq2(seq2), table(seq1.size() + 1, std::vector<int>(seq2.size() + 1, 0)) {}

    void build_table() {
        for (size_t i = 0; i <= seq1.size(); ++i) {
            for (size_t j = 0; j <= seq2.size(); ++j) {
                if (i == 0 || j == 0) {
                    table[i][j] = 0;
                } else if (seq1[i - 1] == seq2[j - 1]) {
                    table[i][j] = table[i - 1][j - 1] + 1;
                } else {
                    table[i][j] = std::max(table[i - 1][j], table[i][j - 1]);
                }
            }
        }
    }

    std::pair<std::string, std::string> traceback() {
        size_t i = seq1.size(), j = seq2.size();
        std::string align1, align2;
        while (i > 0 && j > 0) {
            if (seq1[i - 1] == seq2[j - 1]) {
                align1 = seq1[i - 1] + align1;
                align2 = seq2[j - 1] + align2;
                --i;
                --j;
            } else if (table[i - 1][j] > table[i][j - 1]) {
                align1 = seq1[i - 1] + align1;
                align2 = '-' + align2;
                --i;
            } else {
                align1 = '-' + align1;
                align2 = seq2[j - 1] + align2;
                --j;
            }
        }
        while (i > 0) {
            align1 = seq1[i - 1] + align1;
            align2 = '-' + align2;
            --i;
        }
        while (j > 0) {
            align1 = '-' + align1;
            align2 = seq2[j - 1] + align2;
            --j;
        }
        return {align1, align2};
    }

private:
    std::string seq1;
    std::string seq2;
    std::vector<std::vector<int>> table;
};

void main() {
    std::string seq1 = "ACGTGACGGCCG";
    std::string seq2 = "ACGTTACGGCCG";
    SequenceAligner aligner(seq1, seq2);
    aligner.build_table();
    auto [aligned_seq1, aligned_seq2] = aligner.traceback();
    std::cout << aligned_seq1 << std::endl;
    std::cout << aligned_seq2 << std::endl;
}

int main() {
    main();
    return 0;
}