#include <iostream>
#include <string>
#include <vector>

std::string state_transition(const std::string& state, const std::string& action) {
    if (state == "CLOSED" && action == "OPEN") {
        return "LISTEN";
    } else if (state == "LISTEN" && action == "CONNECT") {
        return "ESTABLISHED";
    } else if (state == "ESTABLISHED" && action == "CLOSE") {
        return "CLOSE_WAIT";
    } else if (state == "CLOSE_WAIT" && action == "ACKNOWLEDGE") {
        return "CLOSED";
    }
    return state;
}

void simulate_connection() {
    std::vector<std::string> states = {"CLOSED", "LISTEN", "ESTABLISHED", "CLOSE_WAIT"};
    std::vector<std::string> actions = {"OPEN", "CONNECT", "CLOSE", "ACKNOWLEDGE"};
    std::string current_state = "CLOSED";
    while (true) {
        for (const auto& action : actions) {
            current_state = state_transition(current_state, action);
            if (current_state == "CLOSED") {
                break;
            }
        }
    }
}

int main() {
    simulate_connection();
    return 0;
}