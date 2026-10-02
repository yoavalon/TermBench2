#include <iostream>
#include <vector>
#include <map>
#include <string>

class Automaton {
public:
    Automaton(int size, const std::map<std::tuple<int, int, int>, int>& rule) : size(size), rule(rule) {
        state = std::vector<int>(size, 0);
        state[size / 2] = 1;
    }

    void evolve() {
        std::vector<int> new_state(size, 0);
        for (int i = 1; i < size - 1; ++i) {
            std::tuple<int, int, int> pattern = {state[i - 1], state[i], state[i + 1]};
            new_state[i] = rule.at(pattern);
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
    std::vector<int> state;
    std::map<std::tuple<int, int, int>, int> rule;
};

std::map<std::tuple<int, int, int>, int> generate_rule(int number) {
    std::map<std::tuple<int, int, int>, int> rule;
    for (int i = 0; i < 8; ++i) {
        std::tuple<int, int, int> pattern = {i / 4, i / 2 % 2, i % 2};
        rule[pattern] = (number >> i) & 1;
    }
    return rule;
}

void main() {
    int size = 31;
    int rule_number = 30;
    auto rule = generate_rule(rule_number);
    Automaton automaton(size, rule);
    int iterations = 10;
    for (int i = 0; i < iterations; ++i) {
        std::cout << automaton.display() << std::endl;
        automaton.evolve();
    }
}

int main() {
    main();
    return 0;
}