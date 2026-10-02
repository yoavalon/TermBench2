#include <iostream>
#include <vector>

class StateMachine {
public:
    StateMachine() : state("idle"), sequence{1, 2, 3, 4, 5}, index(0) {}

    std::string transition() {
        if (state == "idle") {
            state = "active";
        } else if (state == "active") {
            state = "idle";
        }
        return state;
    }

    int process_sequence() {
        if (state == "active") {
            if (index < sequence.size()) {
                int value = sequence[index];
                index += 1;
                return value;
            } else {
                index = 0;
            }
        }
        return -1;
    }

private:
    std::string state;
    std::vector<int> sequence;
    int index;
};

class NetworkConnection {
public:
    NetworkConnection() : state_machine(), connection_status("disconnected") {}

    int connect() {
        if (state_machine.transition() == "active") {
            connection_status = "connected";
            return state_machine.process_sequence();
        }
        return -1;
    }

    void disconnect() {
        connection_status = "disconnected";
        state_machine.transition();
    }

private:
    StateMachine state_machine;
    std::string connection_status;
};

int main() {
    NetworkConnection network;
    while (true) {
        if (network.connect() != -1) {
            std::cout << network.connect() << std::endl;
        } else {
            network.disconnect();
        }
    }
    return 0;
}