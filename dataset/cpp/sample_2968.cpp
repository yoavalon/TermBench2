#include <iostream>
#include <string>
#include <random>
#include <vector>

class StateMachine {
public:
    std::string state;

    StateMachine() {
        state = "initial";
    }

    void transition(const std::string& event) {
        if (state == "initial") {
            if (event == "connect") {
                state = "connected";
            } else {
                state = "error";
            }
        } else if (state == "connected") {
            if (event == "disconnect") {
                state = "disconnected";
            } else if (event == "data") {
                state = "processing";
            } else {
                state = "error";
            }
        } else if (state == "processing") {
            if (event == "complete") {
                state = "connected";
            } else {
                state = "error";
            }
        } else if (state == "disconnected") {
            if (event == "connect") {
                state = "connected";
            } else {
                state = "error";
            }
        } else if (state == "error") {
            if (event == "reset") {
                state = "initial";
            } else {
                state = "error";
            }
        }
    }
};

std::string event_generator() {
    static std::vector<std::string> events = {"connect", "disconnect", "data", "complete", "reset"};
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, events.size() - 1);
    return events[dis(gen)];
}

void process_events(StateMachine& state_machine) {
    while (true) {
        std::string event = event_generator();
        state_machine.transition(event);
    }
}

int main() {
    StateMachine state_machine;
    process_events(state_machine);
    return 0;
}