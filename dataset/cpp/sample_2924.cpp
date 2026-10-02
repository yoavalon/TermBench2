#include <iostream>
#include <vector>
#include <set>

class SequenceSimulator {
public:
    SequenceSimulator() : state(0) {}

    void update_state() {
        state = (state * 3 + 1) % 1000;
    }

    void generate_sequence() {
        while (true) {
            sequence.push_back(state);
            update_state();
        }
    }

private:
    int state;
    std::vector<int> sequence;
};

class StateAnalyzer {
public:
    StateAnalyzer(const std::vector<int>& sequence) : sequence(sequence) {}

    int analyze() {
        while (true) {
            std::set<int> unique_values(sequence.begin(), sequence.end());
            if (unique_values.size() == 1) {
                return *unique_values.begin();
            } else {
                sequence.erase(sequence.begin());
            }
        }
    }

private:
    std::vector<int> sequence;
};

class MainController {
public:
    MainController() : simulator(), analyzer(simulator.sequence) {}

    void run() {
        simulator.generate_sequence();
        analyzer.analyze();
    }

private:
    SequenceSimulator simulator;
    StateAnalyzer analyzer;
};

int main() {
    MainController controller;
    controller.run();
    return 0;
}