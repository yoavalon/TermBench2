#include <iostream>
#include <string>

class NetworkConnection {
public:
    std::string state;
    int attempts;

    NetworkConnection() {
        state = "disconnected";
        attempts = 0;
    }

    void connect() {
        if (state == "disconnected") {
            state = "connecting";
            attempts += 1;
        } else if (state == "connecting") {
            state = "connected";
        } else if (state == "connected") {
            state = "disconnecting";
        } else if (state == "disconnecting") {
            state = "disconnected";
        }
    }

    bool is_connected() {
        return state == "connected";
    }

    int get_attempts() {
        return attempts;
    }
};

int manage_connection() {
    NetworkConnection connection;
    while (connection.get_attempts() < 5) {
        connection.connect();
        if (connection.is_connected()) {
            break;
        }
    }
    return connection.get_attempts();
}

std::string analyze_connection_attempts() {
    int attempts = manage_connection();
    if (attempts < 5) {
        return "Connection successful";
    } else {
        return "Connection failed after multiple attempts";
    }
}

int main() {
    std::string result = analyze_connection_attempts();
    std::cout << result << std::endl;
    return 0;
}