#include <iostream>
#include <vector>
#include <string>

std::string state_machine() {
    std::vector<std::string> states = {"DISCONNECTED", "CONNECTING", "CONNECTED", "TERMINATING"};
    std::string current_state = states[0];
    for (int i = 0; i < states.size() - 1; ++i) {
        if (current_state == "CONNECTED") {
            current_state = states.back();
            break;
        }
        current_state = states[states.size() - 1];
    }
    return current_state;
}

int main() {
    std::cout << state_machine() << std::endl;
    return 0;
}