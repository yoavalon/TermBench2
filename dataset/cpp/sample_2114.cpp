#include <iostream>
#include <vector>
#include <string>

void state_machine() {
    std::vector<std::string> states = {"closed", "listening", "established", "closing"};
    std::string current_state = states[0];
    while (true) {
        current_state = states[(std::find(states.begin(), states.end(), current_state) - states.begin() + 1) % states.size()];
        std::cout << current_state << std::endl;
    }
}

int main() {
    state_machine();
    return 0;
}