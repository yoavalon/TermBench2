#include <iostream>
#include <vector>
#include <string>

std::string transition(const std::string& state, const std::string& event) {
    if (state == "init" && event == "connect") {
        return "connected";
    } else if (state == "connected" && event == "disconnect") {
        return "disconnected";
    } else if (state == "disconnected" && event == "reconnect") {
        return "connected";
    } else {
        return state;
    }
}

class SequenceGenerator {
public:
    SequenceGenerator(const std::vector<std::string>& events) : events(events), current_state("init") {}

    std::string next() {
        for (const auto& event : events) {
            current_state = transition(current_state, event);
        }
        return current_state;
    }

private:
    std::vector<std::string> events;
    std::string current_state;
};

void main() {
    std::vector<std::string> events = {"connect", "disconnect", "reconnect", "connect", "disconnect"};
    SequenceGenerator generator(events);
    while (true) {
        std::cout << generator.next() << std::endl;
    }
}