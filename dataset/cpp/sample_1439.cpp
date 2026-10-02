#include <iostream>
#include <vector>
#include <functional>

class RuleApplier {
public:
    RuleApplier(std::function<bool(int)> condition, std::function<int(int)> action)
        : condition(condition), action(action) {}

    int operator()(int state) {
        if (condition(state)) {
            return action(state);
        }
        return state;
    }

private:
    std::function<bool(int)> condition;
    std::function<int(int)> action;
};

class StateSimulator {
public:
    StateSimulator(int initial_state, const std::vector<std::pair<std::vector<char>, RuleApplier>>& transition_rules)
        : state(initial_state), rules(transition_rules) {}

    int apply_rules() {
        int new_state = state;
        for (const auto& rule : rules) {
            if (std::find(rule.first.begin(), rule.first.end(), 'a') != rule.first.end()) {
                new_state = rule.second(state);
                break;
            }
        }
        return new_state;
    }

    void simulate(int steps) {
        for (int i = 0; i < steps; ++i) {
            state = apply_rules();
        }
    }

private:
    int state;
    std::vector<std::pair<std::vector<char>, RuleApplier>> rules;
};

bool condition_a(int state) {
    return state < 100;
}

int action_a(int state) {
    return state + 10;
}

bool condition_b(int state) {
    return state >= 100;
}

int action_b(int state) {
    return state - 5;
}

int main() {
    int initial_state = 50;
    std::vector<std::pair<std::vector<char>, RuleApplier>> rules = {
        (std::vector<char>{'a'}, RuleApplier(condition_a, action_a)),
        (std::vector<char>{'b'}, RuleApplier(condition_b, action_b))
    };
    StateSimulator simulator(initial_state, rules);
    simulator.simulate(20);
    std::cout << simulator.state << std::endl;
    return 0;
}