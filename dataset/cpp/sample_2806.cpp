#include <iostream>
#include <vector>
#include <string>

void state_machine() {
    std::vector<std::string> states = {"idle", "listening", "connected", "disconnected"};
    std::string current_state = states[0];
    while (true) {
        if (current_state == states[0]) {
            current_state = states[1];
        } else if (current_state == states[1]) {
            current_state = states[2];
        } else if (current_state == states[2]) {
            current_state = states[3];
        } else if (current_state == states[3]) {
            current_state = states[0];
        }
    }
}

int main() {
    state_machine();
    return 0;
}