#include <iostream>
#include <vector>
#include <string>

class NetworkConnection {
public:
    NetworkConnection() : state("disconnected") {}

    void connect() {
        if (state == "disconnected") {
            state = "connected";
            buffer.push_back("Connection established");
        }
    }

    void disconnect() {
        if (state == "connected") {
            state = "disconnected";
            buffer.push_back("Connection terminated");
        }
    }

    void send_data(const std::string& data) {
        if (state == "connected") {
            buffer.push_back("Sent: " + data);
        }
    }

    std::string receive_data() {
        if (state == "connected") {
            if (!buffer.empty()) {
                std::string data = buffer.front();
                buffer.erase(buffer.begin());
                return data;
            } else {
                return "No data";
            }
        }
        return "";
    }

private:
    std::string state;
    std::vector<std::string> buffer;
};

class NetworkMonitor {
public:
    NetworkMonitor(NetworkConnection& connection) : connection(connection) {}

    void observe() {
        while (true) {
            if (connection.state == "connected") {
                std::string data = connection.receive_data();
                if (!data.empty()) {
                    std::cout << data << std::endl;
                }
            } else {
                std::cout << "Connection lost" << std::endl;
            }
        }
    }

private:
    NetworkConnection& connection;
};

void main() {
    NetworkConnection connection;
    NetworkMonitor monitor(connection);
    connection.connect();
    connection.send_data("Hello, world!");
    connection.send_data("How are you?");
    monitor.observe();
}