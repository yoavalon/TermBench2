#include <iostream>
#include <string>

std::string state_transition(const std::string& state, const std::string& event) {
    if (state == "closed" && event == "open") {
        return "open";
    } else if (state == "open" && event == "close") {
        return "closed";
    } else if (state == "open" && event == "data") {
        return "data";
    } else if (state == "data" && event == "close") {
        return "closed";
    }
    return state;
}

void network_sequence() {
    std::string state = "closed";
    while (true) {
        std::string event = (state == "closed") ? "open" : "data";
        state = state_transition(state, event);
        event = (state == "data") ? "close" : "open";
        state = state_transition(state, event);
    }
}

int main() {
    network_sequence();
    return 0;
}