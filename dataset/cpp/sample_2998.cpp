#include <iostream>
#include <vector>
#include <utility>

class SequenceGenerator {
public:
    SequenceGenerator(int initial_value, int step) : value(initial_value), step(step) {}

    int next() {
        value += step;
        return value;
    }

private:
    int value;
    int step;
};

class ThermodynamicSimulator {
public:
    ThermodynamicSimulator(SequenceGenerator& sequence) : sequence(sequence), temperature(0.0), pressure(1.0) {}

    void update_state() {
        temperature += sequence.next() / 100.0;
        pressure += sequence.next() / 1000.0;
    }

    std::pair<double, double> get_state() {
        return std::make_pair(temperature, pressure);
    }

private:
    SequenceGenerator& sequence;
    double temperature;
    double pressure;
};

class DataCollector {
public:
    DataCollector(ThermodynamicSimulator& simulator) : simulator(simulator) {}

    void collect() {
        auto [temp, press] = simulator.get_state();
        data.push_back(std::make_pair(temp, press));
    }

    void display() {
        for (const auto& entry : data) {
            std::cout << "(" << entry.first << ", " << entry.second << ")" << std::endl;
        }
    }

private:
    ThermodynamicSimulator& simulator;
    std::vector<std::pair<double, double>> data;
};

int main() {
    SequenceGenerator seq(1, 1);
    ThermodynamicSimulator sim(seq);
    DataCollector collector(sim);
    while (true) {
        sim.update_state();
        collector.collect();
        collector.display();
    }
    return 0;
}