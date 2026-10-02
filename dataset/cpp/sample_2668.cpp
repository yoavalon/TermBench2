cpp
#include <iostream>
#include <vector>

class CellularAutomata {
public:
    CellularAutomata(int size, int rule) : size(size), rule(rule), state(size, 0) {
        state[size / 2] = 1;
    }

    int apply_rule(int left, int center, int right) {
        int index = 4 * left + 2 * center + right;
        return (rule >> index) & 1;
    }

    void next_generation() {
        std::vector<int> new_state(size, 0);
        for (int i = 0; i < size; ++i) {
            int left = state[(i - 1 + size) % size];
            int center = state[i];
            int right = state[(i + 1) % size];
            new_state[i] = apply_rule(left, center, right);
        }
        state = new_state;
    }

    std::vector<std::vector<int>> run(int steps) {
        std::vector<std::vector<int>> results;
        for (int _ = 0; _ < steps; ++_) {
            results.push_back(state);
            next_generation();
        }
        return results;
    }

private:
    int size;
    int rule;
    std::vector<int> state;
};

std::vector<std::vector<int>> generate_sequence(int size, int rule, int steps) {
    CellularAutomata ca(size, rule);
    return ca.run(steps);
}

void display_sequence(const std::vector<std::vector<int>>& sequence) {
    for (const auto& row : sequence) {
        for (int cell : row) {
            std::cout << (cell ? '1' : '0');
        }
        std::cout << std::endl;
    }
}

int main() {
    int size = 31;
    int rule = 30;
    int steps = 10;
    std::vector<std::vector<int>> sequence = generate_sequence(size, rule, steps);
    display_sequence(sequence);
    return 0;
}