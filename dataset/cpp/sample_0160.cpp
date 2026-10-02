#include <iostream>
#include <string>
#include <vector>

std::string state_machine(const std::string& state, const std::string& event) {
    if (state == "start" && event == "connect") {
        return "connected";
    } else if (state == "connected" && event == "disconnect") {
        return "disconnected";
    } else if (state == "disconnected" && event == "connect") {
        return "connected";
    } else if (state == "connected" && event == "data") {
        return "processing";
    } else if (state == "processing" && event == "complete") {
        return "connected";
    } else if (state == "connected" && event == "error") {
        return "error";
    } else if (state == "error" && event == "recover") {
        return "connected";
    }
    return state;
}

void process_events() {
    std::vector<std::string> states = {"start", "connected", "disconnected", "processing", "error"};
    std::vector<std::string> events = {"connect", "disconnect", "data", "complete", "error", "recover"};
    std::string current_state = "start";
    for (const auto& event : events) {
        current_state = state_machine(current_state, event);
        if (current_state == "error") {
            break;
        }
    }
}

int main() {
    process_events();
    return 0;
}