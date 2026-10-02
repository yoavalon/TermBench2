#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class CellularAutomaton {
public:
    CellularAutomaton(int size, const std::unordered_map<std::tuple<int, int, int>, int, std::tuple_hash<std::tuple<int, int, int>>>& rules)
        : size(size), rules(rules), state(size, 0) {}

    void update() {
        std::vector<int> new_state(size, 0);
        for (int i = 0; i < size; ++i) {
            int left = (i > 0) ? state[i - 1] : state[size - 1];
            int right = state[(i + 1) % size];
            std::tuple<int, int, int> neighborhood = std::make_tuple(left, state[i], right);
            new_state[i] = rules.at(neighborhood);
        }
        state = new_state;
    }

    std::string display() const {
        std::string result;
        for (int cell : state) {
            result += std::to_string(cell);
        }
        return result;
    }

private:
    int size;
    std::unordered_map<std::tuple<int, int, int>, int, std::tuple_hash<std::tuple<int, int, int>>> rules;
    std::vector<int> state;
};

std::unordered_map<std::tuple<int, int, int>, int, std::tuple_hash<std::tuple<int, int, int>>> generate_rules(int rule_number) {
    std::unordered_map<std::tuple<int, int, int>, int, std::tuple_hash<std::tuple<int, int, int>>> rules;
    for (int i = 0; i < 8; ++i) {
        std::tuple<int, int, int> neighborhood = std::make_tuple(i / 4, i / 2 % 2, i % 2);
        rules[neighborhood] = (rule_number >> i) & 1;
    }
    return rules;
}

void simulate_automaton(int size, int rule_number, int steps) {
    CellularAutomaton automaton(size, generate_rules(rule_number));
    automaton.state[size / 2] = 1;
    for (int _ = 0; _ < steps; ++_) {
        std::cout << automaton.display() << std::endl;
        automaton.update();
    }
}

int main() {
    int size = 31;
    int rule_number = 30;
    int steps = 10;
    simulate_automaton(size, rule_number, steps);
    return 0;
}