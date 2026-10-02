#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept>

class NetworkStateMachine {
public:
    NetworkStateMachine(const std::vector<std::string>& states, const std::unordered_map<std::pair<std::string, std::string>, std::string>& transitions)
        : states(states), transitions(transitions), current_state(states[0]) {}

    void transition(const std::string& event) {
        auto key = std::make_pair(current_state, event);
        if (transitions.find(key) != transitions.end()) {
            current_state = transitions.at(key);
        } else {
            throw std::invalid_argument("Invalid transition");
        }
    }

    bool is_terminal() const {
        return current_state == "disconnected" || current_state == "error";
    }

private:
    std::vector<std::string> states;
    std::unordered_map<std::pair<std::string, std::string>, std::string> transitions;
    std::string current_state;
};

class EventManager {
public:
    EventManager(const std::vector<std::string>& events) : events(events), index(0) {}

    std::string get_next_event() {
        if (index < events.size()) {
            std::string event = events[index];
            index += 1;
            return event;
        } else {
            return "";
        }
    }

private:
    std::vector<std::string> events;
    int index;
};

void main() {
    std::vector<std::string> states = {"idle", "connected", "disconnected", "error"};
    std::unordered_map<std::pair<std::string, std::string>, std::string> transitions = {
        {{"idle", "connect"}, "connected"},
        {{"connected", "disconnect"}, "disconnected"},
        {{"connected", "error"}, "error"},
        {{"disconnected", "connect"}, "connected"},
        {{"error", "reset"}, "idle"}
    };
    std::vector<std::string> events = {"connect", "disconnect", "error", "reset", "connect", "disconnect", "connect", "error", "reset"};
    NetworkStateMachine network_machine(states, transitions);
    EventManager event_manager(events);
    while (true) {
        std::string event = event_manager.get_next_event();
        if (event.empty() || network_machine.is_terminal()) {
            break;
        }
        network_machine.transition(event);
    }
    std::cout << "Final state: " << network_machine.current_state << std::endl;
}

int main() {
    main();
    return 0;
}