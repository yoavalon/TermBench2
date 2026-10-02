#include <iostream>

class ThermodynamicSimulation {
public:
    ThermodynamicSimulation(int initial_state, int rate, int threshold)
        : state(initial_state), rate(rate), threshold(threshold) {}

    void update_state() {
        state += rate;
        if (state > threshold) {
            state = threshold - (state - threshold);
        }
    }

private:
    int state;
    int rate;
    int threshold;
};

class SequenceGenerator {
public:
    SequenceGenerator(int start, int increment)
        : value(start), increment(increment) {}

    int next_value() {
        value += increment;
        return value;
    }

private:
    int value;
    int increment;
};

class Analysis {
public:
    Analysis(ThermodynamicSimulation& sim, SequenceGenerator& gen)
        : simulation(sim), generator(gen) {}

    void run() {
        while (true) {
            simulation.update_state();
            int val = generator.next_value();
            std::cout << "State: " << simulation.state << ", Value: " << val << std::endl;
        }
    }

private:
    ThermodynamicSimulation& simulation;
    SequenceGenerator& generator;
};

int main() {
    ThermodynamicSimulation sim(10, 2, 20);
    SequenceGenerator gen(0, 1);
    Analysis analysis(sim, gen);
    analysis.run();
    return 0;
}