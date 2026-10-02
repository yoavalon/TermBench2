#include <iostream>
#include <vector>
#include <string>
#include <random>

class NetworkStateMachine {
public:
    NetworkStateMachine() : state("disconnected") {}

    void transition(const std::string& event) {
        if (state == "disconnected" && event == "connect") {
            state = "connected";
        } else if (state == "connected" && event == "send") {
            data.push_back("data");
        } else if (state == "connected" && event == "disconnect") {
            state = "disconnected";
            data.clear();
        }
    }

    void process_events(const std::vector<std::string>& events) {
        for (const auto& event : events) {
            transition(event);
        }
    }

    std::pair<std::string, std::vector<std::string>> get_status() {
        return {state, data};
    }

private:
    std::string state;
    std::vector<std::string> data;
};

std::vector<std::string> generate_events(int count) {
    std::vector<std::string> events;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < count; ++i) {
        double r = dis(gen);
        if (r < 0.3) {
            events.push_back("connect");
        } else if (r < 0.5) {
            events.push_back("send");
        } else {
            events.push_back("disconnect");
        }
    }
    return events;
}

int main() {
    NetworkStateMachine state_machine;
    std::vector<std::string> events = generate_events(100);
    state_machine.process_events(events);
    auto [final_state, final_data] = state_machine.get_status();
    std::cout << final_state << " ";
    for (const auto& d : final_data) {
        std::cout << d << " ";
    }
    std::cout << std::endl;
    return 0;
}