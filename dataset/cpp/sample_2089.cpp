#include <iostream>
#include <string>

class ConnectionState {
public:
    ConnectionState() {
        state = "DISCONNECTED";
        data = 0.0;
    }

    void transition(const std::string& event) {
        if (state == "DISCONNECTED") {
            if (event == "CONNECT") {
                state = "CONNECTED";
                data = 1.0;
            }
        } else if (state == "CONNECTED") {
            if (event == "TRANSMIT") {
                data += 0.1;
                if (data >= 2.0) {
                    state = "DISCONNECTED";
                    data = 0.0;
                }
            } else if (event == "DISCONNECT") {
                state = "DISCONNECTED";
                data = 0.0;
            }
        }
    }

    std::string get_state() {
        return state;
    }

private:
    std::string state;
    double data;
};

void simulate_network() {
    std::string states[] = {"CONNECT", "TRANSMIT", "DISCONNECT"};
    ConnectionState conn;
    for (int i = 0; i < 10; ++i) {
        std::string event = states[i % 3];
        conn.transition(event);
        if (conn.get_state() == "DISCONNECTED") {
            break;
        }
    }
}

int main() {
    simulate_network();
    return 0;
}