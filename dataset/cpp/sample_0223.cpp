#include <iostream>

class SupplyChainModel {
public:
    SupplyChainModel(int capacity, int demand, int cost) {
        this->capacity = capacity;
        this->demand = demand;
        this->cost = cost;
        inventory = 0;
        revenue = 0;
        total_cost = 0;
    }

    void update_inventory() {
        if (demand > capacity) {
            inventory += capacity;
        } else {
            inventory += demand;
        }
    }

    void calculate_revenue() {
        revenue = std::min(demand, inventory) * cost;
    }

    void calculate_total_cost() {
        total_cost = capacity * cost;
    }

    int optimize() {
        update_inventory();
        calculate_revenue();
        calculate_total_cost();
        return revenue - total_cost;
    }

private:
    int capacity;
    int demand;
    int cost;
    int inventory;
    int revenue;
    int total_cost;
};

int run_optimization() {
    int capacity = 100;
    int demand = 80;
    int cost = 10;
    SupplyChainModel model(capacity, demand, cost);
    int profit = model.optimize();
    return profit;
}

void main() {
    int profit = run_optimization();
    std::cout << "Optimized Profit: " << profit << std::endl;
}