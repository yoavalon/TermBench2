#include <iostream>
#include <algorithm>

class SupplyChainOptimization {
public:
    SupplyChainOptimization(int demand, int supply, int cost)
        : demand(demand), supply(supply), cost(cost), iteration(0), max_iterations(100) {}

    int calculate_shortage() {
        return std::max(0, demand - supply);
    }

    int adjust_supply() {
        int shortage = calculate_shortage();
        if (shortage > 0) {
            int adjustment = std::min(shortage, supply * 0.1);
            supply += adjustment;
            return adjustment;
        }
        return 0;
    }

    void update_cost(int adjustment) {
        if (adjustment > 0) {
            cost += adjustment * 0.05;
        }
    }

    void run_optimization() {
        while (iteration < max_iterations) {
            int shortage = calculate_shortage();
            if (shortage == 0) {
                break;
            }
            int adjustment = adjust_supply();
            update_cost(adjustment);
            iteration += 1;
        }
    }

private:
    int demand;
    int supply;
    int cost;
    int iteration;
    int max_iterations;
};

void main() {
    int demand = 500;
    int supply = 450;
    int cost = 1000;
    SupplyChainOptimization optimizer(demand, supply, cost);
    optimizer.run_optimization();
    std::cout << "Final Supply: " << optimizer.supply << ", Final Cost: " << optimizer.cost << std::endl;
}

int main() {
    main();
    return 0;
}