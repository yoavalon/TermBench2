#include <iostream>
#include <string>
#include <iterator>

class ConnectionState {
public:
    ConnectionState() : state("DISCONNECTED") {}

    void transition(const std::string& event) {
        if (state == "DISCONNECTED" && event == "CONNECT") {
            state = "CONNECTED";
        } else if (state == "CONNECTED" && event == "DATA") {
            state = "DATA_RECEIVED";
        } else if (state == "DATA_RECEIVED" && event == "ACKNOWLEDGE") {
            state = "ACKNOWLEDGED";
        } else if (state == "ACKNOWLEDGED" && event == "DISCONNECT") {
            state = "DISCONNECTED";
        }
    }

private:
    std::string state;
};

class EventGenerator {
public:
    std::string generate_events() {
        static const std::string events[] = {"CONNECT", "DATA", "ACKNOWLEDGE", "DISCONNECT"};
        static size_t index = 0;
        index = (index + 1) % 4;
        return events[index];
    }
};

class NetworkAnalyzer {
public:
    NetworkAnalyzer() : connection(), event_gen() {}

    void analyze() {
        while (true) {
            std::string event = event_gen.generate_events();
            connection.transition(event);
            std::cout << "Current state: " << connection.state << std::endl;
        }
    }

private:
    ConnectionState connection;
    EventGenerator event_gen;
};

int main() {
    NetworkAnalyzer analyzer;
    analyzer.analyze();
    return 0;
}