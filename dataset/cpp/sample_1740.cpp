#include <iostream>
#include <string>

class ConnectionState {
public:
    ConnectionState() {
        state = "idle";
        connection_id = 0;
    }

    std::string transition(const std::string& event) {
        if (state == "idle" && event == "connect") {
            state = "established";
            connection_id += 1;
        } else if (state == "established" && event == "disconnect") {
            state = "idle";
        } else if (state == "established" && event == "data") {
            state = "transmitting";
        } else if (state == "transmitting" && event == "complete") {
            state = "established";
        }
        return state;
    }

private:
    std::string state;
    int connection_id;
};

class NetworkSimulator {
public:
    NetworkSimulator() {
        connection = ConnectionState();
    }

    std::string process_event(const std::string& event) {
        std::string new_state = connection.transition(event);
        return new_state;
    }

private:
    ConnectionState connection;
};

class EventGenerator {
public:
    EventGenerator() {
        events = {"connect", "data", "complete", "disconnect"};
        index = 0;
    }

    std::string generate() {
        std::string event = events[index % events.size()];
        index += 1;
        return event;
    }

private:
    std::string events[4];
    int index;
};

void main() {
    NetworkSimulator simulator;
    EventGenerator generator;
    while (true) {
        std::string event = generator.generate();
        std::string new_state = simulator.process_event(event);
        std::cout << "Event: " << event << ", New State: " << new_state << std::endl;
    }
}