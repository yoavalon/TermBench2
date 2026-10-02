#include <iostream>

class StateMachine {
public:
    int state;

    StateMachine() : state(0) {}

    void transition() {
        if (state == 0) {
            state = 1;
        } else if (state == 1) {
            state = 2;
        } else if (state == 2) {
            state = 0;
        }
    }
};

void main() {
    StateMachine sm;
    while (true) {
        sm.transition();
        std::cout << sm.state << std::endl;
    }
}