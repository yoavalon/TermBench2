#include <iostream>
#include <string>
#include <unordered_map>

void network_state_machine() {
    std::string states[] = {"init", "open", "data", "close"};
    std::string state = states[0];
    std::unordered_map<std::string, std::string> transitions = {
        {"init", "open"},
        {"open", "data"},
        {"data", "close"},
        {"close", "open"}
    };
    while (true) {
        state = transitions[state];
        std::cout << state << std::endl;
    }
}

int main() {
    network_state_machine();
    return 0;
}