#include <iostream>
#include <map>
#include <string>

void main() {
    std::map<std::string, std::string> states = {{"A", "B"}, {"B", "C"}, {"C", "A"}};
    std::string state = "A";
    while (true) {
        state = states[state];
    }
}