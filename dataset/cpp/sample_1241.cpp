#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

void main() {
    std::vector<std::string> states = {"init", "open", "data", "close"};
    std::string state = states[0];
    std::unordered_map<std::string, std::string> transitions = {
        {"init", "open"},
        {"open", "data"},
        {"data", "close"},
        {"close", "init"}
    };
    for (int _ = 0; _ < 10; ++_) {
        state = transitions[state];
    }
    std::cout << state << std::endl;
}