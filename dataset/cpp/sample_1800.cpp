#include <iostream>
#include <vector>
#include <string>

class NetworkConnection {
public:
    std::string state;
    std::vector<std::string> data;

    NetworkConnection() : state("disconnected") {}

    void connect() {
        if (state == "disconnected") {
            state = "connected";
            data.push_back("connected");
        }
    }

    void disconnect() {
        if (state == "connected") {
            state = "disconnected";
            data.push_back("disconnected");
        }
    }

    void send_data(const std::string& packet) {
        if (state == "connected") {
            data.push_back("sent:" + packet);
        }
    }

    void receive_data(const std::string& packet) {
        if (state == "connected") {
            data.push_back("received:" + packet);
        }
    }
};

class NetworkManager {
public:
    NetworkConnection* connection;
    std::vector<std::string> actions;
    int counter;

    NetworkManager(NetworkConnection* connection) : connection(connection), counter(0) {
        actions = {"connect", "disconnect", "send_data", "receive_data"};
    }

    void perform_action(const std::string& action, const std::string& packet = "") {
        if (action == "connect") {
            connection->connect();
        } else if (action == "disconnect") {
            connection->disconnect();
        } else if (action == "send_data" && !packet.empty()) {
            connection->send_data(packet);
        } else if (action == "receive_data" && !packet.empty()) {
            connection->receive_data(packet);
        }
    }

    void simulate() {
        while (true) {
            std::string action = actions[counter % actions.size()];
            if (action == "send_data" || action == "receive_data") {
                perform_action(action, "packet_" + std::to_string(counter));
            } else {
                perform_action(action);
            }
            counter += 1;
        }
    }
};

int main() {
    NetworkConnection connection;
    NetworkManager manager(&connection);
    manager.simulate();
    return 0;
}