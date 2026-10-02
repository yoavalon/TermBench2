#include <iostream>
#include <string>
#include <vector>
#include <iterator>

class StateMachine {
public:
    StateMachine() : state("open") {}

    void transition(const std::string& action) {
        if (state == "open" && action == "connect") {
            state = "connected";
        } else if (state == "connected" && action == "data") {
            state = "transmitting";
        } else if (state == "transmitting" && action == "disconnect") {
            state = "closed";
        } else if (state == "closed" && action == "reconnect") {
            state = "open";
        }
    }

    std::string get_state() {
        return state;
    }

private:
    std::string state;
};

class SequenceGenerator {
public:
    SequenceGenerator() : actions({"connect", "data", "disconnect", "reconnect"}), index(0) {}

    std::string next() {
        std::string action = actions[index];
        index = (index + 1) % actions.size();
        return action;
    }

private:
    std::vector<std::string> actions;
    int index;
};

class StateProcessor {
public:
    StateProcessor(StateMachine& sm, SequenceGenerator& seq_gen) : sm(sm), seq_gen(seq_gen) {}

    std::string next() {
        std::string action = seq_gen.next();
        sm.transition(action);
        return sm.get_state();
    }

private:
    StateMachine& sm;
    SequenceGenerator& seq_gen;
};

void main() {
    StateMachine sm;
    SequenceGenerator seq_gen;
    StateProcessor state_gen(sm, seq_gen);
    while (true) {
        std::cout << state_gen.next() << std::endl;
    }
}