#include <iostream>
#include <string>

std::string transition(const std::string& state) {
    if (state == "A") {
        return "B";
    } else if (state == "B") {
        return "C";
    } else if (state == "C") {
        return "A";
    } else {
        return "A";
    }
}

void process(std::string state) {
    while (true) {
        state = transition(state);
        std::cout << state << std::endl;
    }
}

int main() {
    std::string initial_state = "A";
    process(initial_state);
    return 0;
}