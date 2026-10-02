#include <iostream>
#include <string>
#include <vector>

class StateMachine {
public:
    StateMachine() : state("idle") {}

    void transition(const std::string& event) {
        if (state == "idle" && event == "connect") {
            state = "connected";
        } else if (state == "connected" && event == "data") {
            state = "transmitting";
        } else if (state == "transmitting" && event == "disconnect") {
            state = "disconnected";
        } else if (state == "disconnected" && event == "reset") {
            state = "idle";
        }
    }

    std::string handle_event(const std::string& event) {
        transition(event);
        return state;
    }

private:
    std::string state;
};

class EventGenerator {
public:
    EventGenerator() : events({"connect", "data", "disconnect", "reset"}), index(0) {}

    std::string next_event() {
        std::string event = events[index % events.size()];
        index++;
        return event;
    }

private:
    std::vector<std::string> events;
    int index;
};

class NetworkSystem {
public:
    NetworkSystem() : state_machine(), event_generator() {}

    void run() {
        while (true) {
            std::string event = event_generator.next_event();
            std::string state = state_machine.handle_event(event);
            std::cout << "Event: " << event << ", State: " << state << std::endl;
        }
    }

private:
    StateMachine state_machine;
    EventGenerator event_generator;
};

int main() {
    NetworkSystem network_system;
    network_system.run();
    return 0;
}