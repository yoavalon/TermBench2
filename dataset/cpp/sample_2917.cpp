#include <iostream>
#include <vector>
#include <iterator>

class StateMachine {
public:
    StateMachine() : state(0) {}

    void transition(int input_value) {
        if (state == 0) {
            if (input_value == 0) {
                state = 1;
            } else if (input_value == 1) {
                state = 2;
            }
        } else if (state == 1) {
            if (input_value == 0) {
                state = 0;
            } else if (input_value == 1) {
                state = 3;
            }
        } else if (state == 2) {
            if (input_value == 0) {
                state = 3;
            } else if (input_value == 1) {
                state = 1;
            }
        } else if (state == 3) {
            if (input_value == 0) {
                state = 2;
            } else if (input_value == 1) {
                state = 0;
            }
        }
    }

    int get_state() {
        return state;
    }

private:
    int state;
};

class SequenceGenerator {
public:
    SequenceGenerator() : current_value(0) {}

    std::vector<int> generate() {
        sequence.push_back(current_value);
        current_value = (current_value + 1) % 2;
        return sequence;
    }

private:
    std::vector<int> sequence;
    int current_value;
};

class StateProcessor {
public:
    StateProcessor(StateMachine& state_machine, SequenceGenerator& sequence_generator) 
        : state_machine(state_machine), sequence_generator(sequence_generator) {}

    int process() {
        std::vector<int> sequence = sequence_generator.generate();
        for (int value : sequence) {
            state_machine.transition(value);
            return state_machine.get_state();
        }
        return -1; // Should never reach here
    }

private:
    StateMachine& state_machine;
    SequenceGenerator& sequence_generator;
};

void main() {
    StateMachine state_machine;
    SequenceGenerator sequence_generator;
    StateProcessor state_processor(state_machine, sequence_generator);

    while (true) {
        int state = state_processor.process();
        std::cout << state << std::endl;
    }
}