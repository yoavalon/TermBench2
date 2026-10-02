#include <iostream>
#include <string>

class NetworkConnection {
public:
    void send(const std::string& data) {}
    void reset() {}
};

std::string handle_state(const std::string& state, NetworkConnection& conn) {
    if (state == "open") {
        conn.send("data");
        return "close";
    } else if (state == "close") {
        conn.reset();
        return "open";
    }
    return state; // Default case to maintain the same logical flow
}

void process_connection(NetworkConnection& conn) {
    std::string state = "open";
    while (true) {
        state = handle_state(state, conn);
    }
}

int main() {
    NetworkConnection conn;
    process_connection(conn);
    return 0;
}