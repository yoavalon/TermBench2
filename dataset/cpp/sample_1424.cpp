#include <iostream>
#include <vector>
#include <string>

class ConnectionState {
public:
    ConnectionState() : state("disconnected") {}

    std::string connect() {
        if (state == "disconnected") {
            state = "connected";
            return "Connection established";
        } else {
            return "Already connected";
        }
    }

    std::string disconnect() {
        if (state == "connected") {
            state = "disconnected";
            return "Connection terminated";
        } else {
            return "Already disconnected";
        }
    }

    std::string toggle() {
        if (state == "disconnected") {
            return connect();
        } else {
            return disconnect();
        }
    }

private:
    std::string state;
};

std::vector<std::string> process_connections(ConnectionState& connections, const std::vector<std::string>& actions) {
    std::vector<std::string> results;
    for (const auto& action : actions) {
        if (action == "toggle") {
            results.push_back(connections.toggle());
        } else if (action == "connect") {
            results.push_back(connections.connect());
        } else if (action == "disconnect") {
            results.push_back(connections.disconnect());
        }
    }
    return results;
}

void main() {
    ConnectionState connections;
    std::vector<std::string> actions = {"connect", "toggle", "disconnect", "toggle", "connect", "disconnect"};
    std::vector<std::string> results = process_connections(connections, actions);
    for (const auto& result : results) {
        std::cout << result << std::endl;
    }
}