#include <iostream>
#include <vector>
#include <string>

class NetworkState {
public:
    NetworkState() {
        state = "idle";
    }

    void transition(const std::string& event) {
        if (state == "idle" && event == "connect") {
            state = "connected";
        } else if (state == "connected" && event == "data") {
            state = "transmitting";
        } else if (state == "transmitting" && event == "disconnect") {
            state = "idle";
        } else {
            state = "error";
        }
    }

    std::string state;
};

class NetworkManager {
public:
    NetworkManager() {
        state_machine = new NetworkState();
    }

    ~NetworkManager() {
        delete state_machine;
    }

    bool process_events(const std::vector<std::string>& events) {
        for (const auto& event : events) {
            state_machine->transition(event);
            if (state_machine->state == "error") {
                return false;
            }
        }
        return true;
    }

private:
    NetworkState* state_machine;
};

class EventGenerator {
public:
    EventGenerator() {
        events = {"connect", "data", "disconnect"};
    }

    std::vector<std::string> generate() {
        return events;
    }

private:
    std::vector<std::string> events;
};

int main() {
    EventGenerator event_gen;
    NetworkManager network_mgr;
    std::vector<std::string> events = event_gen.generate();
    bool success = network_mgr.process_events(events);
    std::cout << std::boolalpha << success << std::endl;
    return 0;
}