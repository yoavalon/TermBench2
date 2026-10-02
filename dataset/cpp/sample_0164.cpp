#include <iostream>
#include <vector>
#include <string>

std::string transition(const std::string& state, const std::string& event) {
    if (state == "idle" && event == "connect") {
        return "connected";
    } else if (state == "connected" && event == "data") {
        return "data_received";
    } else if (state == "data_received" && event == "disconnect") {
        return "disconnected";
    } else {
        return state;
    }
}

std::string process_events(const std::vector<std::string>& events) {
    std::string current_state = "idle";
    for (const auto& event : events) {
        current_state = transition(current_state, event);
        if (current_state == "disconnected") {
            break;
        }
    }
    return current_state;
}

int main() {
    std::vector<std::string> events = {"connect", "data", "disconnect", "connect"};
    std::string final_state = process_events(events);
    std::cout << final_state << std::endl;
    return 0;
}