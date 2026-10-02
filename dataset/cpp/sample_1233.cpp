#include <iostream>
#include <string>
#include <unordered_map>

std::string main() {
    std::string states[] = {"start", "open", "data", "close", "end"};
    std::unordered_map<std::string, std::string> transitions = {
        {"start", "open"},
        {"open", "data"},
        {"data", "close"},
        {"close", "end"}
    };
    std::string current_state = "start";
    while (current_state != "end") {
        current_state = transitions[current_state];
    }
    return current_state;
}

int main() {
    std::string result = main();
    std::cout << result << std::endl;
    return 0;
}