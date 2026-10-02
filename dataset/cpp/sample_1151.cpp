#include <iostream>
#include <string>

class ConnectionState {
public:
    ConnectionState(const std::string& status = "disconnected") : status(status) {}

    std::string connect() {
        if (status == "disconnected") {
            status = "connected";
            return "Connection established";
        }
        return "Already connected";
    }

    std::string disconnect() {
        if (status == "connected") {
            status = "disconnected";
            return "Connection terminated";
        }
        return "Already disconnected";
    }

    std::string toggle() {
        if (status == "connected") {
            status = "disconnected";
        } else {
            status = "connected";
        }
        return "Status toggled to " + status;
    }

private:
    std::string status;
};

class NetworkHandler {
public:
    NetworkHandler() : state() {}

    void manage_connection() {
        while (true) {
            std::string action = decide_action();
            if (action == "connect") {
                state.connect();
            } else if (action == "disconnect") {
                state.disconnect();
            } else if (action == "toggle") {
                state.toggle();
            } else {
                break;
            }
        }
    }

    std::string decide_action() {
        if (state.status == "connected") {
            return "disconnect";
        } else {
            return "connect";
        }
    }

private:
    ConnectionState state;
};

int main() {
    NetworkHandler handler;
    handler.manage_connection();
    return 0;
}