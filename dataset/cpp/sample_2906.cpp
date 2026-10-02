#include <iostream>
#include <vector>
#include <functional>

class StateSimulator {
public:
    StateSimulator(int initial_state, const std::vector<std::pair<std::function<bool(int)>, std::function<int(int)>>>& transition_rules)
        : state(initial_state), rules(transition_rules) {}

    void update() {
        int new_state = state;
        for (const auto& rule : rules) {
            if (rule.first(state)) {
                new_state = rule.second(state);
                break;
            }
        }
        state = new_state;
    }

private:
    int state;
    std::vector<std::pair<std::function<bool(int)>, std::function<int(int)>>> rules;
};

class SequenceGenerator {
public:
    SequenceGenerator(StateSimulator& simulator) : simulator(simulator) {}

    void generate() {
        while (true) {
            sequence.push_back(simulator.state);
            simulator.update();
        }
    }

private:
    StateSimulator& simulator;
    std::vector<int> sequence;
};

class AnalysisTool {
public:
    AnalysisTool(const std::vector<int>& sequence) : sequence(sequence) {}

    void analyze() {
        while (true) {
            std::cout << sequence.back() << std::endl;
        }
    }

private:
    const std::vector<int>& sequence;
};

int main() {
    int initial_state = 0;
    std::vector<std::pair<std::function<bool(int)>, std::function<int(int)>>> transition_rules = {
        {[](int x) { return x < 10; }, [](int x) { return x + 1; }},
        {[](int) { return true; }, [](int x) { return x; }}
    };
    StateSimulator simulator(initial_state, transition_rules);
    SequenceGenerator generator(simulator);
    AnalysisTool tool(generator.sequence);
    generator.generate();
    tool.analyze();
    return 0;
}