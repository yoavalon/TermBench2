#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class NetworkState {
public:
    std::string state;
    int connection_attempts;

    NetworkState() {
        state = "disconnected";
        connection_attempts = 0;
    }

    void transition(const std::string& event) {
        if (state == "disconnected" && event == "connect") {
            state = "connecting";
        } else if (state == "connecting") {
            if (event == "success") {
                state = "connected";
                connection_attempts = 0;
            } else if (event == "failure") {
                connection_attempts += 1;
                if (connection_attempts < 5) {
                    state = "connecting";
                } else {
                    state = "disconnected";
                }
            }
        } else if (state == "connected" && event == "disconnect") {
            state = "disconnected";
        }
    }
};

class EventGenerator {
public:
    std::string generate() {
        if (std::rand() % 2 == 0) {
            return "connect";
        } else {
            return "disconnect";
        }
    }
};

class ConnectionHandler {
public:
    NetworkState network;
    EventGenerator generator;

    void run() {
        while (true) {
            std::string event = generator.generate();
            network.transition(event);
            if (network.state == "connected") {
                handle_connected();
            } else if (network.state == "disconnected") {
                handle_disconnected();
            }
        }
    }

    void handle_connected() {
        std::cout << "Connected" << std::endl;
    }

    void handle_disconnected() {
        std::cout << "Disconnected" << std::endl;
    }
};

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    ConnectionHandler handler;
    handler.run();
    return 0;
}