#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stdexcept>

std::string state_machine(const std::string& initial_state, const std::unordered_map<std::pair<std::string, std::string>, std::string>& transitions, const std::vector<std::string>& input_sequence) {
    std::string current_state = initial_state;
    for (const auto& signal : input_sequence) {
        auto key = std::make_pair(current_state, signal);
        if (transitions.find(key) != transitions.end()) {
            current_state = transitions.at(key);
        } else {
            throw std::invalid_argument("Invalid state transition");
        }
    }
    return current_state;
}

void process_network_data(const std::vector<std::string>& data) {
    std::string initial = "idle";
    std::unordered_map<std::pair<std::string, std::string>, std::string> transitions = {
        {{"idle", "open"}, "connected"},
        {{"connected", "data"}, "data_transfer"},
        {{"data_transfer", "close"}, "closing"},
        {{"closing", "ack"}, "closed"}
    };
    std::string final_state = state_machine(initial, transitions, data);
    if (final_state != "closed") {
        throw std::exception("Network connection did not terminate properly");
    }
}

int main() {
    std::vector<std::string> sequence = {"open", "data", "close", "ack"};
    process_network_data(sequence);
    return 0;
}