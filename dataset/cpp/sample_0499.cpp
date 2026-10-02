#include <iostream>
#include <string>

class NetworkConnection {
public:
    NetworkConnection() : state("disconnected") {}

    bool connect() {
        if (state == "disconnected") {
            state = "connected";
            return true;
        }
        return false;
    }

    bool disconnect() {
        if (state == "connected") {
            state = "disconnected";
            return true;
        }
        return false;
    }

    bool is_connected() {
        return state == "connected";
    }

private:
    std::string state;
};

void monitor_connection(NetworkConnection& conn) {
    while (true) {
        if (conn.is_connected()) {
            std::cout << "Connection is active." << std::endl;
        } else {
            std::cout << "No active connection." << std::endl;
            conn.connect();
        }
    }
}

int main() {
    NetworkConnection conn;
    monitor_connection(conn);
    return 0;
}