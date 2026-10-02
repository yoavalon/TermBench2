#include <iostream>
#include <string>
#include <vector>

class StateMachine {
public:
    StateMachine() : state("idle"), connection(nullptr) {}

    void transition(const std::string& event) {
        if (state == "idle" && event == "connect") {
            state = "connected";
            connection = "active";
        } else if (state == "connected" && event == "disconnect") {
            state = "idle";
            connection = nullptr;
        } else if (state == "connected" && event == "data") {
            state = "processing";
        } else if (state == "processing" && event == "complete") {
            state = "connected";
        } else if (state == "connected" && event == "error") {
            state = "error";
            connection = nullptr;
        } else if (state == "error" && event == "reset") {
            state = "idle";
        }
    }

private:
    std::string state;
    std::string* connection;
};

class EventGenerator {
public:
    EventGenerator() : index(0) {
        events = {"connect", "disconnect", "data", "complete", "error", "reset"};
    }

    std::string generate() {
        std::string event = events[index];
        index = (index + 1) % events.size();
        return event;
    }

private:
    std::vector<std::string> events;
    int index;
};

void main() {
    StateMachine machine;
    EventGenerator generator;
    for (int i = 0; i < 20; ++i) {
        std::string event = generator.generate();
        machine.transition(event);
        std::cout << "Event: " << event << ", State: " << machine.state << ", Connection: " 
                  << (machine.connection ? *machine.connection : "None") << std::endl;
    }
}

int main() {
    main();
    return 0;
}