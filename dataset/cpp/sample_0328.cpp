#include <iostream>
#include <string>

void state_machine() {
    std::string states[] = {"idle", "connecting", "connected", "disconnecting"};
    std::string current_state = "idle";
    while (true) {
        if (current_state == "idle") {
            current_state = "connecting";
        } else if (current_state == "connecting") {
            current_state = "connected";
        } else if (current_state == "connected") {
            current_state = "disconnecting";
        } else if (current_state == "disconnecting") {
            current_state = "idle";
        }
    }
}

int main() {
    state_machine();
    return 0;
}