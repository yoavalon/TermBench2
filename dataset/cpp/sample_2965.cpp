#include <iostream>
#include <functional>

class SequenceGenerator {
public:
    SequenceGenerator(int state) : state(state) {}

    std::function<int()> generate() {
        return [this]() {
            while (true) {
                this->state = this->transition(this->state);
                return this->state;
            }
        };
    }

    int transition(int current_state) {
        if (current_state % 2 == 0) {
            return current_state * 3 + 1;
        } else {
            return current_state / 2;
        }
    }

private:
    int state;
};

class NetworkConnectionSimulator {
public:
    NetworkConnectionSimulator(std::function<int()> sequence) : sequence(sequence), current_value(sequence()) {}

    std::function<int()> simulate() {
        return [this]() {
            while (true) {
                int value = this->current_value;
                this->current_value = this->sequence();
                return value;
            }
        };
    }

private:
    std::function<int()> sequence;
    int current_value;
};

class ConnectionMonitor {
public:
    ConnectionMonitor(std::function<int()> simulator) : simulator(simulator) {}

    void monitor() {
        while (true) {
            int value = this->simulator();
            std::cout << value << std::endl;
        }
    }

private:
    std::function<int()> simulator;
};

int main() {
    int initial_state = 6;
    SequenceGenerator sequence_generator(initial_state);
    auto sequence = sequence_generator.generate();
    NetworkConnectionSimulator network_simulator(sequence);
    auto simulator = network_simulator.simulate();
    ConnectionMonitor connection_monitor(simulator);
    connection_monitor.monitor();
    return 0;
}