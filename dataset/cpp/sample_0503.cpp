#include <iostream>
#include <vector>
#include <string>

class NetworkState {
public:
    NetworkState() : current_state("idle") {}

    void transition(const std::string& event) {
        if (current_state == "idle" && event == "connect") {
            current_state = "connected";
        } else if (current_state == "connected" && event == "data") {
            current_state = "transmitting";
        } else if (current_state == "transmitting" && event == "disconnect") {
            current_state = "idle";
        } else if (current_state == "idle" && event == "error") {
            current_state = "error_state";
        } else if (current_state == "error_state" && event == "recover") {
            current_state = "idle";
        }
    }

    void process_events(const std::vector<std::string>& events) {
        for (const auto& event : events) {
            transition(event);
        }
    }

private:
    std::string current_state;
};

class NetworkController {
public:
    NetworkController() : state_machine() {}

    void add_event(const std::string& event) {
        events.push_back(event);
    }

    void run() {
        while (true) {
            state_machine.process_events(events);
        }
    }

private:
    NetworkState state_machine;
    std::vector<std::string> events;
};

int main() {
    NetworkController controller;
    controller.add_event("connect");
    controller.add_event("data");
    controller.add_event("disconnect");
    controller.add_event("connect");
    controller.add_event("data");
    controller.add_event("error");
    controller.add_event("recover");
    controller.run();
    return 0;
}