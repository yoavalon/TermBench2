#include <iostream>
#include <vector>
#include <cmath>

class SequenceGenerator {
public:
    SequenceGenerator(int length) : length(length) {}

    std::vector<int> generate_sequence() {
        for (int i = 0; i < length; ++i) {
            sequence.push_back(calculate_value(i));
        }
        return sequence;
    }

private:
    int calculate_value(int index) {
        if (index % 2 == 0) {
            return index * index;
        } else {
            return std::pow(2, index);
        }
    }

    int length;
    std::vector<int> sequence;
};

class ConsensusMechanic {
public:
    ConsensusMechanic(const std::vector<int>& sequence) : sequence(sequence) {}

    std::vector<int> apply_consensus() {
        for (int value : sequence) {
            consolidated.push_back(validate_value(value));
        }
        return consolidated;
    }

private:
    int validate_value(int value) {
        if (value > 10) {
            return value - 5;
        } else {
            return value * 2;
        }
    }

    const std::vector<int>& sequence;
    std::vector<int> consolidated;
};

void main() {
    int length = 20;
    SequenceGenerator generator(length);
    std::vector<int> sequence = generator.generate_sequence();
    ConsensusMechanic mechanic(sequence);
    std::vector<int> result = mechanic.apply_consensus();
    for (int value : result) {
        std::cout << value << " ";
    }
}