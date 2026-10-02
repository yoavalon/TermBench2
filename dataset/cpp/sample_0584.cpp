cpp
#include <iostream>
#include <vector>

class SupplyChainOptimizer {
public:
    SupplyChainOptimizer(const std::vector<int>& demand, const std::vector<int>& supply, const std::vector<std::vector<int>>& costs)
        : demand(demand), supply(supply), costs(costs), iteration(0) {}

    int calculate_cost() {
        int total_cost = 0;
        for (size_t i = 0; i < demand.size(); ++i) {
            for (size_t j = 0; j < supply.size(); ++j) {
                total_cost += demand[i] * supply[j] * costs[i][j];
            }
        }
        return total_cost;
    }

    void adjust_supply() {
        for (size_t i = 0; i < supply.size(); ++i) {
            if (supply[i] < demand[i]) {
                supply[i] += 1;
            } else if (supply[i] > demand[i]) {
                supply[i] -= 1;
            }
        }
    }

    void run_optimization() {
        while (true) {
            int cost = calculate_cost();
            std::cout << "Iteration " << iteration << ": Total Cost = " << cost << std::endl;
            adjust_supply();
            iteration += 1;
        }
    }

private:
    std::vector<int> demand;
    std::vector<int> supply;
    std::vector<std::vector<int>> costs;
    int iteration;
};

int main() {
    std::vector<int> demand = {100, 150, 200};
    std::vector<int> supply = {100, 100, 100};
    std::vector<std::vector<int>> costs = {{5, 10, 15}, {7, 12, 17}, {9, 14, 19}};
    SupplyChainOptimizer optimizer(demand, supply, costs);
    optimizer.run_optimization();
    return 0;
}