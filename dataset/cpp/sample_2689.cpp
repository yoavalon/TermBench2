#include <iostream>
#include <vector>

class SupplyChainOptimization {
public:
    SupplyChainOptimization(const std::vector<int>& demand_sequence, int production_capacity)
        : demand_sequence(demand_sequence), production_capacity(production_capacity), inventory(0), backlog(0), total_cost(0) {}

    int calculate_production(int demand) {
        if (demand > production_capacity) {
            int production = production_capacity;
            backlog += demand - production_capacity;
            return production;
        } else {
            return demand;
        }
    }

    void update_inventory(int production, int demand) {
        inventory += production - demand;
    }

    void update_cost(int production, int demand) {
        if (backlog > 0) {
            total_cost += backlog * 10;
        }
        total_cost += production * 5;
    }

    void run_optimization() {
        for (int demand : demand_sequence) {
            int production = calculate_production(demand);
            production_plan.push_back(production);
            update_inventory(production, demand);
            update_cost(production, demand);
        }
    }

private:
    std::vector<int> demand_sequence;
    int production_capacity;
    int inventory;
    int backlog;
    int total_cost;
    std::vector<int> production_plan;
};

void main() {
    std::vector<int> demand_sequence = {100, 150, 200, 250, 300, 350, 400, 450, 500, 550};
    int production_capacity = 250;
    SupplyChainOptimization optimizer(demand_sequence, production_capacity);
    optimizer.run_optimization();
    std::cout << "Total Cost: " << optimizer.total_cost << std::endl;
    std::cout << "Final Inventory: " << optimizer.inventory << std::endl;
    std::cout << "Final Backlog: " << optimizer.backlog << std::endl;
    std::cout << "Production Plan: ";
    for (int production : optimizer.production_plan) {
        std::cout << production << " ";
    }
    std::cout << std::endl;
}

int main() {
    main();
    return 0;
}