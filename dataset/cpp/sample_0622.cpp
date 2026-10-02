#include <iostream>
#include <string>

std::string state_machine(std::string state, int count, int max_count) {
    if (count >= max_count) {
        return "Terminated";
    }
    if (state == "CONNECTING") {
        return state_machine("OPEN", count + 1, max_count);
    }
    if (state == "OPEN") {
        return state_machine("CLOSING", count + 1, max_count);
    }
    if (state == "CLOSING") {
        return state_machine("DISCONNECTED", count + 1, max_count);
    }
    if (state == "DISCONNECTED") {
        return state_machine("RECONNECTING", count + 1, max_count);
    }
    if (state == "RECONNECTING") {
        return state_machine("CONNECTING", count + 1, max_count);
    }
    return "";
}

int main() {
    std::string result = state_machine("CONNECTING", 0, 10);
    std::cout << result << std::endl;
    return 0;
}