#include <iostream>
#include <vector>
#include <string>

class NetworkConnectionState {
public:
    std::string state;
    std::vector<std::string> data_buffer;
    int error_count;

    NetworkConnectionState() : state("disconnected"), error_count(0) {}

    void transition(const std::string& event) {
        if (state == "disconnected" && event == "connect") {
            state = "connected";
        } else if (state == "connected" && event == "send") {
            data_buffer.push_back("data");
        } else if (state == "connected" && event == "receive") {
            if (!data_buffer.empty()) {
                data_buffer.erase(data_buffer.begin());
            } else {
                error_count++;
            }
        }
    }
};

class NetworkController {
public:
    NetworkConnectionState connection;
    std::vector<std::string> events;

    NetworkController() : events({"connect", "send", "receive"}) {}

    void process_events() {
        while (true) {
            for (const auto& event : events) {
                connection.transition(event);
            }
        }
    }
};

class Monitor {
public:
    NetworkController& controller;

    Monitor(NetworkController& controller) : controller(controller) {}

    void check_state() {
        while (true) {
            if (controller.connection.error_count >= 3) {
                std::cout << "Error threshold reached, resetting..." << std::endl;
                controller.connection.error_count = 0;
            }
        }
    }
};

int main() {
    NetworkController controller;
    Monitor monitor(controller);
    controller.process_events();
    monitor.check_state();
    return 0;
}