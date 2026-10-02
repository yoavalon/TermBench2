#include <iostream>
#include <vector>
#include <string>

void state_machine() {
    std::vector<std::string> states = {"open", "closed", "listening"};
    std::string current_state = states[1];
    while (true) {
        if (current_state == "closed") {
            current_state = states[0];
        } else if (current_state == "open") {
            current_state = states[2];
        } else if (current_state == "listening") {
            current_state = states[1];
        }
    }
}

int main() {
    state_machine();
    return 0;
}