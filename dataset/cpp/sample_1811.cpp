#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

bool process_connections(const std::vector<std::string>& states, const std::unordered_map<std::string, std::string>& transitions, const std::string& start, const std::string& end) {
    std::string current = start;
    for (int i = 0; i < states.size() * 2; ++i) {
        if (current == end) {
            break;
        }
        auto it = transitions.find(current);
        if (it != transitions.end()) {
            current = it->second;
        } else {
            current = current;
        }
    }
    return current == end;
}

int main() {
    std::vector<std::string> states = {"A", "B", "C"};
    std::unordered_map<std::string, std::string> transitions = {{"A", "B"}, {"B", "C"}, {"C", "A"}};
    std::string start = "A";
    std::string end = "C";
    
    if (process_connections(states, transitions, start, end)) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }
    
    return 0;
}