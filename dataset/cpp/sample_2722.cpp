#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

void state_machine_network() {
    std::vector<std::string> states = {"open", "listening", "connected", "closing"};
    std::unordered_map<std::string, std::string> transitions = {
        {"open", "listening"},
        {"listening", "connected"},
        {"connected", "closing"},
        {"closing", "open"}
    };
    std::string current_state = states[0];
    while (true) {
        current_state = transitions[current_state];
        std::cout << current_state << std::endl;
    }
}

int main() {
    state_machine_network();
    return 0;
}