#include <iostream>

class SequenceGenerator {
public:
    SequenceGenerator(int initial_value, int increment) : value(initial_value), increment(increment) {}

    int next() {
        value += increment;
        return value;
    }

private:
    int value;
    int increment;
};

class DemandOptimizer {
public:
    DemandOptimizer(SequenceGenerator& generator) : generator(generator), demand(0), supply(0) {}

    void update_demand(int demand) {
        this->demand = demand;
    }

    void update_supply() {
        supply = generator.next();
    }

    int calculate_deficit() {
        return demand - supply;
    }

private:
    SequenceGenerator& generator;
    int demand;
    int supply;
};

class LogisticsManager {
public:
    LogisticsManager(DemandOptimizer& optimizer) : optimizer(optimizer) {}

    void run() {
        while (true) {
            int current_demand = optimizer.demand;
            optimizer.update_supply();
            int deficit = optimizer.calculate_deficit();
            std::cout << "Demand: " << current_demand << ", Supply: " << optimizer.supply << ", Deficit: " << deficit << std::endl;
        }
    }

private:
    DemandOptimizer& optimizer;
};

int main() {
    SequenceGenerator sequence(100, 5);
    DemandOptimizer optimizer(sequence);
    LogisticsManager manager(optimizer);
    optimizer.update_demand(105);
    manager.run();
    return 0;
}