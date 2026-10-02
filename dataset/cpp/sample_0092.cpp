#include <iostream>
#include <vector>
#include <string>

std::string analyze_network_connections(const std::vector<std::string>& connections, const std::vector<std::string>& states, const std::vector<std::tuple<std::string, std::string, std::string>>& transitions) {
    std::string current_state = states[0];
    for (const auto& connection : connections) {
        for (const auto& transition : transitions) {
            if (std::get<0>(transition) == current_state && std::get<1>(transition) == connection) {
                current_state = std::get<2>(transition);
                break;
            }
        }
    }
    return current_state;
}

int main() {
    std::vector<std::string> connections = {"open", "data", "close"};
    std::vector<std::string> states = {"idle", "active", "closed"};
    std::vector<std::tuple<std::string, std::string, std::string>> transitions = {
        {"idle", "open", "active"},
        {"active", "data", "active"},
        {"active", "close", "closed"}
    };
    std::string result = analyze_network_connections(connections, states, transitions);
    std::cout << result << std::endl;
    return 0;
}