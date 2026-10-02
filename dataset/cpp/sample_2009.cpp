#include <iostream>
#include <vector>
#include <string>

class ConnectionState {
public:
    ConnectionState() : state("DISCONNECTED") {}

    std::string transition(const std::string& event) {
        if (state == "DISCONNECTED" && event == "CONNECT") {
            state = "CONNECTED";
        } else if (state == "CONNECTED" && event == "SEND") {
            state = "SENDING";
        } else if (state == "SENDING" && event == "ACKNOWLEDGE") {
            state = "ACKNOWLEDGED";
        } else if (state == "ACKNOWLEDGED" && event == "DISCONNECT") {
            state = "DISCONNECTED";
        } else if (state == "CONNECTED" && event == "DATA") {
            data_buffer.push_back(event);
        } else if (state == "SENDING" && event == "REJECT") {
            state = "REJECTED";
        } else if (state == "REJECTED" && event == "RETRY") {
            state = "SENDING";
        }
        return state;
    }

private:
    std::string state;
    std::vector<std::string> data_buffer;
};

class NetworkHandler {
public:
    NetworkHandler() : connection(ConnectionState()) {}

    std::string process_event(const std::string& event) {
        std::string new_state = connection.transition(event);
        return new_state;
    }

private:
    ConnectionState connection;
};

class EventSimulator {
public:
    EventSimulator() {
        events = {"CONNECT", "DATA", "SEND", "ACKNOWLEDGE", "DISCONNECT"};
    }

    std::vector<std::string> generate_events() {
        return events;
    }

private:
    std::vector<std::string> events;
};

void main() {
    NetworkHandler handler;
    EventSimulator simulator;
    for (const auto& event : simulator.generate_events()) {
        std::string state = handler.process_event(event);
        std::cout << "Event: " << event << ", New State: " << state << std::endl;
    }
}