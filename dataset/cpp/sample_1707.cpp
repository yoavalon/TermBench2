#include <iostream>
#include <vector>
#include <string>

class ConnectionState {
public:
    ConnectionState() : state("DISCONNECTED") {
        states = {"DISCONNECTED", "CONNECTING", "CONNECTED", "DISCONNECTING"};
    }

    void transition(const std::string& event) {
        if (state == "DISCONNECTED" && event == "CONNECT") {
            state = "CONNECTING";
        } else if (state == "CONNECTING") {
            state = "CONNECTED";
        } else if (state == "CONNECTED" && event == "DISCONNECT") {
            state = "DISCONNECTING";
        } else if (state == "DISCONNECTING") {
            state = "DISCONNECTED";
        }
    }

    std::string current_state() {
        return state;
    }

private:
    std::string state;
    std::vector<std::string> states;
};

class EventGenerator {
public:
    EventGenerator() {
        events = {"CONNECT", "DISCONNECT"};
        index = 0;
    }

    std::string next_event() {
        std::string event = events[index];
        index = (index + 1) % events.size();
        return event;
    }

private:
    std::vector<std::string> events;
    int index;
};

class NetworkSimulator {
public:
    NetworkSimulator() {
        state_machine = ConnectionState();
        event_generator = EventGenerator();
    }

    void simulate() {
        while (true) {
            std::string event = event_generator.next_event();
            state_machine.transition(event);
            std::cout << state_machine.current_state() << std::endl;
        }
    }

private:
    ConnectionState state_machine;
    EventGenerator event_generator;
};

int main() {
    NetworkSimulator simulator;
    simulator.simulate();
    return 0;
}