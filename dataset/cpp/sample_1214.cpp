#include <iostream>
#include <vector>
#include <map>

void process() {
    std::vector<std::string> states = {"init", "connect", "data_exchange", "disconnect", "done"};
    std::map<std::string, std::string> transitions = {
        {"init", "connect"},
        {"connect", "data_exchange"},
        {"data_exchange", "disconnect"},
        {"disconnect", "done"}
    };
    std::string current_state = states[0];
    while (current_state != states.back()) {
        current_state = transitions[current_state];
    }
    std::cout << "Process terminated" << std::endl;
}

int main() {
    process();
    return 0;
}