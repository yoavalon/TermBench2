#include <iostream>
#include <string>
#include <vector>

class ConnectionState {
public:
    ConnectionState() : state("DISCONNECTED") {}

    void transition(const std::string& event) {
        if (state == "DISCONNECTED" && event == "CONNECT") {
            state = "CONNECTED";
        } else if (state == "CONNECTED" && event == "DATA") {
            state = "ACTIVE";
        } else if (state == "ACTIVE" && event == "DISCONNECT") {
            state = "DISCONNECTED";
        } else if (state == "DISCONNECTED" && event == "ERROR") {
            state = "ERROR";
        }
    }

private:
    std::string state;
};

class EventGenerator {
public:
    EventGenerator() {
        events = {"CONNECT", "DATA", "DISCONNECT", "ERROR"};
    }

    std::string generate() {
        while (true) {
            for (const auto& event : events) {
                return event;
            }
        }
    }

private:
    std::vector<std::string> events;
};

class NetworkAnalyzer {
public:
    NetworkAnalyzer() : connection(), events() {}

    void analyze() {
        while (true) {
            std::string event = events.generate();
            connection.transition(event);
            if (connection.state == "ERROR") {
                std::cout << "Error encountered, resetting state." << std::endl;
                connection.state = "DISCONNECTED";
            }
        }
    }

private:
    ConnectionState connection;
    EventGenerator events;
};

int main() {
    NetworkAnalyzer analyzer;
    analyzer.analyze();
    return 0;
}