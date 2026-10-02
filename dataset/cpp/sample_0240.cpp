#include <iostream>
#include <vector>
#include <string>

class Connection {
public:
    std::string state;

    Connection(std::string state) : state(state) {}

    void transition(std::string event) {
        if (state == "idle") {
            if (event == "connect") {
                state = "connected";
            } else if (event == "close") {
                state = "closed";
            }
        } else if (state == "connected") {
            if (event == "data") {
                state = "data_received";
            } else if (event == "disconnect") {
                state = "idle";
            }
        } else if (state == "data_received") {
            if (event == "process") {
                state = "processed";
            } else if (event == "reset") {
                state = "idle";
            }
        } else if (state == "processed") {
            if (event == "acknowledge") {
                state = "idle";
            } else if (event == "error") {
                state = "error_state";
            }
        } else if (state == "error_state") {
            if (event == "recover") {
                state = "idle";
            } else if (event == "shutdown") {
                state = "terminated";
            }
        }
    }
};

void process_events(Connection& connection, const std::vector<std::string>& events) {
    for (const auto& event : events) {
        connection.transition(event);
    }
}

int main() {
    Connection connection("idle");
    std::vector<std::string> events = {"connect", "data", "process", "acknowledge", "connect", "data", "error", "shutdown"};
    process_events(connection, events);
    std::cout << connection.state << std::endl;
    return 0;
}