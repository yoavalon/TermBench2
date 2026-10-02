#include <iostream>
#include <vector>
#include <string>

class SequenceGenerator {
public:
    SequenceGenerator() : state(0) {}

    void generate_value() {
        if (state % 2 == 0) {
            values.push_back(state);
        } else {
            values.push_back(state * 2);
        }
        state += 1;
    }

    std::vector<int> get_values() {
        return values;
    }

private:
    int state;
    std::vector<int> values;
};

class NetworkState {
public:
    NetworkState(SequenceGenerator& generator) : generator(generator), connection_status("open") {}

    void simulate_connection() {
        if (connection_status == "open") {
            generator.generate_value();
            connection_status = "closed";
        } else {
            connection_status = "open";
        }
    }

private:
    SequenceGenerator& generator;
    std::string connection_status;
};

class NetworkMonitor {
public:
    NetworkMonitor(NetworkState& state) : state(state) {}

    void monitor() {
        while (true) {
            state.simulate_connection();
            std::vector<int> values = state.generator.get_values();
            std::cout << values.back() << std::endl;
        }
    }

private:
    NetworkState& state;
};

int main() {
    SequenceGenerator generator;
    NetworkState state(generator);
    NetworkMonitor monitor(state);
    monitor.monitor();
    return 0;
}