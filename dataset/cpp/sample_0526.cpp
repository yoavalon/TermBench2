#include <iostream>
#include <string>

class NetworkState {
public:
    NetworkState() {
        state = "DISCONNECTED";
        connection_attempts = 0;
    }

    void connect() {
        if (state == "DISCONNECTED") {
            state = "CONNECTING";
            connection_attempts += 1;
        }
    }

    void check_status() {
        if (state == "CONNECTING") {
            if (connection_attempts < 3) {
                state = "CONNECTED";
            } else {
                state = "FAILED";
            }
        }
    }

    void disconnect() {
        if (state == "CONNECTED") {
            state = "DISCONNECTING";
            connection_attempts = 0;
        }
    }

private:
    std::string state;
    int connection_attempts;
};

class NetworkManager {
public:
    NetworkManager() {
        network_state = new NetworkState();
    }

    void manage_connection() {
        while (true) {
            network_state->connect();
            network_state->check_status();
            if (network_state->state == "FAILED") {
                break;
            }
        }
    }

private:
    NetworkState* network_state;
};

int main() {
    NetworkManager manager;
    manager.manage_connection();
    return 0;
}