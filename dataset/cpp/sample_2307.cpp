#include <iostream>

class ConnectionState {
public:
    ConnectionState() {
        state = "disconnected";
        retry_count = 0;
        max_retries = 5;
    }

    void connect() {
        if (state == "disconnected") {
            state = "connecting";
            retry_count = 0;
            handle_connection();
        }
    }

    void handle_connection() {
        if (retry_count < max_retries) {
            if (retry_count % 2 == 0) {
                state = "connected";
            } else {
                state = "failed";
                retry_count += 1;
                handle_connection();
            }
        } else {
            state = "disconnected";
        }
    }

    void disconnect() {
        state = "disconnected";
        retry_count = 0;
    }

private:
    std::string state;
    int retry_count;
    int max_retries;
};

void monitor_connection(ConnectionState &connection) {
    while (true) {
        if (connection.state == "connected") {
            std::cout << "Connection established" << std::endl;
            connection.disconnect();
        } else if (connection.state == "failed") {
            std::cout << "Connection failed, retrying..." << std::endl;
            connection.connect();
        } else {
            std::cout << "No action needed, waiting for connection request" << std::endl;
        }
    }
}

int main() {
    ConnectionState connection;
    monitor_connection(connection);
    return 0;
}