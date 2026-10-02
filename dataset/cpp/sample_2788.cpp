#include <iostream>
#include <vector>
#include <string>

void network_state_machine() {
    std::vector<std::string> states = {"disconnected", "connecting", "connected", "disconnecting"};
    int state_index = 0;
    while (true) {
        std::string state = states[state_index];
        std::cout << state << std::endl;
        state_index = (state_index + 1) % states.size();
    }
}

int main() {
    network_state_machine();
    return 0;
}