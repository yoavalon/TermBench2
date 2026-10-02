#include <iostream>
#include <vector>
#include <string>

std::string state_transition(const std::string& state, const std::string& data) {
    if (state == "start") {
        if (data == "open") {
            return "connected";
        }
    } else if (state == "connected") {
        if (data == "close") {
            return "disconnected";
        }
    }
    return state;
}

std::string network_analysis(const std::vector<std::string>& data_sequence) {
    std::string state = "start";
    for (const auto& data : data_sequence) {
        state = state_transition(state, data);
    }
    return state;
}

int main() {
    std::vector<std::string> data_sequence = {"open", "data_transfer", "close"};
    std::string result = network_analysis(data_sequence);
    std::cout << result << std::endl;
    return 0;
}