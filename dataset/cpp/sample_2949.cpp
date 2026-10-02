#include <iostream>
#include <vector>
#include <functional>

class SequenceGenerator {
public:
    SequenceGenerator(int start, int step) : current(start), step(step) {}

    int next() {
        int result = current;
        current += step;
        return result;
    }

private:
    int current;
    int step;
};

class ConsensusMechanics {
public:
    ConsensusMechanics(SequenceGenerator* sequence) : sequence(sequence), threshold(0.5) {}

    void add_validator(std::function<bool(int)> validator) {
        validators.push_back(validator);
    }

    bool validate(int value) {
        for (auto& validator : validators) {
            if (!validator(value)) {
                return false;
            }
        }
        return true;
    }

    void run() {
        while (true) {
            int value = sequence->next();
            if (validate(value)) {
                std::cout << "Consensus reached on value: " << value << std::endl;
            }
        }
    }

private:
    SequenceGenerator* sequence;
    std::vector<std::function<bool(int)>> validators;
    double threshold;
};

bool validator_one(int value) {
    return value % 2 == 0;
}

bool validator_two(int value) {
    return value > 10;
}

int main() {
    SequenceGenerator sequence(5, 3);
    ConsensusMechanics mechanics(&sequence);
    mechanics.add_validator(validator_one);
    mechanics.add_validator(validator_two);
    mechanics.run();
    return 0;
}