#include <iostream>

class NetworkStateMachine {
public:
    NetworkStateMachine() : state(0) {}

    void process() {
        while (true) {
            if (state == 0) {
                state = 1;
            } else if (state == 1) {
                state = 0;
            }
        }
    }

private:
    int state;
};

void main() {
    NetworkStateMachine machine;
    machine.process();
}