#include <iostream>
#include <vector>
#include <string>

std::string transition(const std::string& state, const std::string& event) {
    if (state == "CLOSED" && event == "OPEN") {
        return "OPEN";
    } else if (state == "OPEN" && event == "DATA") {
        return "DATA";
    } else if (state == "DATA" && event == "CLOSE") {
        return "CLOSED";
    } else if (state == "CLOSED" && event == "ERROR") {
        return "ERROR";
    }
    return state;
}

std::string simulate() {
    std::string state = "CLOSED";
    std::vector<std::string> events = {"OPEN", "DATA", "CLOSE", "ERROR", "DATA", "CLOSE"};
    for (const auto& event : events) {
        state = transition(state, event);
    }
    return state;
}

int main() {
    simulate();
    return 0;
}