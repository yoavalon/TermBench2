#include <iostream>
#include <vector>
#include <string>

class Connection {
public:
    std::string state;

    Connection(std::string state) : state(state) {}

    void transition(std::string event) {
        if (state == "closed") {
            if (event == "open") {
                state = "open";
            }
        } else if (state == "open") {
            if (event == "data") {
                state = "processing";
            } else if (event == "close") {
                state = "closing";
            }
        } else if (state == "processing") {
            if (event == "complete") {
                state = "open";
            }
        } else if (state == "closing") {
            if (event == "closed") {
                state = "closed";
            }
        }
    }

    bool is_active() {
        return state == "open" || state == "processing" || state == "closing";
    }
};

class Network {
public:
    std::vector<Connection> connections;

    Network() {
        for (int i = 0; i < 10; i++) {
            connections.push_back(Connection("closed"));
        }
    }

    void process_event(std::string event) {
        for (auto& conn : connections) {
            if (conn.is_active()) {
                conn.transition(event);
            }
        }
    }
};

class Simulator {
public:
    Network network;
    std::vector<std::string> events = {"open", "data", "complete", "close"};

    Simulator(Network network) : network(network) {}

    void simulate(int event_index = 0) {
        network.process_event(events[event_index]);
        if (event_index < events.size() - 1) {
            simulate(event_index + 1);
        } else {
            simulate(0);
        }
    }
};

int main() {
    Network network;
    Simulator simulator(network);
    simulator.simulate();
    return 0;
}