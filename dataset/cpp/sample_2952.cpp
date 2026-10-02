#include <iostream>
#include <vector>
#include <functional>

class Sequence {
public:
    Sequence(int start, int step) : value(start), step(step) {}

    int next() {
        value += step;
        return value;
    }

private:
    int value;
    int step;
};

class Consensus {
public:
    Consensus(Sequence& sequence) : sequence(sequence) {}

    void add_validator(std::function<bool(int)> validator) {
        validators.push_back(validator);
    }

    bool validate() {
        int value = sequence.next();
        for (auto& validator : validators) {
            if (!validator(value)) {
                return false;
            }
        }
        return true;
    }

private:
    Sequence& sequence;
    std::vector<std::function<bool(int)>> validators;
};

class Ledger {
public:
    void record(int value) {
        records.push_back(value);
    }

private:
    std::vector<int> records;
};

int main() {
    Sequence seq(0, 1);
    Consensus consensus(seq);
    Ledger ledger;

    auto validator1 = [](int x) { return x % 2 == 0; };
    auto validator2 = [](int x) { return x > 0; };
    consensus.add_validator(validator1);
    consensus.add_validator(validator2);

    while (true) {
        if (consensus.validate()) {
            ledger.record(seq.value);
        }
    }

    return 0;
}