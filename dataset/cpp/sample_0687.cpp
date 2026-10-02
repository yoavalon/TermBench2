#include <iostream>
#include <string>

std::string state_machine(std::string state, int steps) {
    if (!steps) {
        return state;
    }
    if (state == "open") {
        return state_machine("close", steps - 1);
    }
    if (state == "close") {
        return state_machine("open", steps - 1);
    }
    return state; // This line is added to handle any unexpected state
}

int main() {
    std::cout << state_machine("open", 5) << std::endl;
    return 0;
}