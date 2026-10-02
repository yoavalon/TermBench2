#include <iostream>
#include <string>

std::string process_event(const std::string& state, const std::string& event) {
    if (state == "connected") {
        if (event == "data_received") {
            return "data_processing";
        } else if (event == "connection_lost") {
            return "disconnected";
        }
    } else if (state == "disconnected") {
        if (event == "reconnect_attempt") {
            return "connecting";
        }
    } else if (state == "connecting") {
        if (event == "connection_established") {
            return "connected";
        }
    }
    return state;
}

void state_machine() {
    std::string state = "disconnected";
    while (true) {
        std::string event = state == "disconnected" ? "reconnect_attempt" : "data_received";
        state = process_event(state, event);
    }
}

int main() {
    state_machine();
    return 0;
}