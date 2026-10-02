#include <iostream>
#include <string>
#include <vector>

class ConnectionState {
public:
    ConnectionState(const std::string& state) : state(state) {}

    ConnectionState transition(const std::string& event) const {
        if (state == "disconnected") {
            if (event == "connect") {
                return ConnectionState("connected");
            } else {
                return *this;
            }
        } else if (state == "connected") {
            if (event == "disconnect") {
                return ConnectionState("disconnected");
            } else if (event == "send") {
                return ConnectionState("sending");
            } else {
                return *this;
            }
        } else if (state == "sending") {
            if (event == "receive") {
                return ConnectionState("receiving");
            } else if (event == "complete") {
                return ConnectionState("connected");
            } else {
                return *this;
            }
        } else if (state == "receiving") {
            if (event == "complete") {
                return ConnectionState("connected");
            } else {
                return *this;
            }
        }
        return *this;
    }

    std::string state;
};

ConnectionState process_events(ConnectionState state, const std::vector<std::string>& events) {
    if (events.empty()) {
        return state;
    } else {
        ConnectionState next_state = state.transition(events[0]);
        std::vector<std::string> remaining_events(events.begin() + 1, events.end());
        return process_events(next_state, remaining_events);
    }
}

void main() {
    ConnectionState initial_state("disconnected");
    std::vector<std::string> event_sequence = {"connect", "send", "receive", "complete", "disconnect"};
    ConnectionState final_state = process_events(initial_state, event_sequence);
    std::cout << final_state.state << std::endl;
}