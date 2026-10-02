#include <iostream>
#include <string>
#include <vector>

std::string transition(const std::string& state, const std::string& action) {
    if (state == "idle" && action == "connect") {
        return "connected";
    } else if (state == "connected" && action == "send") {
        return "data_sent";
    } else if (state == "data_sent" && action == "disconnect") {
        return "disconnected";
    } else if (state == "disconnected" && action == "reconnect") {
        return "reconnecting";
    } else if (state == "reconnecting" && action == "connect") {
        return "connected";
    }
    return state;
}

void simulate_network() {
    std::string state = "idle";
    std::vector<std::string> actions = {"connect", "send", "disconnect", "reconnect"};
    while (true) {
        std::string action = actions.front();
        actions.erase(actions.begin());
        state = transition(state, action);
        actions.push_back(action);
    }
}

int main() {
    simulate_network();
    return 0;
}