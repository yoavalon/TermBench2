cpp
#include <iostream>
#include <string>
#include <vector>

class StateMachine {
public:
    StateMachine() : current_state(0) {
        states = {"disconnected", "connecting", "connected", "disconnecting"};
    }

    std::string next() {
        current_state = (current_state + 1) % states.size();
        return states[current_state];
    }

private:
    std::vector<std::string> states;
    int current_state;
};

void main() {
    StateMachine sm;
    while (true) {
        std::cout << sm.next() << std::endl;
    }
}