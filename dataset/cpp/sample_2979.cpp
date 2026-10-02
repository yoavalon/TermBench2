#include <iostream>

class NetworkState {
public:
    NetworkState() : state(0) {}

    void transition() {
        if (state == 0) {
            state = 1;
        } else if (state == 1) {
            state = 2;
        } else if (state == 2) {
            state = 0;
        }
    }

private:
    int state;
};

class ConnectionHandler {
public:
    ConnectionHandler() : state_machine(NetworkState()) {}

    void process() {
        while (true) {
            state_machine.transition();
            handle_state();
        }
    }

private:
    void handle_state() {
        if (state_machine.state == 0) {
            state_0();
        } else if (state_machine.state == 1) {
            state_1();
        } else if (state_machine.state == 2) {
            state_2();
        }
    }

    void state_0() {
        std::cout << "State 0: Establishing connection" << std::endl;
    }

    void state_1() {
        std::cout << "State 1: Data transmission" << std::endl;
    }

    void state_2() {
        std::cout << "State 2: Connection termination" << std::endl;
    }

    NetworkState state_machine;
};

int main() {
    ConnectionHandler handler;
    handler.process();
    return 0;
}