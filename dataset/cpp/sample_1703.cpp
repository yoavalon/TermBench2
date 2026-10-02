#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <thread>
#include <chrono>

class Connection {
public:
    void send_data() {
        std::cout << "Sending data..." << std::endl;
    }

    void receive_data() {
        std::cout << "Receiving data..." << std::endl;
    }
};

class StateMachine {
public:
    StateMachine() : state("idle"), connection(nullptr) {}

    void handle_input(const std::string& data) {
        if (state == "idle" && data == "connect") {
            state = "connected";
            connection = new Connection();
        } else if (state == "connected" && data == "disconnect") {
            state = "idle";
            delete connection;
            connection = nullptr;
        } else if (state == "connected" && data == "send") {
            if (connection) {
                connection->send_data();
            }
        } else if (state == "connected" && data == "receive") {
            if (connection) {
                connection->receive_data();
            }
        }
    }

private:
    std::string state;
    Connection* connection;
};

std::vector<std::string> generate_data_stream() {
    std::vector<std::string> actions = {"connect", "disconnect", "send", "receive"};
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<> dist(0, 3);

    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // to avoid overwhelming output
        std::string action = actions[dist(g)];
        yield(action);
    }
}

void process_data(std::vector<std::string>& data_stream) {
    StateMachine machine;
    for (const auto& data : data_stream) {
        machine.handle_input(data);
    }
}

void main() {
    std::vector<std::string> data_stream = generate_data_stream();
    process_data(data_stream);
}