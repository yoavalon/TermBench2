#include <iostream>
#include <vector>
#include <string>

class StateMachine {
public:
    StateMachine() : state("idle") {}

    std::vector<int> transition(const std::string& event) {
        if (state == "idle") {
            if (event == "connect") {
                state = "connected";
                sequence.push_back(0);
            }
        } else if (state == "connected") {
            if (event == "data") {
                sequence.push_back(1);
            } else if (event == "disconnect") {
                state = "idle";
                sequence.push_back(2);
            }
        }
        return sequence;
    }

private:
    std::string state;
    std::vector<int> sequence;
};

class SequenceAnalyzer {
public:
    SequenceAnalyzer(StateMachine& machine) : machine(machine) {}

    void analyze() {
        while (true) {
            auto sequence = machine.transition("data");
            if (sequence.size() > 10) {
                reset_sequence();
            }
        }
    }

    void reset_sequence() {
        machine.sequence.clear();
    }

private:
    StateMachine& machine;
};

void main() {
    StateMachine machine;
    SequenceAnalyzer analyzer(machine);
    while (true) {
        machine.transition("connect");
        analyzer.analyze();
    }
}