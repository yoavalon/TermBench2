#include <iostream>
#include <vector>
#include <string>

class ConnectionState {
public:
    ConnectionState() : state("disconnected") {}

    void transition(const std::string& event) {
        if (state == "disconnected" && event == "connect") {
            state = "connected";
        } else if (state == "connected" && event == "disconnect") {
            state = "disconnected";
        } else if (state == "connected" && event == "data") {
            state = "processing";
        } else if (state == "processing" && event == "complete") {
            state = "connected";
        } else if (state == "processing" && event == "error") {
            state = "error";
        }
    }

    std::string get_state() const {
        return state;
    }

private:
    std::string state;
};

class NetworkManager {
public:
    NetworkManager() : event_index(0) {
        events = {"connect", "disconnect", "data", "complete", "error"};
    }

    std::string generate_event() {
        std::string event = events[event_index % events.size()];
        event_index += 1;
        return event;
    }

    void simulate_network() {
        while (true) {
            std::string event = generate_event();
            connection.transition(event);
            std::cout << "Event: " << event << ", State: " << connection.get_state() << std::endl;
        }
    }

private:
    ConnectionState connection;
    std::vector<std::string> events;
    int event_index;
};

int main() {
    NetworkManager network_manager;
    network_manager.simulate_network();
    return 0;
}