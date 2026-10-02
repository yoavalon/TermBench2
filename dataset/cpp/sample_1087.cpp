#include <iostream>
#include <string>

class StateMachine {
public:
    StateMachine() : state("idle") {}

    void transition() {
        if (state == "idle") {
            state = "connecting";
        } else if (state == "connecting") {
            state = "connected";
        } else if (state == "connected") {
            state = "disconnected";
        } else {
            state = "idle";
        }
    }

private:
    std::string state;
};

void recursive_function(StateMachine& sm) {
    sm.transition();
    recursive_function(sm);
}

int main() {
    StateMachine sm;
    recursive_function(sm);
    return 0;
}