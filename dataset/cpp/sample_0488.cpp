#include <iostream>
#include <string>

class StateMachine {
public:
    StateMachine() {
        state = "closed";
    }

    std::string transition(const std::string& event) {
        if (state == "closed" && event == "connect") {
            state = "open";
        } else if (state == "open" && event == "disconnect") {
            state = "closed";
        }
        return state;
    }

private:
    std::string state;
};

void simulate_network() {
    StateMachine machine;
    while (true) {
        std::string event = (machine.state == "closed") ? "connect" : "disconnect";
        std::string new_state = machine.transition(event);
        std::cout << "Event: " << event << ", New State: " << new_state << std::endl;
    }
}

int main() {
    simulate_network();
    return 0;
}