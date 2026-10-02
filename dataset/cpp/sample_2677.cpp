#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept>

class StateMachine {
public:
    StateMachine(const std::unordered_map<std::string, std::vector<std::string>>& states, const std::unordered_map<std::pair<std::string, std::string>, std::string>& transitions, const std::string& start_state)
        : states(states), transitions(transitions), current_state(start_state) {}

    void transition(const std::string& event) {
        auto key = std::make_pair(current_state, event);
        if (transitions.find(key) != transitions.end()) {
            next_state = transitions.at(key);
            current_state = next_state;
            sequence.push_back(event);
        } else {
            throw std::invalid_argument("Invalid transition");
        }
    }

    bool is_terminated() {
        auto terminal_states = states.at("terminal");
        return std::find(terminal_states.begin(), terminal_states.end(), current_state) != terminal_states.end();
    }

private:
    const std::unordered_map<std::string, std::vector<std::string>>& states;
    const std::unordered_map<std::pair<std::string, std::string>, std::string>& transitions;
    std::string current_state;
    std::string next_state;
    std::vector<std::string> sequence;
};

class NetworkConnection {
public:
    NetworkConnection(StateMachine& state_machine) : state_machine(state_machine) {}

    void process_events(const std::vector<std::string>& events) {
        for (const auto& event : events) {
            state_machine.transition(event);
            if (state_machine.is_terminated()) {
                break;
            }
        }
    }

private:
    StateMachine& state_machine;
};

int main() {
    std::unordered_map<std::string, std::vector<std::string>> states = {
        {"initial", {"connected", "disconnected"}},
        {"connected", {"sending", "receiving", "disconnected"}},
        {"sending", {"connected", "disconnected"}},
        {"receiving", {"connected", "disconnected"}},
        {"terminal", {"disconnected"}}
    };

    std::unordered_map<std::pair<std::string, std::string>, std::string> transitions = {
        {{"initial", "connect"}, "connected"},
        {{"connected", "send"}, "sending"},
        {{"connected", "receive"}, "receiving"},
        {{"connected", "disconnect"}, "disconnected"},
        {{"sending", "connect"}, "connected"},
        {{"sending", "disconnect"}, "disconnected"},
        {{"receiving", "connect"}, "connected"},
        {{"receiving", "disconnect"}, "disconnected"}
    };

    std::string start_state = "initial";
    StateMachine state_machine(states, transitions, start_state);
    NetworkConnection network_connection(state_machine);
    std::vector<std::string> events = {"connect", "send", "receive", "disconnect"};
    network_connection.process_events(events);

    std::cout << "Sequence: ";
    for (const auto& event : state_machine.sequence) {
        std::cout << event << " ";
    }
    std::cout << std::endl;

    std::cout << "Terminated: " << (state_machine.is_terminated() ? "true" : "false") << std::endl;

    return 0;
}