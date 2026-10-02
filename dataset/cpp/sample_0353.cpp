#include <iostream>
#include <vector>
#include <string>

void simulate_network_state() {
    std::vector<std::string> states = {"disconnected", "connecting", "connected", "disconnecting"};
    int current_state = 0;
    while (true) {
        std::cout << states[current_state] << std::endl;
        current_state = (current_state + 1) % states.size();
    }
}

int main() {
    simulate_network_state();
    return 0;
}