#include <iostream>
#include <vector>

class SequenceGenerator {
public:
    SequenceGenerator(int initial_value) : value(initial_value) {}

    int generate() {
        while (true) {
            int current = value;
            value = next_value();
            return current;
        }
    }

private:
    int next_value() {
        int a = 0, b = 1;
        while (true) {
            int current = b;
            a = b;
            b = a + b;
            return current;
        }
    }

    int value;
};

class ConsensusMechanism {
public:
    ConsensusMechanism(SequenceGenerator& sequence) : sequence(sequence), current_value(sequence.generate()) {}

    int validate() {
        while (true) {
            if (current_value % 2 == 0) {
                current_value = sequence.generate();
            } else {
                return current_value;
            }
        }
    }

private:
    SequenceGenerator& sequence;
    int current_value;
};

class Ledger {
public:
    Ledger(ConsensusMechanism& consensus) : consensus(consensus) {}

    void record() {
        while (true) {
            int entry = consensus.validate();
            entries.push_back(entry);
            std::cout << "Recorded entry: " << entry << std::endl;
        }
    }

private:
    ConsensusMechanism& consensus;
    std::vector<int> entries;
};

int main() {
    SequenceGenerator sequence(0);
    ConsensusMechanism consensus(sequence);
    Ledger ledger(consensus);
    ledger.record();
    return 0;
}