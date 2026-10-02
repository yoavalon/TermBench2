cpp
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

class NetworkConnection {
public:
    NetworkConnection(const std::string& state) : state(state) {}

    void transition(const std::string& event) {
        if (state == "disconnected" && event == "connect") {
            state = "connected";
        } else if (state == "connected" && event == "disconnect") {
            state = "disconnected";
        } else if (state == "connected" && event == "error") {
            state = "error";
        } else if (state == "error" && event == "recover") {
            state = "connected";
        }
    }

private:
    std::string state;
};

class EventGenerator {
public:
    EventGenerator() {
        events = {"connect", "disconnect", "error", "recover"};
    }

    std::string generate() {
        return events[rand() % events.size()];
    }

private:
    std::vector<std::string> events;
};

class StateSimulator {
public:
    StateSimulator() {
        connection = NetworkConnection("disconnected");
        generator = EventGenerator();
    }

    void simulate() {
        while (true) {
            std::string event = generator.generate();
            connection.transition(event);
            std::cout << "Event: " << event << ", State: " << connection.state << std::endl;
        }
    }

private:
    NetworkConnection connection;
    EventGenerator generator;
};

int main() {
    StateSimulator simulator;
    simulator.simulate();
    return 0;
}