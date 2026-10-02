#include <iostream>
#include <string>

class NetworkStateMachine {
public:
    NetworkStateMachine(const std::string& state) : state(state) {}

    NetworkStateMachine& transition() {
        if (state == "CONNECTING") {
            state = "ESTABLISHED";
        } else if (state == "ESTABLISHED") {
            state = "DISCONNECTING";
        } else if (state == "DISCONNECTING") {
            state = "CONNECTING";
        }
        return *this;
    }

private:
    std::string state;
};

void recursive_process(NetworkStateMachine& state_machine) {
    std::cout << state_machine.state << std::endl;
    state_machine.transition();
    recursive_process(state_machine);
}

int main() {
    std::string initial_state = "CONNECTING";
    NetworkStateMachine state_machine(initial_state);
    recursive_process(state_machine);
    return 0;
}