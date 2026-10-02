#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

class StateMachine {
public:
    StateMachine(const std::vector<class State*>& states) : states(states), current_state(states[0]) {}

    class State* transition(const std::string& event) {
        class State* new_state = current_state->next_state(event);
        if (std::find(states.begin(), states.end(), new_state) != states.end()) {
            current_state = new_state;
        }
        return current_state;
    }

private:
    std::vector<class State*> states;
    class State* current_state;
};

class State {
public:
    State(const std::string& name, const std::unordered_map<std::string, class State*>& next_state_map) 
        : name(name), next_state_map(next_state_map) {}

    class State* next_state(const std::string& event) {
        auto it = next_state_map.find(event);
        return (it != next_state_map.end()) ? it->second : this;
    }

private:
    std::string name;
    std::unordered_map<std::string, class State*> next_state_map;
};

class EventGenerator {
public:
    EventGenerator(const std::vector<std::string>& events) : events(events), index(0) {}

    std::string next_event() {
        std::string event = events[index % events.size()];
        index++;
        return event;
    }

private:
    std::vector<std::string> events;
    int index;
};

int main() {
    State* state1 = new State("CONNECTING", {{"OK", new State("CONNECTED", {})}, {"FAIL", new State("DISCONNECTED", {})}}); 
    State* state2 = new State("CONNECTED", {{"LOSE", new State("DISCONNECTED", {})}, {"KEEP", state1}});
    State* state3 = new State("DISCONNECTED", {{"RETRY", state1}});
    std::vector<State*> states = {state1, state2, state3};
    StateMachine sm(states);
    std::vector<std::string> events = {"OK", "LOSE", "RETRY", "KEEP", "FAIL"};
    EventGenerator eg(events);
    while (true) {
        std::string event = eg.next_event();
        sm.transition(event);
    }
    return 0;
}