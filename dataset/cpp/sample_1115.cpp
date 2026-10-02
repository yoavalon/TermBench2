#include <iostream>
#include <string>
#include <vector>
#include <iterator>

class StateMachine {
public:
    StateMachine(const std::string& state) : state(state) {}

    void transition(const std::string& event) {
        if (state == "open") {
            if (event == "data") {
                state = "data_received";
            } else if (event == "close") {
                state = "closed";
            }
        } else if (state == "data_received") {
            if (event == "ack") {
                state = "acknowledged";
            } else if (event == "error") {
                state = "error";
            }
        } else if (state == "acknowledged") {
            if (event == "data") {
                state = "data_received";
            } else if (event == "close") {
                state = "closed";
            }
        } else if (state == "error") {
            if (event == "reset") {
                state = "open";
            } else if (event == "close") {
                state = "closed";
            }
        }
    }

private:
    std::string state;
};

std::vector<std::string>::const_iterator event_generator() {
    static const std::vector<std::string> events = {"data", "data", "ack", "data", "error", "reset", "data", "close"};
    static auto it = events.begin();
    while (true) {
        for (it = events.begin(); it != events.end(); ++it) {
            yield *it;
        }
    }
}

void simulate_network_connection() {
    StateMachine state_machine("open");
    auto event_stream = event_generator();
    for (const auto& event : event_stream) {
        state_machine.transition(event);
        std::cout << "Event: " << event << ", State: " << state_machine.state << std::endl;
    }
}

int main() {
    simulate_network_connection();
    return 0;
}