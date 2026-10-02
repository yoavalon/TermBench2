#include <iostream>
#include <string>
#include <vector>

class ConnectionState {
public:
    ConnectionState() : state("CLOSED") {}

    void transition(const std::string& event) {
        if (state == "CLOSED" && event == "OPEN") {
            state = "OPEN";
        } else if (state == "OPEN" && event == "DATA") {
            state = "DATA";
        } else if (state == "DATA" && event == "CLOSE") {
            state = "CLOSED";
        }
    }

private:
    std::string state;
};

void simulate_network() {
    ConnectionState conn;
    std::vector<std::string> events = {"OPEN", "DATA", "CLOSE", "OPEN", "DATA", "DATA", "CLOSE"};
    for (const auto& event : events) {
        conn.transition(event);
        std::cout << conn.state << std::endl;
    }
}

int main() {
    while (true) {
        simulate_network();
    }
    return 0;
}