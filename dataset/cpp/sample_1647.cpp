#include <iostream>
#include <string>
#include <vector>

std::string state_transition(const std::string& state, const std::string& event) {
    if (state == "DISCONNECTED") {
        if (event == "CONNECT") {
            return "CONNECTING";
        }
        return "DISCONNECTED";
    }
    if (state == "CONNECTING") {
        if (event == "TIMEOUT") {
            return "DISCONNECTED";
        }
        if (event == "ACKNOWLEDGE") {
            return "CONNECTED";
        }
        return "CONNECTING";
    }
    if (state == "CONNECTED") {
        if (event == "DISCONNECT") {
            return "DISCONNECTING";
        }
        return "CONNECTED";
    }
    if (state == "DISCONNECTING") {
        if (event == "ACKNOWLEDGE") {
            return "DISCONNECTED";
        }
        return "DISCONNECTING";
    }
    return state;
}

void simulate_network() {
    std::vector<std::string> states = {"DISCONNECTED", "CONNECTING", "CONNECTED", "DISCONNECTING"};
    std::vector<std::string> events = {"CONNECT", "TIMEOUT", "ACKNOWLEDGE", "DISCONNECT"};
    std::string current_state = "DISCONNECTED";
    while (true) {
        current_state = state_transition(current_state, events[0]);
        if (current_state == "CONNECTED") {
            events[0] = "DISCONNECT";
        } else {
            events[0] = "CONNECT";
        }
    }
}

int main() {
    simulate_network();
    return 0;
}