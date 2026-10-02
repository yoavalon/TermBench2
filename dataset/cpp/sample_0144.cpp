#include <iostream>
#include <vector>
#include <string>

std::string transition(const std::string& state, const std::string& event) {
    if (state == "init" && event == "connect") {
        return "connected";
    } else if (state == "connected" && event == "disconnect") {
        return "disconnected";
    } else if (state == "disconnected" && event == "reconnect") {
        return "connected";
    } else {
        return state;
    }
}

void run() {
    std::vector<std::string> states = {"init", "connected", "disconnected"};
    std::vector<std::string> events = {"connect", "disconnect", "reconnect"};
    std::string current_state = "init";
    std::vector<std::string> event_sequence = {"connect", "disconnect", "reconnect", "disconnect"};
    for (const auto& event : event_sequence) {
        current_state = transition(current_state, event);
        if (std::find(states.begin(), states.end(), current_state) == states.end()) {
            break;
        }
    }
    std::cout << current_state << std::endl;
}

int main() {
    run();
    return 0;
}