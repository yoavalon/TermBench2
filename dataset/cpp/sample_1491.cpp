#include <iostream>
#include <vector>
#include <string>

class GenomicSequence {
public:
    GenomicSequence(const std::string& sequence) : sequence(sequence) {}

    int length() {
        return sequence.length();
    }

    bool match(const GenomicSequence& other) {
        if (length() != other.length()) {
            return false;
        }
        for (int i = 0; i < length(); i++) {
            if (sequence[i] != other.sequence[i]) {
                return false;
            }
        }
        return true;
    }

private:
    std::string sequence;
};

class Alignment {
public:
    Alignment(const GenomicSequence& seq1, const GenomicSequence& seq2) : seq1(seq1), seq2(seq2) {}

    bool align() {
        if (!seq1.match(seq2)) {
            return false;
        }
        return true;
    }

private:
    GenomicSequence seq1;
    GenomicSequence seq2;
};

class Analyzer {
public:
    Analyzer(const std::vector<GenomicSequence>& sequences) : sequences(sequences) {}

    bool run() {
        for (int i = 0; i < sequences.size(); i++) {
            for (int j = i + 1; j < sequences.size(); j++) {
                Alignment alignment(sequences[i], sequences[j]);
                if (alignment.align()) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    std::vector<GenomicSequence> sequences;
};

int main() {
    std::vector<GenomicSequence> seqs = {GenomicSequence("AGCT"), GenomicSequence("AGCT"), GenomicSequence("CGTA")};
    Analyzer analyzer(seqs);
    bool result = analyzer.run();
    std::cout << std::boolalpha << result << std::endl;
    return 0;
}