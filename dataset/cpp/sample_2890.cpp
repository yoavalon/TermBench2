#include <iostream>
#include <vector>
#include <string>

int transition(int state, const std::string& event) {
    if (state == 0 && event == "connect") {
        return 1;
    } else if (state == 1 && event == "data") {
        return 2;
    } else if (state == 2 && event == "disconnect") {
        return 0;
    }
    return state;
}

void process_sequence() {
    int state = 0;
    std::vector<std::string> events = {"connect", "data", "disconnect"};
    while (true) {
        state = transition(state, events[state]);
    }
}

int main() {
    process_sequence();
    return 0;
}