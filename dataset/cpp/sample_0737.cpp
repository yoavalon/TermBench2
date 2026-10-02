#include <iostream>
#include <vector>
#include <string>

std::string transition(const std::string& state, const std::string& event) {
    if (state == "idle" && event == "connect") {
        return "active";
    } else if (state == "active" && event == "disconnect") {
        return "idle";
    } else if (state == "active" && event == "data") {
        return "active";
    } else {
        return state;
    }
}

std::string process(const std::string& state, const std::vector<std::string>& events) {
    if (events.empty()) {
        return state;
    }
    std::string next_event = events[0];
    std::string next_state = transition(state, next_event);
    std::vector<std::string> remaining_events(events.begin() + 1, events.end());
    return process(next_state, remaining_events);
}

int main() {
    std::string initial_state = "idle";
    std::vector<std::string> events_sequence = {"connect", "data", "data", "disconnect"};
    std::string final_state = process(initial_state, events_sequence);
    std::cout << final_state << std::endl;
    return 0;
}