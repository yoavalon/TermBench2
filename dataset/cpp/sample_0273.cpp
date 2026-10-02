#include <iostream>
#include <vector>
#include <string>

class NetworkConnection {
public:
    NetworkConnection(std::string state = "disconnected") : state(state) {}

    void connect() {
        if (state == "disconnected") {
            state = "connecting";
        } else if (state == "connected") {
            std::cout << "Already connected." << std::endl;
        } else {
            state = "reconnecting";
        }
    }

    void disconnect() {
        if (state == "connected" || state == "reconnecting") {
            state = "disconnecting";
        } else if (state == "disconnected") {
            std::cout << "Already disconnected." << std::endl;
        } else {
            state = "disconnected";
        }
    }

    void transition() {
        if (state == "connecting") {
            state = "connected";
        } else if (state == "reconnecting") {
            state = "connected";
        } else if (state == "disconnecting") {
            state = "disconnected";
        } else {
            state = "disconnected";
        }
    }

private:
    std::string state;
};

void manage_connection(NetworkConnection& connection, const std::vector<std::string>& actions) {
    for (const auto& action : actions) {
        if (action == "connect") {
            connection.connect();
        } else if (action == "disconnect") {
            connection.disconnect();
        }
        connection.transition();
    }
}

int main() {
    std::vector<std::string> actions = {"connect", "disconnect", "connect", "connect", "disconnect", "disconnect"};
    NetworkConnection connection;
    manage_connection(connection, actions);
    return 0;
}