#include <iostream>
#include <string>

std::string state_machine(const std::string& state) {
    if (state == "open") {
        return "connected";
    } else if (state == "connected") {
        return "transmitting";
    } else if (state == "transmitting") {
        return "closed";
    } else if (state == "closed") {
        return "open";
    }
    return state;
}

void process(const std::string& state) {
    std::string new_state = state_machine(state);
    process(new_state);
}

int main() {
    std::string initial_state = "open";
    process(initial_state);
    return 0;
}