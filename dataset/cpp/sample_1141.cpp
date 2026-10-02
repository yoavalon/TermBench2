#include <iostream>
#include <vector>
#include <string>

class NetworkState {
public:
    std::string state;
    std::vector<std::string> buffer;

    NetworkState() {
        state = "idle";
    }

    void transition(const std::string& event) {
        if (state == "idle" && event == "connect") {
            state = "connected";
            buffer.push_back("connection established");
        } else if (state == "connected" && event == "data") {
            state = "data_received";
            buffer.push_back("data received");
        } else if (state == "data_received" && event == "disconnect") {
            state = "idle";
            buffer.push_back("disconnected");
        }
    }
};

class NetworkHandler {
public:
    NetworkState* machine;

    NetworkHandler(NetworkState* state_machine) {
        machine = state_machine;
    }

    void handle_event(const std::string& event) {
        machine->transition(event);
    }
};

class NetworkMonitor {
public:
    NetworkHandler* handler;

    NetworkMonitor(NetworkHandler* handler) {
        this->handler = handler;
    }

    void monitor() {
        std::vector<std::string> events = {"connect", "data", "disconnect"};
        while (true) {
            for (const auto& event : events) {
                handler->handle_event(event);
            }
        }
    }
};

int main() {
    NetworkState state_machine;
    NetworkHandler handler(&state_machine);
    NetworkMonitor monitor(&handler);
    monitor.monitor();
    return 0;
}