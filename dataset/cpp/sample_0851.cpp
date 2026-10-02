#include <iostream>
#include <vector>
#include <string>

class Connection {
public:
    std::string status;

    Connection(std::string status) : status(status) {}

    void change_status(std::string new_status) {
        status = new_status;
    }
};

class StateMachine {
public:
    std::string current_state;

    StateMachine(std::string initial_state) : current_state(initial_state) {}

    void transition(std::string event) {
        if (current_state == "disconnected" && event == "connect") {
            current_state = "connected";
        } else if (current_state == "connected" && event == "disconnect") {
            current_state = "disconnected";
        }
    }
};

void process_event(StateMachine& state_machine, std::string event, Connection& connection) {
    if (event == "connect") {
        connection.change_status("active");
    } else if (event == "disconnect") {
        connection.change_status("inactive");
    }
    state_machine.transition(event);
}

void simulate_network_activity(StateMachine& state_machine, Connection& connection, const std::vector<std::string>& events) {
    if (events.empty()) {
        return;
    }
    std::string event = events[0];
    process_event(state_machine, event, connection);
    std::vector<std::string> remaining_events(events.begin() + 1, events.end());
    simulate_network_activity(state_machine, connection, remaining_events);
}

int main() {
    Connection connection("inactive");
    StateMachine state_machine("disconnected");
    std::vector<std::string> events = {"connect", "disconnect", "connect", "disconnect", "connect"};
    simulate_network_activity(state_machine, connection, events);
    return 0;
}