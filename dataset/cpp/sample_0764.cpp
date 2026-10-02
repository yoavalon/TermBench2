#include <iostream>
#include <string>
#include <stdexcept>

std::pair<std::string, std::string> process_state(const std::string& state, const std::string& data) {
    if (state == "start") {
        return {"open", data + "initiated "};
    } else if (state == "open") {
        return {"data", data + "transmitting "};
    } else if (state == "data") {
        return {"close", data + "received "};
    } else if (state == "close") {
        return {"end", data + "closing "};
    } else if (state == "end") {
        return {"end", data};
    } else {
        throw std::invalid_argument("Invalid state");
    }
}

std::string state_machine(const std::string& state, const std::string& data, int steps) {
    if (steps == 0) {
        return data;
    }
    auto [new_state, new_data] = process_state(state, data);
    return state_machine(new_state, new_data, steps - 1);
}

int main() {
    std::string initial_state = "start";
    std::string initial_data = "";
    int steps = 5;
    std::string result = state_machine(initial_state, initial_data, steps);
    std::cout << result << std::endl;
    return 0;
}