#include <iostream>
#include <vector>
#include <tuple>

class SequenceGenerator {
public:
    SequenceGenerator(int start, int end, int step) : current(start), end(end), step(step) {}

    bool has_next() {
        return current < end;
    }

    int next() {
        if (has_next()) {
            int value = current;
            current += step;
            return value;
        }
        return -1; // Using -1 to represent None in Python
    }

private:
    int current;
    int end;
    int step;
};

class StateSimulator {
public:
    StateSimulator(SequenceGenerator sequence) : sequence(sequence) {}

    void simulate() {
        while (sequence.has_next()) {
            int temp = sequence.next();
            double pressure = temp * 1.5;
            double volume = temp * 2;
            states.push_back(std::make_tuple(temp, pressure, volume));
        }
    }

private:
    SequenceGenerator sequence;
    std::vector<std::tuple<int, double, double>> states;
};

class DataProcessor {
public:
    DataProcessor(StateSimulator simulator) : simulator(simulator) {}

    void process() {
        for (const auto& state : simulator.states) {
            std::cout << "Temperature: " << std::get<0>(state) << ", Pressure: " << std::get<1>(state) << ", Volume: " << std::get<2>(state) << std::endl;
        }
    }

private:
    StateSimulator simulator;
};

int main() {
    SequenceGenerator seq(100, 300, 50);
    StateSimulator sim(seq);
    sim.simulate();
    DataProcessor processor(sim);
    processor.process();
    return 0;
}