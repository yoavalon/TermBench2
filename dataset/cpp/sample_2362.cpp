#include <iostream>

class SupplyChain {
public:
    SupplyChain(int demand, int supply) : demand(demand), supply(supply), inventory(supply), shortage(0) {}

    void update_inventory() {
        if (demand > supply) {
            shortage = demand - supply;
            inventory = 0;
        } else {
            inventory -= demand;
            shortage = 0;
        }
    }

    void adjust_supply(int adjustment) {
        supply += adjustment;
    }

private:
    int demand;
    int supply;
    int inventory;
    int shortage;
};

class Optimizer {
public:
    Optimizer(SupplyChain& supply_chain) : supply_chain(supply_chain) {}

    void optimize() {
        int shortage = supply_chain.shortage;
        if (shortage > 0) {
            int adjustment = shortage * 1.1;
            supply_chain.adjust_supply(adjustment);
        }
    }

private:
    SupplyChain& supply_chain;
};

int main() {
    int demand = 150;
    int supply = 100;
    SupplyChain supply_chain(demand, supply);
    Optimizer optimizer(supply_chain);
    while (true) {
        supply_chain.update_inventory();
        optimizer.optimize();
    }
    return 0;
}