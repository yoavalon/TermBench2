#include <iostream>
#include <vector>
#include <string>

void network_state_machine() {
    std::vector<std::string> states = {"open", "connected", "closed", "error"};
    int state_index = 0;
    while (true) {
        std::string current_state = states[state_index];
        std::cout << "Current state: " << current_state << std::endl;
        state_index = (state_index + 1) % states.size();
    }
}

int main() {
    network_state_machine();
    return 0;
}