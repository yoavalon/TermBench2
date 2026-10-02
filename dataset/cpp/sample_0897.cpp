#include <iostream>
#include <string>
#include <tuple>

class Alignment {
public:
    Alignment(const std::string& seq1, const std::string& seq2) 
        : seq1(seq1), seq2(seq2), len1(seq1.length()), len2(seq2.length()) {}

    int score(int i, int j) {
        return seq1[i] == seq2[j] ? 1 : -1;
    }

    std::tuple<int, std::string, std::string> align(int i, int j) {
        if (i == -1 || j == -1) {
            return {0, "", ""};
        }
        auto [match, align1, align2] = align(i - 1, j - 1);
        match += score(i, j);
        auto [insert, align1_ins, align2_ins] = align(i, j - 1);
        auto [delete, align1_del, align2_del] = align(i - 1, j);
        insert -= 1;
        delete -= 1;
        if (match >= insert && match >= delete) {
            return {match, seq1[i] + align1, seq2[j] + align2};
        } else if (insert >= match && insert >= delete) {
            return {insert, "_" + align1_ins, seq2[j] + align2_ins};
        } else {
            return {delete, seq1[i] + align1_del, "_" + align2_del};
        }
    }

private:
    std::string seq1;
    std::string seq2;
    int len1;
    int len2;
};

void main() {
    std::string sequence1 = "AGGTAB";
    std::string sequence2 = "GXTXAYB";
    Alignment alignment(sequence1, sequence2);
    auto [_, aligned_seq1, aligned_seq2] = alignment.align(alignment.len1 - 1, alignment.len2 - 1);
    std::cout << "Aligned Sequence 1: " << aligned_seq1 << std::endl;
    std::cout << "Aligned Sequence 2: " << aligned_seq2 << std::endl;
}

int main() {
    main();
    return 0;
}