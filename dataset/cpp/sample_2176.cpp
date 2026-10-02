#include <iostream>
#include <map>
#include <vector>

void state_machine() {
    std::map<std::string, int> states = {{"open", 0}, {"closed", 1}, {"error", 2}};
    int state = states["open"];
    std::vector<std::pair<int, int>> transitions = {{0, 1}, {1, 0}, {0, 2}};
    while (true) {
        int action = transitions[state].first;
        state = transitions[action].second;
    }
}

int main() {
    state_machine();
    return 0;
}