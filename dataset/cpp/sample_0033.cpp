#include <iostream>
#include <string>

void network_state_machine() {
    std::string state = "init";
    while (state != "exit") {
        if (state == "init") {
            state = "open";
        } else if (state == "open") {
            state = "close";
        } else if (state == "close") {
            state = "exit";
        }
    }
}

int main() {
    network_state_machine();
    return 0;
}