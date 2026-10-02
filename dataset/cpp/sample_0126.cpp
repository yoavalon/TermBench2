#include <iostream>
#include <string>
#include <vector>

std::string process_connection(const std::string& state, const std::string& data) {
    if (state == "init") {
        if (data == "connect") {
            return "connected";
        }
    } else if (state == "connected") {
        if (data == "data") {
            return "processing";
        } else if (data == "disconnect") {
            return "disconnected";
        }
    } else if (state == "processing") {
        if (data == "complete") {
            return "connected";
        } else if (data == "disconnect") {
            return "disconnected";
        }
    } else if (state == "disconnected") {
        if (data == "connect") {
            return "connected";
        }
    }
    return state;
}

void main() {
    std::vector<std::string> states = {"init", "connected", "processing", "disconnected"};
    std::vector<std::string> data_sequence = {"connect", "data", "complete", "disconnect", "connect"};
    std::string current_state = "init";
    for (const auto& data : data_sequence) {
        current_state = process_connection(current_state, data);
        if (std::find(states.begin(), states.end(), current_state) == states.end()) {
            break;
        }
    }
}