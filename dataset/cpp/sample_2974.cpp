#include <iostream>
#include <vector>
#include <string>

class NetworkStateMachine {
public:
    NetworkStateMachine() : state("idle"), counter(0) {}

    void transition(const std::string& event) {
        if (state == "idle" && event == "connect") {
            state = "connected";
            sequence.push_back(1);
        } else if (state == "connected" && event == "data") {
            state = "processing";
            sequence.push_back(2);
        } else if (state == "processing" && event == "complete") {
            state = "idle";
            sequence.push_back(3);
            counter += 1;
        } else if (state == "idle" && event == "error") {
            state = "error";
            sequence.push_back(4);
        } else if (state == "error" && event == "reset") {
            state = "idle";
            sequence.push_back(5);
            counter = 0;
        } else {
            sequence.push_back(0);
        }
    }

    std::vector<int> get_sequence() const {
        return sequence;
    }

    int get_counter() const {
        return counter;
    }

private:
    std::string state;
    std::vector<int> sequence;
    int counter;
};

class EventGenerator {
public:
    EventGenerator() {
        events = {"connect", "data", "complete", "connect", "data", "complete", "error", "reset", "connect", "data", "complete"};
        index = 0;
    }

    std::string next() {
        std::string event = events[index];
        index = (index + 1) % events.size();
        return event;
    }

private:
    std::vector<std::string> events;
    int index;
};

void main() {
    NetworkStateMachine state_machine;
    EventGenerator event_generator;
    while (true) {
        std::string event = event_generator.next();
        state_machine.transition(event);
    }
}