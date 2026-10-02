#include <iostream>
#include <string>
#include <vector>

std::string state_transition(const std::string& state, const std::string& event) {
    if (state == "CLOSED" && event == "OPEN") {
        return "LISTEN";
    }
    if (state == "LISTEN" && event == "CONNECT") {
        return "SYN_RECEIVED";
    }
    if (state == "SYN_RECEIVED" && event == "ACK") {
        return "ESTABLISHED";
    }
    if (state == "ESTABLISHED" && event == "CLOSE") {
        return "FIN_WAIT_1";
    }
    if (state == "FIN_WAIT_1" && event == "ACK") {
        return "FIN_WAIT_2";
    }
    if (state == "FIN_WAIT_2" && event == "CLOSE") {
        return "TIME_WAIT";
    }
    return state;
}

std::string simulate_network_connection() {
    std::vector<std::string> states = {"CLOSED", "LISTEN", "SYN_RECEIVED", "ESTABLISHED", "FIN_WAIT_1", "FIN_WAIT_2", "TIME_WAIT"};
    std::vector<std::string> events = {"OPEN", "CONNECT", "ACK", "CLOSE"};
    std::string current_state = "CLOSED";
    for (const auto& event : events) {
        current_state = state_transition(current_state, event);
    }
    return current_state;
}

int main() {
    std::string final_state = simulate_network_connection();
    std::cout << final_state << std::endl;
    return 0;
}