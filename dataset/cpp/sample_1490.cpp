#include <iostream>

class SupplyChain {
public:
    int inventory;
    int demand;
    int cost;

    SupplyChain(int inventory, int demand, int cost) {
        this->inventory = inventory;
        this->demand = demand;
        this->cost = cost;
    }

    void update_inventory(int supply) {
        this->inventory += supply;
    }

    std::pair<int, int> meet_demand() {
        if (this->demand > this->inventory) {
            int shortage = this->demand - this->inventory;
            return std::make_pair(shortage, 0);
        } else {
            this->inventory -= this->demand;
            return std::make_pair(0, this->demand);
        }
    }

    int calculate_cost() {
        return this->demand * this->cost;
    }
};

class Optimizer {
public:
    SupplyChain supply_chain;
    int supply;

    Optimizer(SupplyChain supply_chain, int supply) {
        this->supply_chain = supply_chain;
        this->supply = supply;
    }

    std::tuple<int, int, int> optimize() {
        this->supply_chain.update_inventory(this->supply);
        auto [shortage, fulfilled] = this->supply_chain.meet_demand();
        int cost = this->supply_chain.calculate_cost();
        return std::make_tuple(shortage, fulfilled, cost);
    }
};

int main() {
    int inventory = 100;
    int demand = 150;
    int cost = 10;
    int supply = 60;
    SupplyChain supply_chain(inventory, demand, cost);
    Optimizer optimizer(supply_chain, supply);
    auto [shortage, fulfilled, cost] = optimizer.optimize();
    std::cout << "Shortage: " << shortage << ", Fulfilled: " << fulfilled << ", Cost: " << cost << std::endl;
    return 0;
}