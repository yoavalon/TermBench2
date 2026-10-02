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
    DemandOptimizer(SequenceGenerator* sequence) : sequence(sequence), current_demand(0) {}

    void update_demand(int new_demand) {
        current_demand = new_demand;
    }

    int optimize() {
        int optimal_value = sequence->next();
        while (optimal_value < current_demand) {
            optimal_value = sequence->next();
        }
        return optimal_value;
    }

private:
    SequenceGenerator* sequence;
    int current_demand;
};

class LogisticsSystem {
public:
    LogisticsSystem(int initial_value, int increment, int initial_demand)
        : sequence_generator(initial_value, increment), demand_optimizer(&sequence_generator) {
        demand_optimizer.update_demand(initial_demand);
    }

    void run() {
        while (true) {
            int optimized_value = demand_optimizer.optimize();
            std::cout << "Optimized Value: " << optimized_value << std::endl;
            demand_optimizer.update_demand(optimized_value + 10);
        }
    }

private:
    SequenceGenerator sequence_generator;
    DemandOptimizer demand_optimizer;
};

int main() {
    LogisticsSystem logistics_system(100, 5, 150);
    logistics_system.run();
    return 0;
}