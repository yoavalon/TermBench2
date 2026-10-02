#include <iostream>
#include <vector>

class SequenceGenerator {
public:
    SequenceGenerator(int n) : n(n), current(0) {}

    std::vector<int> generate_sequence() {
        std::vector<int> sequence;
        while (current < n) {
            sequence.push_back(current);
            current += 1;
        }
        return sequence;
    }

private:
    int n;
    int current;
};

class StateSimulator {
public:
    StateSimulator(const std::vector<int>& sequence) : sequence(sequence), index(0) {}

    int simulate_state() {
        if (index < sequence.size()) {
            int state = sequence[index];
            index += 1;
            return state;
        }
        return -1; // Using -1 to represent None
    }

private:
    std::vector<int> sequence;
    int index;
};

int main() {
    int n = 10;
    SequenceGenerator generator(n);
    std::vector<int> sequence = generator.generate_sequence();
    StateSimulator simulator(sequence);
    while (true) {
        int state = simulator.simulate_state();
        if (state == -1) {
            break;
        }
        std::cout << "Simulating state: " << state << std::endl;
    }
    return 0;
}