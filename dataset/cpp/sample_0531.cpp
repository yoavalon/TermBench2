#include <iostream>
#include <string>
#include <vector>
#include <memory>

class State {
public:
    virtual std::shared_ptr<State> transition(const std::string& event) = 0;
};

class ClosedState : public State {
public:
    std::shared_ptr<State> transition(const std::string& event) override {
        if (event == "open") {
            return std::make_shared<OpenState>();
        }
        return std::shared_ptr<State>(this);
    }
};

class OpenState : public State {
public:
    std::shared_ptr<State> transition(const std::string& event) override {
        if (event == "close") {
            return std::make_shared<ClosedState>();
        }
        if (event == "data") {
            return std::make_shared<DataState>();
        }
        return std::shared_ptr<State>(this);
    }
};

class DataState : public State {
public:
    std::shared_ptr<State> transition(const std::string& event) override {
        if (event == "close") {
            return std::make_shared<ClosedState>();
        }
        if (event == "data") {
            return std::shared_ptr<State>(this);
        }
        return std::make_shared<OpenState>();
    }
};

std::vector<std::string> states = {"open", "data", "close"};

std::string event_generator() {
    static size_t index = 0;
    std::string current_event = states[index];
    index = (index + 1) % states.size();
    return current_event;
}

void state_machine() {
    std::shared_ptr<State> current_state = std::make_shared<ClosedState>();
    while (true) {
        std::string event = event_generator();
        current_state = current_state->transition(event);
    }
}

int main() {
    state_machine();
    return 0;
}