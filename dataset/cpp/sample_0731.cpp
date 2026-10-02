#include <iostream>
#include <string>

std::string state_machine(const std::string& state, const std::string& data, int counter) {
    if (counter > 0) {
        if (state == "open") {
            std::string new_state = "established";
            std::string new_data = data + "1";
            return state_machine(new_state, new_data, counter - 1);
        } else if (state == "established") {
            std::string new_state = "closed";
            std::string new_data = data + "0";
            return state_machine(new_state, new_data, counter - 1);
        } else {
            std::string new_state = "idle";
            std::string new_data = data + "2";
            return state_machine(new_state, new_data, counter - 1);
        }
    }
    return data;
}

void main() {
    std::string initial_state = "open";
    std::string initial_data = "";
    int max_iterations = 5;
    std::string result = state_machine(initial_state, initial_data, max_iterations);
    std::cout << result << std::endl;
}