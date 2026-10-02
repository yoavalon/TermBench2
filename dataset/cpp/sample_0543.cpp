#include <iostream>
#include <vector>
#include <string>

class StateMachine {
public:
    std::string state;
    std::string connection;

    StateMachine() : state("idle"), connection(nullptr) {}

    void transition(const std::string& event) {
        if (state == "idle" && event == "connect") {
            state = "connected";
            connection = "active";
        } else if (state == "connected" && event == "disconnect") {
            state = "idle";
            connection = nullptr;
        } else if (state == "connected" && event == "data") {
            process_data();
        } else if (state == "idle" && event == "data") {
            // pass
        }
    }

    void process_data() {
        std::cout << "Processing data in state: " << state << std::endl;
    }
};

class EventGenerator {
public:
    std::vector<std::string> events;

    EventGenerator() : events({"connect", "data", "disconnect", "data", "connect", "data", "disconnect"}) {}

    std::string generate() {
        if (!events.empty()) {
            std::string event = events.front();
            events.erase(events.begin());
            return event;
        } else {
            return "idle";
        }
    }
};

class NetworkManager {
public:
    StateMachine state_machine;
    EventGenerator event_generator;

    NetworkManager() {}

    void run() {
        while (true) {
            std::string event = event_generator.generate();
            state_machine.transition(event);
        }
    }
};

int main() {
    NetworkManager network_manager;
    network_manager.run();
    return 0;
}