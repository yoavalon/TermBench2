#include <iostream>
#include <vector>
#include <string>

class ConnectionState {
public:
    ConnectionState() : state("disconnected") {}

    std::string connect() {
        if (state == "disconnected") {
            state = "connecting";
            return connecting();
        }
        return "already connected";
    }

    std::string connecting() {
        if (state == "connecting") {
            state = "connected";
            return connected();
        }
        return "connection failed";
    }

    std::string connected() {
        if (state == "connected") {
            state = "disconnecting";
            return disconnecting();
        }
        return "connection lost";
    }

    std::string disconnecting() {
        if (state == "disconnecting") {
            state = "disconnected";
            return "disconnected";
        }
        return "disconnection failed";
    }

private:
    std::string state;
};

std::vector<std::string> simulate_connections() {
    ConnectionState conn;
    std::vector<std::string> states = {"connect", "connect", "disconnect", "connect", "disconnect"};
    std::vector<std::string> results;
    for (const auto& action : states) {
        if (action == "connect") {
            results.push_back(conn.connect());
        } else if (action == "disconnect") {
            results.push_back(conn.disconnecting());
        }
    }
    return results;
}

void main() {
    std::vector<std::string> results = simulate_connections();
    for (const auto& result : results) {
        std::cout << result << std::endl;
    }
}

int main() {
    main();
    return 0;
}