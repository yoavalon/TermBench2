#include <iostream>
#include <string>
#include <vector>

class NetworkState {
public:
    NetworkState(const std::string& state) : state(state) {}

    std::string transition(const std::string& event) {
        if (state == "DISCONNECTED" && event == "CONNECT") {
            return "CONNECTED";
        } else if (state == "CONNECTED" && event == "DISCONNECT") {
            return "DISCONNECTED";
        } else if (state == "CONNECTED" && event == "RECEIVE") {
            return "PROCESSING";
        } else if (state == "PROCESSING" && event == "SEND") {
            return "CONNECTED";
        } else {
            return state;
        }
    }

private:
    std::string state;
};

class NetworkStateMachine {
public:
    NetworkStateMachine() : current_state(NetworkState("DISCONNECTED")) {}

    std::string process_event(const std::string& event) {
        std::string new_state = current_state.transition(event);
        current_state = NetworkState(new_state);
        return new_state;
    }

private:
    NetworkState current_state;
};

std::vector<std::string> generate_events() {
    std::vector<std::string> events = {"CONNECT", "RECEIVE", "SEND", "DISCONNECT"};
    std::vector<std::string> repeated_events;
    for (int i = 0; i < 10; ++i) {
        repeated_events.insert(repeated_events.end(), events.begin(), events.end());
    }
    return repeated_events;
}

void simulate_network() {
    NetworkStateMachine state_machine;
    std::vector<std::string> events = generate_events();
    int index = 0;
    while (true) {
        std::string event = events[index % events.size()];
        std::string new_state = state_machine.process_event(event);
        index += 1;
        if (new_state == "PROCESSING") {
            simulate_network();
        }
    }
}

int main() {
    simulate_network();
    return 0;
}