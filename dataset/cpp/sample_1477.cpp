#include <iostream>

class ConnectionState {
public:
    ConnectionState() : state("disconnected") {}

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

class NetworkManager {
public:
    NetworkManager(ConnectionState& state) : state(state) {}

    void attempt_connection() {
        if (!state.is_connected()) {
            state.connect();
        } else {
            state.disconnect();
        }
    }

    void monitor() {
        for (int i = 0; i < 10; ++i) {
            attempt_connection();
            if (state.is_connected()) {
                break;
            }
        }
    }

private:
    ConnectionState& state;
};

int main() {
    ConnectionState state;
    NetworkManager manager(state);
    manager.monitor();
    return 0;
}