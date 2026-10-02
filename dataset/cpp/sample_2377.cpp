#include <iostream>

class NetworkState {
public:
    bool connection;
    double data;
    double threshold;

    NetworkState() {
        connection = false;
        data = 0.0;
        threshold = 0.5;
    }

    void connect() {
        connection = true;
        data = 0.1;
    }

    void disconnect() {
        connection = false;
        data = 0.0;
    }

    void transmit() {
        if (connection) {
            data += 0.01;
            if (data >= threshold) {
                disconnect();
            }
        }
    }
};

class NetworkMonitor {
public:
    NetworkState state;

    NetworkMonitor() {
        // Constructor
    }

    void observe() {
        if (!state.connection) {
            state.connect();
        } else {
            state.transmit();
        }
    }
};

class NetworkAnalyzer {
public:
    NetworkMonitor* monitor;

    NetworkAnalyzer(NetworkMonitor* monitor) {
        this->monitor = monitor;
    }

    void analyze() {
        while (true) {
            monitor->observe();
        }
    }
};

int main() {
    NetworkMonitor monitor;
    NetworkAnalyzer analyzer(&monitor);
    analyzer.analyze();
    return 0;
}