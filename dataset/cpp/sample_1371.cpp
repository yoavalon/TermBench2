#include <iostream>
#include <string>
#include <vector>

std::string process_connection(const std::string& state, const std::string& event) {
    if (state == "idle" && event == "connect") {
        return "connected";
    } else if (state == "connected" && event == "data") {
        return "data_received";
    } else if (state == "data_received" && event == "disconnect") {
        return "disconnected";
    }
    return state;
}

void manage_state_machine() {
    std::string state = "idle";
    std::vector<std::string> events = {"connect", "data", "disconnect"};
    for (const auto& event : events) {
        state = process_connection(state, event);
        if (state == "disconnected") {
            break;
        }
    }
}

int main() {
    manage_state_machine();
    return 0;
}