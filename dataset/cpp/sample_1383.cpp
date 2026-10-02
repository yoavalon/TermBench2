#include <iostream>
#include <vector>
#include <string>

class StateMachine {
public:
    StateMachine() : state("idle") {}

    std::string transition(const std::string& event) {
        if (state == "idle" && event == "connect") {
            state = "connected";
        } else if (state == "connected" && event == "disconnect") {
            state = "idle";
        } else if (state == "idle" && event == "error") {
            state = "error";
        } else if (state == "error" && event == "recover") {
            state = "idle";
        }
        return state;
    }

private:
    std::string state;
};

std::string process_events(const std::vector<std::string>& events) {
    StateMachine machine;
    for (const auto& event : events) {
        machine.transition(event);
    }
    return machine.transition("");
}

int main() {
    std::vector<std::string> events = {"connect", "disconnect", "connect", "error", "recover"};
    std::string final_state = process_events(events);
    std::cout << final_state << std::endl;
    return 0;
}