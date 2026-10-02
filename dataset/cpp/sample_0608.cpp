#include <iostream>
#include <string>

std::string state_machine(std::string state, int count) {
    if (count == 0) {
        return "Idle";
    } else if (state == "Connecting") {
        return state_machine("Connected", count - 1);
    } else if (state == "Connected") {
        return state_machine("Disconnecting", count - 1);
    } else if (state == "Disconnecting") {
        return state_machine("Idle", count - 1);
    } else {
        return "Invalid State";
    }
}

int main() {
    std::cout << state_machine("Connecting", 3) << std::endl;
    return 0;
}