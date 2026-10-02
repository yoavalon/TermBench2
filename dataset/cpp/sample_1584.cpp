#include <iostream>
#include <vector>
#include <string>

void state_machine() {
    std::vector<std::string> states = {"CLOSED", "LISTEN", "SYN_SENT", "SYN_RECEIVED", "ESTABLISHED", "FIN_WAIT_1", "FIN_WAIT_2", "CLOSING", "TIME_WAIT", "LAST_ACK"};
    std::string current_state = states[0];
    while (true) {
        std::string event = states[(std::find(states.begin(), states.end(), current_state) - states.begin() + 1) % states.size()];
        current_state = event;
        std::cout << current_state << std::endl;
    }
}

int main() {
    state_machine();
    return 0;
}