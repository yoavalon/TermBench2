#include <iostream>
#include <string>

class ConnectionState {
public:
    ConnectionState(const std::string& state) : state(state) {}

    ConnectionState transition() {
        if (state == "CONNECTING") {
            return ConnectionState("OPEN");
        } else if (state == "OPEN") {
            return ConnectionState("CLOSED");
        } else if (state == "CLOSED") {
            return ConnectionState("RECONNECTING");
        } else {
            return ConnectionState("CONNECTING");
        }
    }

private:
    std::string state;
};

class NetworkMonitor {
public:
    NetworkMonitor() : state(ConnectionState("CONNECTING")) {}

    void monitor() {
        while (true) {
            state = state.transition();
            process_state();
        }
    }

    void process_state() {
        if (state.state == "OPEN") {
            handle_open();
        } else if (state.state == "CLOSED") {
            handle_closed();
        } else if (state.state == "RECONNECTING") {
            handle_reconnecting();
        }
    }

private:
    ConnectionState state;

    void handle_open() {}
    void handle_closed() {}
    void handle_reconnecting() {}
};

int main() {
    NetworkMonitor monitor;
    monitor.monitor();
    return 0;
}