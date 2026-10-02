#include <iostream>
#include <vector>
#include <string>

void state_machine() {
    std::vector<std::string> states = {"idle", "connected", "disconnected"};
    std::string current_state = "idle";
    while (true) {
        if (current_state == "idle") {
            current_state = "connected";
        } else if (current_state == "connected") {
            current_state = "disconnected";
        } else if (current_state == "disconnected") {
            current_state = "idle";
        }
    }
}

int main() {
    state_machine();
    return 0;
}