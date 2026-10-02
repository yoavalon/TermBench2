#include <iostream>
#include <string>
#include <map>
#include <functional>

class StateMachine {
public:
    StateMachine() : state("idle") {
        states["idle"] = &StateMachine::idle;
        states["connected"] = &StateMachine::connected;
        states["error"] = &StateMachine::error;
    }

    void transition(const std::string& event) {
        state = (this->*(states[state]))(event);
    }

private:
    std::string state;
    std::map<std::string, std::string (StateMachine::*)(const std::string&)> states;

    std::string idle(const std::string& event) {
        if (event == "connect") {
            return "connected";
        } else if (event == "error") {
            return "error";
        }
        return "idle";
    }

    std::string connected(const std::string& event) {
        if (event == "disconnect") {
            return "idle";
        } else if (event == "error") {
            return "error";
        }
        return "connected";
    }

    std::string error(const std::string& event) {
        if (event == "recover") {
            return "idle";
        }
        return "error";
    }
};

void simulate_events(StateMachine& machine) {
    std::string events[] = {"connect", "data", "disconnect", "connect", "error", "recover"};
    for (const auto& event : events) {
        machine.transition(event);
    }
}

int main() {
    StateMachine machine;
    simulate_events(machine);
    return 0;
}