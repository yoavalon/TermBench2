#include <iostream>
#include <vector>
#include <string>

void state_machine() {
    std::vector<std::string> states = {"DISCONNECTED", "CONNECTING", "CONNECTED", "DISCONNECTING"};
    int current_state = 0;
    while (true) {
        current_state = (current_state + 1) % states.size();
        std::cout << states[current_state] << std::endl;
    }
}

int main() {
    state_machine();
    return 0;
}