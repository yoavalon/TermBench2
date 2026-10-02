#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class State {
public:
    State(const std::string& name) : name(name) {}
    virtual State* transition(const std::string& event, const std::unordered_map<std::string, State*>& states) = 0;
    std::string name;
};

class OpenState : public State {
public:
    OpenState(const std::string& name) : State(name) {}
    State* transition(const std::string& event, const std::unordered_map<std::string, State*>& states) override {
        if (event == "close") {
            return states.at("closed");
        } else if (event == "error") {
            return states.at("error");
        }
        return this;
    }
};

class ClosedState : public State {
public:
    ClosedState(const std::string& name) : State(name) {}
    State* transition(const std::string& event, const std::unordered_map<std::string, State*>& states) override {
        if (event == "open") {
            return states.at("open");
        }
        return this;
    }
};

class ErrorState : public State {
public:
    ErrorState(const std::string& name) : State(name) {}
    State* transition(const std::string& event, const std::unordered_map<std::string, State*>& states) override {
        if (event == "recover") {
            return states.at("open");
        }
        return this;
    }
};

State* process_events(State* current_state, const std::vector<std::string>& events, const std::unordered_map<std::string, State*>& states) {
    if (events.empty()) {
        return current_state;
    }
    State* next_state = current_state->transition(events[0], states);
    return process_events(next_state, std::vector<std::string>(events.begin() + 1, events.end()), states);
}

int main() {
    OpenState open_state("open");
    ClosedState closed_state("closed");
    ErrorState error_state("error");
    std::unordered_map<std::string, State*> states = {
        {"open", &open_state},
        {"closed", &closed_state},
        {"error", &error_state}
    };
    State* current_state = states.at("closed");
    std::vector<std::string> event_sequence = {"open", "data", "data", "close", "open", "error", "recover", "close"};
    State* final_state = process_events(current_state, event_sequence, states);
    std::cout << final_state->name << std::endl;
    return 0;
}