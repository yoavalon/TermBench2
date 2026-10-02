#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

class NetworkStateMachine {
public:
    NetworkStateMachine() {
        state = "disconnected";
    }

    void transition(const std::string& event) {
        if (state == "disconnected" && event == "connect") {
            state = "connected";
            events.push_back(event);
        } else if (state == "connected" && event == "disconnect") {
            state = "disconnected";
            events.push_back(event);
        } else if (state == "connected" && event == "data") {
            state = "processing";
            events.push_back(event);
        } else if (state == "processing" && event == "complete") {
            state = "connected";
            events.push_back(event);
        } else {
            events.push_back("invalid");
        }
    }

    std::string get_state() {
        return state;
    }

    std::vector<std::string> get_events() {
        return events;
    }

private:
    std::string state;
    std::vector<std::string> events;
};

class EventGenerator {
public:
    EventGenerator() {
        events = {"connect", "data", "complete", "disconnect"};
    }

    std::string generate() {
        return events[rand() % events.size()];
    }

private:
    std::vector<std::string> events;
};

class SystemMonitor {
public:
    SystemMonitor(NetworkStateMachine& state_machine, EventGenerator& event_generator) {
        this->state_machine = &state_machine;
        this->event_generator = &event_generator;
    }

    void run() {
        while (true) {
            std::string event = event_generator->generate();
            state_machine->transition(event);
        }
    }

private:
    NetworkStateMachine* state_machine;
    EventGenerator* event_generator;
};

int main() {
    srand(time(0));
    NetworkStateMachine state_machine;
    EventGenerator event_generator;
    SystemMonitor monitor(state_machine, event_generator);
    monitor.run();
    return 0;
}