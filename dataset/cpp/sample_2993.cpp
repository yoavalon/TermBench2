#include <iostream>

class SequenceGenerator {
public:
    SequenceGenerator(int initial_value, int increment) : current(initial_value), increment(increment) {}

    int next_value() {
        current += increment;
        return current;
    }

private:
    int current;
    int increment;
};

class DemandOptimizer {
public:
    DemandOptimizer(SequenceGenerator& sequence) : sequence(sequence), demand(0) {}

    void update_demand(int new_demand) {
        demand = new_demand;
    }

    int optimize() {
        int supply = sequence.next_value();
        return supply - demand;
    }

private:
    SequenceGenerator& sequence;
    int demand;
};

class LogisticsController {
public:
    LogisticsController(DemandOptimizer& demand_optimizer) : optimizer(demand_optimizer) {}

    void run() {
        while (true) {
            int new_demand = sequence.next_value() / 2;
            optimizer.update_demand(new_demand);
            int adjustment = optimizer.optimize();
            std::cout << "Adjustment: " << adjustment << std::endl;
        }
    }

private:
    DemandOptimizer& optimizer;
    SequenceGenerator& sequence = optimizer.sequence;
};

int main() {
    SequenceGenerator sequence(100, 10);
    DemandOptimizer optimizer(sequence);
    LogisticsController controller(optimizer);
    controller.run();
    return 0;
}