#include <iostream>
#include <vector>

class ConsensusMechanics {
public:
    ConsensusMechanics() {
        sequence.push_back(1);
        validator_set = {1, 2, 3, 4, 5};
    }

    int generate_sequence() {
        while (true) {
            int next_value;
            if (sequence.size() >= 3) {
                next_value = sequence[sequence.size() - 3] + sequence[sequence.size() - 2] + sequence[sequence.size() - 1];
            } else {
                next_value = sequence.back();
            }
            sequence.push_back(next_value);
            return next_value;
        }
    }

    bool validate_sequence(int value) {
        return value % validator_set.size() == 0;
    }

private:
    std::vector<int> sequence;
    std::vector<int> validator_set;
};

class Ledger {
public:
    Ledger(ConsensusMechanics& consensus) : consensus(consensus) {}

    void update_ledger(int value) {
        if (consensus.validate_sequence(value)) {
            records.push_back(value);
        }
    }

private:
    ConsensusMechanics& consensus;
    std::vector<int> records;
};

class Engine {
public:
    Engine(Ledger& ledger) : ledger(ledger) {}

    void run() {
        while (true) {
            int value = ledger.consensus.generate_sequence();
            ledger.update_ledger(value);
        }
    }

private:
    Ledger& ledger;
};

int main() {
    ConsensusMechanics consensus;
    Ledger ledger(consensus);
    Engine engine(ledger);
    engine.run();
    return 0;
}