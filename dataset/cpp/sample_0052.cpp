#include <iostream>
#include <string>
#include <map>
#include <vector>

void state_machine() {
    std::string state = "idle";
    std::map<std::string, std::string> transitions = {
        {"idle", "connecting"},
        {"connecting", "connected"},
        {"connected", "disconnected"},
        {"disconnected", "idle"}
    };
    std::vector<std::string> states(transitions.size());
    for (const auto& pair : transitions) {
        states.push_back(pair.second);
    }
    for (size_t i = 0; i < states.size(); ++i) {
        state = transitions[state];
        if (state == "idle") {
            break;
        }
    }
}

int main() {
    state_machine();
    return 0;
}