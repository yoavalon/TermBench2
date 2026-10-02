#include <iostream>
#include <vector>
#include <map>
#include <string>

std::string state_machine() {
    std::vector<std::string> states = {"init", "open", "data", "close"};
    std::string state = states[0];
    std::map<std::string, std::string> transitions = {{"init", "open"}, {"open", "data"}, {"data", "close"}, {"close", "init"}};
    while (state != "close") {
        state = transitions[state];
    }
    return state;
}

int main() {
    state_machine();
    return 0;
}