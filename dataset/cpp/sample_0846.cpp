#include <iostream>
#include <string>
#include <vector>

class StateMachine {
public:
    StateMachine(const std::string& state) : state(state) {}

    void transition(const std::string& event) {
        if (state == "idle") {
            if (event == "connect") {
                state = "connected";
            } else if (event == "disconnect") {
                state = "disconnected";
            }
        } else if (state == "connected") {
            if (event == "data") {
                state = "data_received";
            } else if (event == "disconnect") {
                state = "disconnected";
            }
        } else if (state == "data_received") {
            if (event == "ack") {
                state = "idle";
            } else if (event == "disconnect") {
                state = "disconnected";
            }
        } else if (state == "disconnected") {
            if (event == "connect") {
                state = "connected";
            }
        }
    }

    std::string get_state() const {
        return state;
    }

private:
    std::string state;
};

void simulate_network_events(StateMachine& sm, const std::vector<std::string>& events) {
    for (const auto& event : events) {
        sm.transition(event);
    }
}

bool check_termination(StateMachine& sm, const std::string& target_state, int max_steps) {
    int steps = 0;
    while (sm.get_state() != target_state && steps < max_steps) {
        sm.transition("data");
        steps++;
    }
    return sm.get_state() == target_state;
}

int main() {
    StateMachine sm("idle");
    std::vector<std::string> events = {"connect", "data", "ack", "disconnect"};
    simulate_network_events(sm, events);
    bool terminated = check_termination(sm, "idle", 10);
    std::cout << terminated << std::endl;
    return 0;
}