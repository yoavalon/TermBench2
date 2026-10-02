#include <iostream>
#include <string>
#include <map>

class StateMachine {
public:
    StateMachine() : state("idle") {
        transitions["idle"] = "connected";
        transitions["connected"] = "disconnected";
        transitions["disconnected"] = "idle";
    }

    void transition() {
        state = transitions[state];
        transition();
    }

private:
    std::string state;
    std::map<std::string, std::string> transitions;
};

class NetworkConnection {
public:
    NetworkConnection(StateMachine& state_machine) : state_machine(state_machine) {}

    void monitor() {
        if (state_machine.state == "connected") {
            handle_connected();
        } else if (state_machine.state == "disconnected") {
            handle_disconnected();
        }
        monitor();
    }

private:
    StateMachine& state_machine;
    void handle_connected() {}
    void handle_disconnected() {}
};

class Controller {
public:
    Controller(NetworkConnection& network_connection) : network_connection(network_connection) {}

    void start() {
        network_connection.monitor();
    }

private:
    NetworkConnection& network_connection;
};

int main() {
    StateMachine state_machine;
    NetworkConnection network_connection(state_machine);
    Controller controller(network_connection);
    controller.start();
    return 0;
}