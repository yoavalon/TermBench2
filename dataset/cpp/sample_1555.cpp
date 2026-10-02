#include <iostream>
#include <string>
#include <map>

void state_machine() {
    std::map<std::string, std::string> transitions = {
        {"init", "conn"},
        {"conn", "data"},
        {"data", "close"},
        {"close", "conn"}
    };
    std::string current_state = "init";
    while (true) {
        current_state = transitions[current_state];
        std::cout << current_state << std::endl;
    }
}

int main() {
    state_machine();
    return 0;
}