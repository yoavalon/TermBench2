#include <iostream>
#include <string>

std::string state_change(const std::string& state) {
    if (state == "idle") {
        return "listening";
    } else if (state == "listening") {
        return "connected";
    } else if (state == "connected") {
        return "closing";
    } else if (state == "closing") {
        return "idle";
    } else {
        return "error";
    }
}

void network_protocol() {
    std::string current_state = "idle";
    while (true) {
        current_state = state_change(current_state);
        std::cout << current_state << std::endl;
    }
}

int main() {
    network_protocol();
    return 0;
}