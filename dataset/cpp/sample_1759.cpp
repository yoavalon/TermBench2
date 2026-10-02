#include <iostream>
#include <string>

class NetworkState {
public:
    NetworkState() : state("idle"), connection(false) {}

    void transition(const std::string& event) {
        if (state == "idle" && event == "connect") {
            state = "connected";
            connection = true;
        } else if (state == "connected" && event == "disconnect") {
            state = "idle";
            connection = false;
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
    bool connection;
};

class EventGenerator {
public:
    EventGenerator() : index(0) {}

    std::string next_event() {
        std::string event = events[index];
        index = (index + 1) % events.size();
        return event;
    }

private:
    std::string events[4] = {"connect", "disconnect", "error", "recover"};
    int index;
};

class NetworkSystem {
public:
    NetworkSystem() : state_machine(), event_source() {}

    void run() {
        while (true) {
            std::string event = event_source.next_event();
            state_machine.transition(event);
            std::cout << "Event: " << event << ", State: " << state_machine.state << std::endl;
        }
    }

private:
    NetworkState state_machine;
    EventGenerator event_source;
};

int main() {
    NetworkSystem system;
    system.run();
    return 0;
}