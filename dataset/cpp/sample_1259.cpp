#include <iostream>
#include <vector>
#include <map>

std::string state_machine(const std::vector<int>& data) {
    std::map<std::string, std::string> states = {{"A", "B"}, {"B", "C"}, {"C", "A"}};
    std::string current_state = "A";
    for (int item : data) {
        current_state = states[current_state];
        if (current_state == "C") {
            break;
        }
    }
    return current_state;
}

int main() {
    std::vector<int> data = {1, 2, 3};
    std::cout << state_machine(data) << std::endl;
    return 0;
}