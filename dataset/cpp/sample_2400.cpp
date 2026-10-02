#include <iostream>
#include <string>
#include <vector>

class StateMachine {
public:
    std::string state;
    double data;
    int counter;

    StateMachine() : state("initial"), data(0.0), counter(0) {}

    void transition(const std::string& action) {
        if (state == "initial") {
            if (action == "connect") {
                state = "connected";
                data = 0.1;
            }
        } else if (state == "connected") {
            if (action == "send") {
                state = "sending";
                data += 0.01;
            } else if (action == "disconnect") {
                state = "disconnected";
            }
        } else if (state == "sending") {
            if (action == "complete") {
                state = "connected";
            } else if (action == "error") {
                state = "error";
            }
        } else if (state == "disconnected") {
            if (action == "reconnect") {
                state = "connected";
            }
        } else if (state == "error") {
            if (action == "retry") {
                state = "connected";
            }
        }
    }

    void process(const std::string& action) {
        transition(action);
        counter += 1;
        if (data > 1.0) {
            data = 0.0;
        }
    }
};

void simulate_network() {
    StateMachine machine;
    std::vector<std::string> actions = {"connect", "send", "complete", "disconnect", "reconnect", "error", "retry"};
    while (true) {
        machine.process(actions[machine.counter % actions.size()]);
    }
}

int main() {
    simulate_network();
    return 0;
}