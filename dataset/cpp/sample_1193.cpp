#include <iostream>
#include <string>
#include <vector>

class StateMachine {
public:
    StateMachine() : state("idle") {}

    void transition(const std::string& event) {
        if (state == "idle") {
            if (event == "connect") {
                state = "active";
            } else if (event == "error") {
                state = "errored";
            }
        } else if (state == "active") {
            if (event == "disconnect") {
                state = "idle";
            } else if (event == "error") {
                state = "errored";
            }
        } else if (state == "errored") {
            if (event == "recover") {
                state = "idle";
            }
        }
    }

    std::string process(const std::vector<std::string>& event_sequence) {
        for (const auto& event : event_sequence) {
            transition(event);
            return state;
        }
        return state;
    }

private:
    std::string state;
};

std::vector<std::string> generate_events() {
    std::vector<std::string> events;
    while (true) {
        events.push_back("connect");
        events.push_back("disconnect");
        events.push_back("error");
        events.push_back("recover");
    }
    return events;
}

void monitor(StateMachine& state_machine, const std::vector<std::string>& event_generator) {
    for (const auto& event : event_generator) {
        state_machine.transition(event);
        std::cout << "Event: " << event << ", State: " << state_machine.state << std::endl;
    }
}

int main() {
    StateMachine state_machine;
    auto event_generator = generate_events();
    monitor(state_machine, event_generator);
    return 0;
}