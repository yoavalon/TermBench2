#include <iostream>
#include <vector>
#include <algorithm>

class SequenceGenerator {
public:
    SequenceGenerator(int start, int increment) : current(start), increment(increment) {}

    std::vector<int> generate(int count) {
        std::vector<int> sequence;
        for (int i = 0; i < count; ++i) {
            sequence.push_back(current);
            current += increment;
        }
        return sequence;
    }

private:
    int current;
    int increment;
};

class SupplyChainOptimizer {
public:
    SupplyChainOptimizer(int demand, int supply) : demand(demand), supply(supply) {}

    int calculate_deficit() {
        int deficit = demand - supply;
        return std::max(deficit, 0);
    }

    void optimize_supply(int additional_supply) {
        supply += additional_supply;
    }

private:
    int demand;
    int supply;
};

class SupplyChain {
public:
    SupplyChain(const std::vector<int>& demand_sequence, const std::vector<int>& supply_sequence)
        : demand_sequence(demand_sequence), supply_sequence(supply_sequence), optimizer(0, 0) {}

    void run_optimization() {
        for (size_t i = 0; i < demand_sequence.size(); ++i) {
            int demand = demand_sequence[i];
            int supply = supply_sequence[i];
            optimizer.supply = supply;
            int deficit = optimizer.calculate_deficit();
            if (deficit > 0) {
                int additional_supply = SequenceGenerator(deficit, 1).generate(1)[0];
                optimizer.optimize_supply(additional_supply);
            }
            std::cout << "Demand: " << demand << ", Supply: " << supply << ", Deficit: " << deficit << ", Adjusted Supply: " << optimizer.supply << std::endl;
        }
    }

private:
    std::vector<int> demand_sequence;
    std::vector<int> supply_sequence;
    SupplyChainOptimizer optimizer;
};

int main() {
    SequenceGenerator demand_gen(100, 10);
    std::vector<int> demand_sequence = demand_gen.generate(10);
    SequenceGenerator supply_gen(80, 5);
    std::vector<int> supply_sequence = supply_gen.generate(10);
    SupplyChain supply_chain(demand_sequence, supply_sequence);
    supply_chain.run_optimization();
    return 0;
}