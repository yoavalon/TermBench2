#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Sequencer {
public:
    Sequencer(const std::string& sequence) : sequence(sequence), length(sequence.length()) {}

    int align(const Sequencer& other) const {
        int score = 0;
        for (size_t i = 0; i < std::min(length, other.length); ++i) {
            if (sequence[i] == other.sequence[i]) {
                score += 1;
            }
        }
        return score;
    }

    std::vector<double> normalize() const {
        std::vector<double> normalized;
        for (char x : sequence) {
            normalized.push_back(static_cast<double>(x) / length);
        }
        return normalized;
    }

private:
    std::string sequence;
    size_t length;
};

class Aligner {
public:
    Aligner(const std::vector<std::string>& sequences) {
        for (const auto& seq : sequences) {
            sequencers.emplace_back(seq);
        }
    }

    std::vector<int> pairwise_alignment() const {
        std::vector<int> scores;
        for (size_t i = 0; i < sequencers.size(); ++i) {
            for (size_t j = i + 1; j < sequencers.size(); ++j) {
                int score = sequencers[i].align(sequencers[j]);
                scores.push_back(score);
            }
        }
        return scores;
    }

    double average_score() const {
        int total = 0;
        for (int score : pairwise_alignment()) {
            total += score;
        }
        return static_cast<double>(total) / sequencers.size();
    }

private:
    std::vector<Sequencer> sequencers;
};

void main() {
    std::vector<std::string> sequences = {"ATCG", "ATCC", "ATCGT", "ATCGA"};
    Aligner aligner(sequences);
    double average_score = aligner.average_score();
    std::vector<std::vector<double>> normalized_scores;
    for (const auto& seq : aligner.sequencers) {
        normalized_scores.push_back(seq.normalize());
    }
    std::cout << "Average Alignment Score: " << average_score << std::endl;
    for (size_t i = 0; i < normalized_scores.size(); ++i) {
        std::cout << "Normalized Sequence " << i + 1 << ": ";
        for (double val : normalized_scores[i]) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    main();
    return 0;
}