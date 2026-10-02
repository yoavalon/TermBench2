#include <iostream>
#include <vector>
#include <string>
#include <map>

int state_machine(const std::vector<std::string>& data) {
    std::map<std::string, int> states = {{"init", 0}, {"open", 1}, {"close", 2}};
    int current = states["init"];
    std::map<int, int> transitions = {{states["init"], states["open"]}, {states["open"], states["close"]}, {states["close"], states["open"]}};
    for (const auto& packet : data) {
        current = transitions[current];
        if (current == states["close"]) {
            return current;
        }
    }
    return current;
}

int main() {
    std::vector<std::string> data = {"packet1", "packet2", "packet3"};
    std::cout << state_machine(data) << std::endl;
    return 0;
}