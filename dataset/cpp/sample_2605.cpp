#include <iostream>
#include <vector>
#include <string>

class SequenceMatcher {
public:
    SequenceMatcher(const std::string& seq1, const std::string& seq2)
        : seq1(seq1), seq2(seq2), len1(seq1.length()), len2(seq2.length()) {}

    int match() {
        std::vector<std::vector<int>> matrix(len1 + 1, std::vector<int>(len2 + 1, 0));
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (seq1[i - 1] == seq2[j - 1]) {
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
                } else {
                    matrix[i][j] = std::max(matrix[i - 1][j], matrix[i][j - 1]);
                }
            }
        }
        return matrix[len1][len2];
    }

private:
    std::string seq1;
    std::string seq2;
    int len1;
    int len2;
};

class GenomicSequenceAnalyzer {
public:
    GenomicSequenceAnalyzer(const std::vector<std::string>& sequences)
        : sequences(sequences) {}

    std::vector<std::tuple<int, int, int>> analyze() {
        std::vector<std::tuple<int, int, int>> results;
        for (int i = 0; i < sequences.size(); ++i) {
            for (int j = i + 1; j < sequences.size(); ++j) {
                SequenceMatcher matcher(sequences[i], sequences[j]);
                results.emplace_back(i, j, matcher.match());
            }
        }
        return results;
    }

private:
    std::vector<std::string> sequences;
};

void main() {
    std::vector<std::string> sequences = {"ATCGTACG", "CGTACGTA", "GTAATCGC", "TACGTACG", "ACGTACGT"};
    GenomicSequenceAnalyzer analyzer(sequences);
    auto results = analyzer.analyze();
    for (const auto& [idx1, idx2, score] : results) {
        std::cout << "Sequence " << idx1 << " vs Sequence " << idx2 << ": Alignment Score " << score << std::endl;
    }
}