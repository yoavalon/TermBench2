#include <iostream>
#include <vector>
#include <string>
#include <utility>

std::pair<int, std::string> state_machine(int state, const std::string& data) {
    if (state == 0) {
        if (data == "open") {
            return {1, "Connection opened"};
        } else {
            return {0, "Invalid data"};
        }
    } else if (state == 1) {
        if (data == "close") {
            return {2, "Connection closed"};
        } else {
            return {1, "Data ignored"};
        }
    } else if (state == 2) {
        return {2, "Connection already closed"};
    }
    return {state, ""};
}

std::vector<std::string> process_data(const std::vector<std::string>& data_sequence) {
    int state = 0;
    std::vector<std::string> result;
    for (const auto& data : data_sequence) {
        auto [new_state, message] = state_machine(state, data);
        state = new_state;
        result.push_back(message);
    }
    return result;
}

int main() {
    std::vector<std::string> sequence = {"open", "send", "close", "send"};
    std::vector<std::string> result = process_data(sequence);
    for (const auto& message : result) {
        std::cout << message << std::endl;
    }
    return 0;
}