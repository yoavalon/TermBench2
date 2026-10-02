#include <iostream>
#include <vector>
#include <string>

class StateMachine {
public:
    StateMachine(std::string state) : state(state) {}

    std::string transition(const std::string& input_data) {
        if (state == "start") {
            if (input_data == "data1") {
                state = "state1";
            } else if (input_data == "data2") {
                state = "state2";
            }
        } else if (state == "state1") {
            if (input_data == "data3") {
                state = "end";
            } else {
                state = "start";
            }
        } else if (state == "state2") {
            if (input_data == "data4") {
                state = "end";
            } else {
                state = "start";
            }
        }
        return state;
    }

private:
    std::string state;
};

std::string process_data(StateMachine& machine, const std::vector<std::string>& data_list, int index = 0) {
    if (index == data_list.size()) {
        return machine.transition("");
    }
    machine.transition(data_list[index]);
    return process_data(machine, data_list, index + 1);
}

void main() {
    std::string initial_state = "start";
    StateMachine state_machine(initial_state);
    std::vector<std::string> data_sequence = {"data1", "data2", "data3", "data4", "data1", "data3"};
    std::string final_state = process_data(state_machine, data_sequence);
    std::cout << final_state << std::endl;
}