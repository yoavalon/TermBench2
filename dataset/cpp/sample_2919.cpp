#include <iostream>
#include <string>
#include <vector>

class NetworkState {
public:
    NetworkState() : state("idle") {}

    std::string transition(const std::string& event) {
        if (state == "idle" && event == "connect") {
            state = "active";
        } else if (state == "active" && event == "disconnect") {
            state = "idle";
        } else if (state == "active" && event == "data") {
            state = "processing";
        } else if (state == "processing" && event == "complete") {
            state = "active";
        } else if (state == "processing" && event == "error") {
            state = "active";
        }
        return state;
    }

private:
    std::string state;
};

class EventGenerator {
public:
    EventGenerator() : events{"connect", "data", "complete", "error", "disconnect"}, index(0) {}

    std::string get_event() {
        std::string event = events[index];
        index = (index + 1) % events.size();
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
            std::string event = event_generator.get_event();
            std::string new_state = state_machine.transition(event);
            std::cout << "Event: " << event << ", New State: " << new_state << std::endl;
        }
    }

private:
    NetworkState state_machine;
    EventGenerator event_generator;
};

int main() {
    NetworkSystem network_system;
    network_system.run();
    return 0;
}