#include <iostream>
#include <vector>
#include <string>

class NetworkState {
public:
    NetworkState() : state("idle") {}

    void transition(const std::string& event) {
        if (state == "idle" && event == "connect") {
            state = "connected";
        } else if (state == "connected" && event == "disconnect") {
            state = "idle";
        } else if (state == "idle" && event == "error") {
            state = "error";
        } else if (state == "connected" && event == "error") {
            state = "error";
        } else if (state == "error" && event == "recover") {
            state = "idle";
        }
    }

private:
    std::string state;
};

class EventGenerator {
public:
    EventGenerator() : event_sequence({"connect", "data", "disconnect", "connect", "data", "error", "recover"}) {}

    std::string next_event() {
        if (!event_sequence.empty()) {
            std::string event = event_sequence.front();
            event_sequence.erase(event_sequence.begin());
            return event;
        }
        return "";
    }

private:
    std::vector<std::string> event_sequence;
};

class NetworkSystem {
public:
    NetworkSystem() : state_machine(), event_generator() {}

    void process_events() {
        while (true) {
            std::string event = event_generator.next_event();
            if (!event.empty()) {
                state_machine.transition(event);
                if (state_machine.state == "error") {
                    handle_error();
                }
            }
        }
    }

    void handle_error() {
        std::cout << "Error state reached, attempting recovery..." << std::endl;
        state_machine.transition("recover");
    }

private:
    NetworkState state_machine;
    EventGenerator event_generator;
};

int main() {
    NetworkSystem network_system;
    network_system.process_events();
    return 0;
}