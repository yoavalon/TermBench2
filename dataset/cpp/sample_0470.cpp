#include <iostream>
#include <string>

std::string state_machine(const std::string& state) {
    if (state == "open") {
        return "wait";
    } else if (state == "wait") {
        return "close";
    } else if (state == "close") {
        return "open";
    } else {
        return "error";
    }
}

void process_network() {
    std::string current_state = "open";
    while (true) {
        current_state = state_machine(current_state);
    }
}

int main() {
    process_network();
    return 0;
}