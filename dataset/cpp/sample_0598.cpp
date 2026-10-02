#include <iostream>
#include <string>

class NetworkConnection {
public:
    NetworkConnection(const std::string& state = "disconnected") : state(state) {}

    std::string connect() {
        if (state == "disconnected") {
            state = "connected";
        }
        return state;
    }

    std::string disconnect() {
        if (state == "connected") {
            state = "disconnected";
        }
        return state;
    }

    bool is_connected() {
        return state == "connected";
    }

private:
    std::string state;
};

class StateMachine {
public:
    StateMachine() : connection() {}

    std::string process(const std::string& command) {
        if (command == "connect") {
            return connection.connect();
        } else if (command == "disconnect") {
            return connection.disconnect();
        } else if (command == "status") {
            return connection.is_connected() ? "true" : "false";
        }
        return "";
    }

private:
    NetworkConnection connection;
};

void simulate_network_activity(StateMachine& state_machine) {
    while (true) {
        if (state_machine.process("connect") == "connected") {
            std::cout << "Connection established." << std::endl;
            while (state_machine.process("status") == "true") {
                std::cout << "Connected." << std::endl;
            }
        }
        std::cout << "Connection lost." << std::endl;
        state_machine.process("disconnect");
    }
}

int main() {
    StateMachine state_machine;
    simulate_network_activity(state_machine);
    return 0;
}