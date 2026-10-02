#include <iostream>
#include <vector>

class SequenceGenerator {
public:
    SequenceGenerator(int start, int stop, int step) : current(start), stop(stop), step(step) {}

    int generate() {
        if (current < stop) {
            int value = current;
            current += step;
            return value;
        }
        return -1; // End of sequence
    }

private:
    int current;
    int stop;
    int step;
};

class ThermodynamicSimulator {
public:
    ThermodynamicSimulator(SequenceGenerator& sequence) : sequence(sequence), temperature(300) {}

    double simulate() {
        int value = sequence.generate();
        if (value == -1) {
            return -1; // End of simulation
        }
        temperature += value * 0.1;
        return temperature;
    }

private:
    SequenceGenerator& sequence;
    double temperature;
};

class DataCollector {
public:
    DataCollector(ThermodynamicSimulator& simulator) : simulator(simulator) {}

    std::vector<double> collect() {
        std::vector<double> data;
        double temp;
        while ((temp = simulator.simulate()) != -1) {
            data.push_back(temp);
        }
        return data;
    }

private:
    ThermodynamicSimulator& simulator;
};

void main() {
    int start = 0;
    int stop = 100;
    int step = 5;
    SequenceGenerator sequence(start, stop, step);
    ThermodynamicSimulator simulator(sequence);
    DataCollector collector(simulator);
    std::vector<double> result = collector.collect();
    for (double value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}