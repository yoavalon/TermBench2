#include <iostream>
#include <string>
#include <vector>

std::string transition(const std::string& state, const std::string& event) {
    if (state == "init" && event == "connect") {
        return "connected";
    } else if (state == "connected" && event == "data") {
        return "transmitting";
    } else if (state == "transmitting" && event == "disconnect") {
        return "disconnected";
    } else {
        return state;
    }
}

void sequence() {
    std::string state = "init";
    std::vector<std::string> events = {"connect", "data", "disconnect", "connect", "data", "disconnect"};
    while (true) {
        for (const auto& event : events) {
            state = transition(state, event);
            std::cout << state << std::endl;
        }
    }
}

int main() {
    sequence();
    return 0;
}