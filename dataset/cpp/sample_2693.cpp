#include <iostream>
#include <vector>
#include <algorithm>

class SequenceGenerator {
public:
    SequenceGenerator(int start, int end, int step) : current(start), end(end), step(step) {}

    std::vector<int> generate() {
        std::vector<int> sequence;
        while (current <= end) {
            sequence.push_back(current);
            current += step;
        }
        return sequence;
    }

private:
    int current;
    int end;
    int step;
};

class LogisticsOptimizer {
public:
    LogisticsOptimizer(int demand, int supply) : demand(demand), supply(supply) {}

    int calculate_deficit() {
        return std::max(0, demand - supply);
    }

    int optimize() {
        int deficit = calculate_deficit();
        if (deficit > 0) {
            return supply + deficit;
        }
        return supply;
    }

private:
    int demand;
    int supply;
};

int main() {
    SequenceGenerator demand_generator(100, 200, 10);
    SequenceGenerator supply_generator(120, 220, 15);
    std::vector<int> demand_sequence = demand_generator.generate();
    std::vector<int> supply_sequence = supply_generator.generate();
    std::vector<int> optimized_supplies;

    for (size_t i = 0; i < demand_sequence.size() && i < supply_sequence.size(); ++i) {
        LogisticsOptimizer optimizer(demand_sequence[i], supply_sequence[i]);
        optimized_supplies.push_back(optimizer.optimize());
    }

    for (int supply : optimized_supplies) {
        std::cout << supply << " ";
    }
    std::cout << std::endl;

    return 0;
}