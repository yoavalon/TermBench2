#include <iostream>
#include <string>
#include <map>

std::string network_state_machine() {
    std::map<std::string, std::string> transitions = {
        {"idle", "connected"},
        {"connected", "failed"},
        {"failed", "idle"}
    };
    std::string state = "idle";
    for (int i = 0; i < 3; ++i) {
        state = transitions[state];
    }
    return state;
}

int main() {
    std::cout << network_state_machine() << std::endl;
    return 0;
}