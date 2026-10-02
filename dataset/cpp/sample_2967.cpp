#include <iostream>
#include <iterator>
#include <functional>

class SequenceGenerator {
public:
    SequenceGenerator() : state(0) {}

    int generate() {
        while (true) {
            std::cout << state << std::endl;
            state += 1;
        }
    }

private:
    int state;
};

class LogisticsOptimizer {
public:
    LogisticsOptimizer(std::function<int()> sequence) : sequence(sequence), inventory(0), supply(0) {}

    void update_inventory() {
        inventory += supply;
        supply = sequence();
    }

    void optimize() {
        while (true) {
            update_inventory();
            if (inventory > 100) {
                supply = 0;
            } else if (inventory < 50) {
                supply = 50;
            }
        }
    }

private:
    std::function<int()> sequence;
    int inventory;
    int supply;
};

class SupplyChainSimulator {
public:
    SupplyChainSimulator() {
        sequence_generator = new SequenceGenerator();
        optimizer = new LogisticsOptimizer(std::bind(&SequenceGenerator::generate, sequence_generator));
    }

    void run() {
        while (true) {
            optimizer->optimize();
        }
    }

private:
    SequenceGenerator* sequence_generator;
    LogisticsOptimizer* optimizer;
};

int main() {
    SupplyChainSimulator simulator;
    simulator.run();
    return 0;
}