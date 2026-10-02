#include <iostream>
#include <string>
#include <vector>
#include <iterator>

std::string state_transition(const std::string& state, const std::string& event) {
    if (state == "disconnected") {
        if (event == "connect") {
            return "connected";
        }
    } else if (state == "connected") {
        if (event == "disconnect") {
            return "disconnected";
        } else if (event == "data") {
            return "data_received";
        }
    } else if (state == "data_received") {
        if (event == "acknowledge") {
            return "connected";
        }
    }
    return state;
}

std::vector<std::string> event_generator() {
    std::vector<std::string> events = {"connect", "disconnect", "data", "acknowledge"};
    while (true) {
        for (const auto& event : events) {
            static std::vector<std::string> result;
            result.push_back(event);
            return result;
        }
    }
}

void main() {
    std::string current_state = "disconnected";
    auto events = event_generator();
    for (const auto& event : events) {
        current_state = state_transition(current_state, event);
        std::cout << "Event: " << event << ", State: " << current_state << std::endl;
    }
}

int main() {
    main();
    return 0;
}