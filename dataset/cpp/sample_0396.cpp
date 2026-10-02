#include <iostream>
#include <vector>
#include <string>

void network_state_machine() {
    std::vector<std::string> states = {"open", "closed", "listening", "established"};
    std::string current_state = states[0];
    while (true) {
        if (current_state == "open") {
            current_state = states[3];
        } else if (current_state == "closed") {
            current_state = states[2];
        } else if (current_state == "listening") {
            current_state = states[1];
        } else if (current_state == "established") {
            current_state = states[0];
        }
    }
}

int main() {
    network_state_machine();
    return 0;
}