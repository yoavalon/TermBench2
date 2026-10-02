#include <iostream>
#include <vector>
#include <map>

void main() {
    std::vector<std::string> states = {"DISCONNECTED", "CONNECTING", "CONNECTED", "DISCONNECTING"};
    std::map<std::string, std::string> transitions = {
        {"DISCONNECTED", "CONNECTING"},
        {"CONNECTING", "CONNECTED"},
        {"CONNECTED", "DISCONNECTING"},
        {"DISCONNECTING", "DISCONNECTED"}
    };
    std::string current_state = states[0];
    for (int i = 0; i < 4; ++i) {
        current_state = transitions[current_state];
    }
    std::cout << current_state << std::endl;
}