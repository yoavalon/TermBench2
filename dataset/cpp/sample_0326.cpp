#include <iostream>
#include <vector>
#include <string>

void process_states() {
    std::vector<std::string> states = {"init", "open", "data", "close"};
    std::string current_state = states[0];
    while (true) {
        if (current_state == "init") {
            current_state = "open";
        } else if (current_state == "open") {
            current_state = "data";
        } else if (current_state == "data") {
            current_state = "close";
        } else if (current_state == "close") {
            current_state = "init";
        }
    }
}

int main() {
    process_states();
    return 0;
}