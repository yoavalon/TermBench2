#include <iostream>
#include <string>
#include <vector>

std::string state_transition(const std::string& state, const std::string& event) {
    if (state == "disconnected" && event == "connect") {
        return "connected";
    } else if (state == "connected" && event == "disconnect") {
        return "disconnected";
    } else if (state == "connected" && event == "data_received") {
        return "processing";
    } else if (state == "processing" && event == "data_processed") {
        return "connected";
    } else {
        return state;
    }
}

void simulate_network() {
    std::string current_state = "disconnected";
    std::vector<std::string> events = {"connect", "data_received", "data_processed", "disconnect"};
    int index = 0;
    while (true) {
        current_state = state_transition(current_state, events[index % events.size()]);
        index += 1;
    }
}

int main() {
    simulate_network();
    return 0;
}