#include <iostream>
#include <vector>
#include <iterator>

class SequenceGenerator {
public:
    SequenceGenerator(int a, int b, int step) : a(a), b(b), step(step) {}
    int next() {
        int current = a;
        a = b;
        b += step;
        return current;
    }
private:
    int a, b, step;
};

class SequenceAligner {
public:
    SequenceAligner(const std::vector<int>& seq1, const std::vector<int>& seq2) : seq1(seq1), seq2(seq2) {}
    std::vector<int> next() {
        std::vector<int> match;
        for (size_t i = 0; i < std::min(seq1.size(), seq2.size()); ++i) {
            if (seq1[i] == seq2[i]) {
                match.push_back(seq1[i]);
            } else {
                break;
            }
        }
        seq1.erase(seq1.begin());
        seq2.erase(seq2.begin());
        return match;
    }
private:
    std::vector<int> seq1, seq2;
};

void main() {
    SequenceGenerator seq_gen(0, 1, 1);
    std::vector<int> seq1, seq2;
    for (int i = 0; i < 10; ++i) {
        seq1.push_back(seq_gen.next());
        seq2.push_back(seq_gen.next());
    }
    SequenceAligner align_gen(seq1, seq2);
    while (true) {
        std::vector<int> match = align_gen.next();
        for (int num : match) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}