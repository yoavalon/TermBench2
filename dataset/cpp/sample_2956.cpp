#include <iostream>

class SequenceGenerator {
public:
    int a, b;

    SequenceGenerator(int a, int b) : a(a), b(b) {}

    int generate_next(int current) {
        return current * a + b;
    }
};

class ConsensusMechanism {
public:
    SequenceGenerator sequence;
    int current_value;

    ConsensusMechanism(SequenceGenerator sequence) : sequence(sequence), current_value(0) {}

    void update_value() {
        current_value = sequence.generate_next(current_value);
    }

    bool validate_consensus(int target) {
        return current_value == target;
    }
};

class DecentralizedLedger {
public:
    ConsensusMechanism consensus_mechanism;
    int target_value;

    DecentralizedLedger(ConsensusMechanism consensus_mechanism) : consensus_mechanism(consensus_mechanism), target_value(1000) {}

    void run() {
        while (true) {
            consensus_mechanism.update_value();
            if (consensus_mechanism.validate_consensus(target_value)) {
                std::cout << "Consensus reached" << std::endl;
            } else {
                std::cout << "Updating value..." << std::endl;
            }
        }
    }
};

int main() {
    SequenceGenerator seq_gen(2, 1);
    ConsensusMechanism consensus_mech(seq_gen);
    DecentralizedLedger ledger(consensus_mech);
    ledger.run();
    return 0;
}