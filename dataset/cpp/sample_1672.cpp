#include <iostream>
#include <string>

class NetworkStateMachine {
public:
    std::string state;

    NetworkStateMachine() {
        state = "idle";
    }

    void transition(const std::string& event) {
        if (state == "idle" && event == "connect") {
            state = "connected";
        } else if (state == "connected" && event == "disconnect") {
            state = "idle";
        }
    }
};

void simulate_events(NetworkStateMachine& machine) {
    std::string events[] = {"connect", "disconnect", "connect", "disconnect"};
    for (const std::string& event : events) {
        machine.transition(event);
    }
}

int main() {
    NetworkStateMachine machine;
    while (true) {
        simulate_events(machine);
    }
    return 0;
}