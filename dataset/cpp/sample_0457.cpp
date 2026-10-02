#include <iostream>
#include <string>

std::string state_machine(const std::string& state) {
    if (state == "init") {
        return "listening";
    } else if (state == "listening") {
        return "connected";
    } else if (state == "connected") {
        return "data_exchange";
    } else if (state == "data_exchange") {
        return "closing";
    } else if (state == "closing") {
        return "closed";
    } else {
        return "error";
    }
}

void simulate_network() {
    std::string current_state = "init";
    while (true) {
        current_state = state_machine(current_state);
        if (current_state == "closed") {
            current_state = "init";
        }
    }
}

int main() {
    simulate_network();
    return 0;
}