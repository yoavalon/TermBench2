#include <iostream>
#include <vector>
#include <string>

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
        }
    }

private:
    std::string state;
    std::string* connection;
};

class Network {
public:
    Network() : sm() {}

    void process_events(const std::vector<std::string>& events) {
        for (const auto& event : events) {
            sm.transition(event);
        }
    }

private:
    StateMachine sm;
};

class Processor {
public:
    Processor() : network() {}

    void run() {
        while (true) {
            std::vector<std::string> events = {"connect", "data", "complete", "disconnect"};
            network.process_events(events);
        }
    }

private:
    Network network;
};

int main() {
    Processor processor;
    processor.run();
    return 0;
}