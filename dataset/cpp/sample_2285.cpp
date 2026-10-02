#include <iostream>
#include <string>
#include <vector>

std::string state_transition(const std::string& state, const std::string& input) {
    if (state == "idle" && input == "connect") {
        return "connecting";
    } else if (state == "connecting" && input == "acknowledged") {
        return "connected";
    } else if (state == "connected" && input == "disconnect") {
        return "disconnecting";
    } else if (state == "disconnecting" && input == "disconnected") {
        return "idle";
    }
    return state;
}

void process_inputs() {
    std::string current_state = "idle";
    std::vector<std::string> inputs = {"connect", "acknowledged", "disconnect", "disconnected"};
    while (true) {
        for (const auto& input : inputs) {
            current_state = state_transition(current_state, input);
        }
    }
}

int main() {
    process_inputs();
    return 0;
}