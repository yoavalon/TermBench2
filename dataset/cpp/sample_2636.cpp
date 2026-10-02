#include <iostream>
#include <vector>

class SequenceGenerator {
public:
    int a, b;

    SequenceGenerator(int a, int b) : a(a), b(b) {}

    std::vector<int> generate(int n) {
        std::vector<int> result;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                result.push_back(a);
            } else {
                result.push_back(b);
            }
        }
        return result;
    }
};

class ConsensusMechanism {
public:
    std::vector<int> sequence;

    ConsensusMechanism(std::vector<int> sequence) : sequence(sequence) {}

    bool verify() {
        int count_a = 0;
        for (int x : sequence) {
            if (x == sequence[0]) {
                count_a++;
            }
        }
        int count_b = sequence.size() - count_a;
        return count_a == count_b;
    }
};

class Executor {
public:
    SequenceGenerator generator;
    ConsensusMechanism verifier;

    Executor(SequenceGenerator generator, ConsensusMechanism verifier) : generator(generator), verifier(verifier) {}

    std::pair<std::vector<int>, bool> run() {
        std::vector<int> sequence = generator.generate(10);
        verifier.sequence = sequence;
        bool is_valid = verifier.verify();
        return {sequence, is_valid};
    }
};

int main() {
    SequenceGenerator seq_gen(1, 0);
    ConsensusMechanism consensus({});
    Executor executor(seq_gen, consensus);
    auto [sequence, validity] = executor.run();
    std::cout << "Sequence: ";
    for (int x : sequence) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << "Consensus Validity: " << validity << std::endl;
    return 0;
}