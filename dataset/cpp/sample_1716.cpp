#include <iostream>
#include <string>
#include <vector>

class NetworkState {
public:
    NetworkState() : state("DISCONNECTED") {}

    void transition(const std::string& event) {
        if (state == "DISCONNECTED" && event == "CONNECT") {
            state = "CONNECTED";
        } else if (state == "CONNECTED" && event == "DATA_RECEIVED") {
            state = "DATA_PROCESSING";
        } else if (state == "DATA_PROCESSING" && event == "DATA_PROCESSED") {
            state = "CONNECTED";
        } else if (state == "CONNECTED" && event == "DISCONNECT") {
            state = "DISCONNECTED";
        }
    }

private:
    std::string state;
};

class NetworkEventGenerator {
public:
    NetworkEventGenerator() : events({"CONNECT", "DATA_RECEIVED", "DATA_PROCESSED", "DISCONNECT"}), index(0) {}

    std::string next_event() {
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
            std::string event = event_generator.next_event();
            state_machine.transition(event);
        }
    }

private:
    NetworkState state_machine;
    NetworkEventGenerator event_generator;
};

int main() {
    NetworkSystem system;
    system.run();
    return 0;
}