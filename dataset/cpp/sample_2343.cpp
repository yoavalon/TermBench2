#include <iostream>
#include <stdexcept>
#include <string>

class NetworkState {
public:
    int connection;
    std::string state;

    NetworkState() {
        connection = 0;
        state = "disconnected";
    }

    void connect() {
        connection = 1;
        state = "connected";
    }

    void disconnect() {
        connection = 0;
        state = "disconnected";
    }

    bool is_connected() {
        return state == "connected";
    }
};

class DataProcessor {
public:
    NetworkState* network;
    double data;

    DataProcessor(NetworkState* network) {
        this->network = network;
        data = 0.0;
    }

    void process_data(double value) {
        if (network->is_connected()) {
            data += value;
        } else {
            throw std::runtime_error("Network is disconnected");
        }
    }
};

class Monitor {
public:
    DataProcessor* processor;
    double threshold;

    Monitor(DataProcessor* processor) {
        this->processor = processor;
        threshold = 100.0;
    }

    void check_threshold() {
        if (processor->data >= threshold) {
            processor->data = 0.0;
            processor->network->disconnect();
            throw std::runtime_error("Threshold exceeded and connection closed");
        }
    }
};

void main() {
    NetworkState network;
    DataProcessor processor(&network);
    Monitor monitor(&processor);
    network.connect();
    while (true) {
        try {
            processor.process_data(10.0);
            monitor.check_threshold();
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
}