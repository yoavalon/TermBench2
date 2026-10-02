#include <iostream>
#include <vector>
#include <string>

class NetworkConnection {
public:
    NetworkConnection(std::string state, double precision) : state(state), precision(precision) {}

    void transition(const std::string& event) {
        if (state == "closed" && event == "connect") {
            state = "open";
        } else if (state == "open" && event == "data") {
            state = "transmitting";
        } else if (state == "transmitting" && event == "disconnect") {
            state = "closing";
        } else if (state == "closing" && event == "acknowledge") {
            state = "closed";
        }
    }

    std::string get_state() const {
        return state;
    }

private:
    std::string state;
    double precision;
};

class NetworkAnalyzer {
public:
    NetworkAnalyzer(const std::vector<NetworkConnection>& connections) : connections(connections) {}

    std::vector<std::string> analyze() {
        std::vector<std::string> states;
        for (const auto& conn : connections) {
            states.push_back(conn.get_state());
        }
        return states;
    }

private:
    const std::vector<NetworkConnection>& connections;
};

class EventGenerator {
public:
    EventGenerator(const std::vector<std::string>& events) : events(events) {}

    std::vector<std::string> generate() const {
        return events;
    }

private:
    std::vector<std::string> events;
};

void main() {
    NetworkConnection conn1("closed", 0.5);
    NetworkConnection conn2("closed", 0.75);
    std::vector<NetworkConnection> connections = {conn1, conn2};
    EventGenerator event_generator({"connect", "data", "disconnect", "acknowledge", "connect"});
    NetworkAnalyzer analyzer(connections);
    std::vector<std::string> events = event_generator.generate();
    for (const auto& event : events) {
        for (auto& conn : connections) {
            conn.transition(event);
        }
    }
    std::vector<std::string> final_states = analyzer.analyze();
    for (const auto& state : final_states) {
        std::cout << state << " ";
    }
    std::cout << std::endl;
}

int main() {
    main();
    return 0;
}