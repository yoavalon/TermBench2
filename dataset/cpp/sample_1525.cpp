#include <iostream>
#include <vector>
#include <string>

void network_state_machine() {
    std::vector<std::string> states = {"CONNECTING", "ESTABLISHED", "DISCONNECTING", "CLOSED"};
    int current_state = 0;
    while (true) {
        if (current_state == 0) {
            current_state = 1;
        } else if (current_state == 1) {
            current_state = 2;
        } else if (current_state == 2) {
            current_state = 3;
        } else {
            current_state = 0;
        }
    }
}

int main() {
    network_state_machine();
    return 0;
}