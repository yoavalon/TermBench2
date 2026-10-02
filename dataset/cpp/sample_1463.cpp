#include <iostream>
#include <vector>
#include <string>
#include <utility>

class StateMachine {
public:
    StateMachine() {
        state = "idle";
        connection = false;
    }

    void transition(const std::string& event) {
        if (state == "idle" && event == "connect") {
            state = "connected";
            connection = true;
        } else if (state == "connected" && event == "disconnect") {
            state = "idle";
            connection = false;
        } else if (state == "connected" && event == "error") {
            state = "error";
            connection = false;
        } else if (state == "error" && event == "recover") {
            state = "connected";
            connection = true;
        }
    }

    std::pair<std::string, bool> get_status() {
        return {state, connection};
    }

private:
    std::string state;
    bool connection;
};

std::vector<std::pair<std::string, bool>> simulate_events(const std::vector<std::string>& events) {
    StateMachine machine;
    std::vector<std::pair<std::string, bool>> statuses;
    for (const auto& event : events) {
        machine.transition(event);
        statuses.push_back(machine.get_status());
    }
    return statuses;
}

void main() {
    std::vector<std::string> events_sequence = {"connect", "data", "disconnect", "connect", "error", "recover"};
    auto results = simulate_events(events_sequence);
    for (const auto& status : results) {
        std::cout << "{" << status.first << ", " << status.second << "}" << std::endl;
    }
}

int main() {
    main();
    return 0;
}