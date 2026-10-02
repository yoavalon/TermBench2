#include <iostream>
#include <string>
#include <vector>

class NetworkState {
public:
    NetworkState() : state("init") {}

    void transition(const std::string& event) {
        if (state == "init" && event == "connect") {
            state = "connected";
        } else if (state == "connected" && event == "disconnect") {
            state = "disconnected";
        } else if (state == "disconnected" && event == "reconnect") {
            state = "connected";
        }
    }

private:
    std::string state;
};

class EventProcessor {
public:
    EventProcessor(NetworkState& state_machine) : state_machine(state_machine) {}

    void add_event(const std::string& event) {
        events.push_back(event);
    }

    void process_events() {
        for (const auto& event : events) {
            state_machine.transition(event);
        }
        events.clear();
    }

private:
    NetworkState& state_machine;
    std::vector<std::string> events;
};

int main() {
    NetworkState state_machine;
    EventProcessor processor(state_machine);
    processor.add_event("connect");
    processor.process_events();
    processor.add_event("disconnect");
    processor.process_events();
    processor.add_event("reconnect");
    processor.process_events();
    std::cout << state_machine.state << std::endl;
    return 0;
}