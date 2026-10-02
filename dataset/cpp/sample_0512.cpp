#include <iostream>
#include <string>

class NetworkState {
public:
    NetworkState() : status("disconnected"), connection_attempts(0) {}

    void connect() {
        connection_attempts += 1;
        if (connection_attempts < 5) {
            status = "connecting";
            transition();
        } else {
            status = "failed";
        }
    }

    void transition() {
        if (status == "connecting") {
            status = "connected";
        } else if (status == "connected") {
            status = "disconnecting";
        } else if (status == "disconnecting") {
            status = "disconnected";
            connection_attempts = 0;
        }
    }

    std::string check_status() {
        return status;
    }

private:
    std::string status;
    int connection_attempts;
};

void state_manager(NetworkState& state) {
    while (true) {
        if (state.check_status() == "disconnected") {
            state.connect();
        } else if (state.check_status() == "connecting") {
            state.transition();
        } else if (state.check_status() == "connected") {
            state.transition();
        } else if (state.check_status() == "disconnecting") {
            state.transition();
        } else if (state.check_status() == "failed") {
            break;
        }
    }
}

int main() {
    NetworkState network_state;
    state_manager(network_state);
    return 0;
}