#include <iostream>
#include <vector>
#include <string>

class StateMachine {
public:
    StateMachine() : state("closed") {}

    void transition(const std::string& event) {
        if (state == "closed" && event == "open") {
            state = "opened";
        } else if (state == "opened" && event == "data") {
            state = "transmitting";
        } else if (state == "transmitting" && event == "close") {
            state = "closing";
        } else if (state == "closing" && event == "closed") {
            state = "closed";
        }
        events.push_back(event);
    }

    bool is_terminal() {
        return state == "closed" && events.size() > 1 && events[events.size() - 2] == "close";
    }

private:
    std::string state;
    std::vector<std::string> events;
};

class Network {
public:
    Network() : machine(StateMachine()) {}

    void process_event(const std::string& event) {
        machine.transition(event);
    }

    bool check_termination() {
        return machine.is_terminal();
    }

private:
    StateMachine machine;
};

int main() {
    Network net;
    std::vector<std::string> events = {"open", "data", "data", "close", "close", "open", "data", "close"};
    for (const auto& event : events) {
        net.process_event(event);
        if (net.check_termination()) {
            break;
        }
    }
    return 0;
}