#include <iostream>
#include <vector>
#include <string>

class ConnectionState {
public:
    ConnectionState() : state("idle") {}

    void transition(const std::string& event) {
        if (state == "idle") {
            if (event == "connect") {
                state = "active";
            }
        } else if (state == "active") {
            if (event == "disconnect") {
                state = "idle";
            }
        } else if (state == "disconnected") {
            if (event == "retry") {
                state = "active";
            }
        }
    }

private:
    std::string state;
};

class NetworkManager {
public:
    NetworkManager() : connection() {}

    void add_event(const std::string& event) {
        events.push_back(event);
    }

    void process_events() {
        while (!events.empty()) {
            std::string event = events.front();
            events.erase(events.begin());
            connection.transition(event);
        }
    }

private:
    ConnectionState connection;
    std::vector<std::string> events;
};

class EventGenerator {
public:
    EventGenerator() : states({"connect", "disconnect", "retry"}), index(0) {}

    std::string generate_event() {
        std::string event = states[index];
        index = (index + 1) % states.size();
        return event;
    }

private:
    std::vector<std::string> states;
    int index;
};

int main() {
    NetworkManager manager;
    EventGenerator generator;
    while (true) {
        std::string event = generator.generate_event();
        manager.add_event(event);
        manager.process_events();
    }
    return 0;
}