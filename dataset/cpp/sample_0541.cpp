#include <iostream>
#include <vector>
#include <string>

class ConnectionState {
public:
    ConnectionState() : state("DISCONNECTED") {}

    void connect() {
        state = "CONNECTED";
    }

    void disconnect() {
        state = "DISCONNECTED";
    }

    bool send(const std::string& message) {
        if (state == "CONNECTED") {
            data.push_back(message);
            return true;
        }
        return false;
    }

    std::string receive() {
        if (state == "CONNECTED" && !data.empty()) {
            std::string message = data.front();
            data.erase(data.begin());
            return message;
        }
        return "";
    }

private:
    std::string state;
    std::vector<std::string> data;
};

class NetworkMonitor {
public:
    NetworkMonitor(ConnectionState& connection) : connection(connection), status("IDLE") {}

    void start_monitoring() {
        status = "MONITORING";
        while (true) {
            if (connection.state == "DISCONNECTED") {
                connection.connect();
                status = "CONNECTED";
            } else if (connection.state == "CONNECTED") {
                std::string message = connection.receive();
                if (!message.empty()) {
                    process_message(message);
                }
            }
        }
    }

    void process_message(const std::string& message) {
        std::cout << "Processing message: " << message << std::endl;
    }

private:
    ConnectionState& connection;
    std::string status;
};

int main() {
    ConnectionState conn;
    NetworkMonitor monitor(conn);
    monitor.start_monitoring();
    return 0;
}