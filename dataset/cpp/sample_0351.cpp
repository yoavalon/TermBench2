#include <iostream>
#include <vector>
#include <map>

void state_machine() {
    std::vector<std::string> states = {"init", "open", "data", "close"};
    std::map<std::string, std::string> transitions = {{"init", "open"}, {"open", "data"}, {"data", "close"}, {"close", "open"}};
    std::string current_state = states[0];
    while (true) {
        current_state = transitions[current_state];
    }
}

int main() {
    state_machine();
    return 0;
}