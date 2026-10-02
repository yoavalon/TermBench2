#include <iostream>

class SequenceGenerator {
public:
    SequenceGenerator(int a, int b) : a(a), b(b), current(a) {}

    int next() {
        current += b;
        return current;
    }

private:
    int a;
    int b;
    int current;
};

class InventoryOptimizer {
public:
    InventoryOptimizer(int initial_stock, SequenceGenerator demand_sequence) 
        : stock(initial_stock), demand_sequence(demand_sequence), current_demand(0) {}

    void update_stock(int supply) {
        stock += supply;
    }

    void process_demand() {
        current_demand = demand_sequence.next();
        if (stock >= current_demand) {
            stock -= current_demand;
        } else {
            stock = 0;
        }
    }

private:
    int stock;
    SequenceGenerator demand_sequence;
    int current_demand;
};

class SupplyChainSimulator {
public:
    SupplyChainSimulator(int initial_stock, int demand_a, int demand_b, int supply_a, int supply_b) 
        : inventory_optimizer(initial_stock, SequenceGenerator(demand_a, demand_b)), 
          supply_sequence(SequenceGenerator(supply_a, supply_b)) {}

    void run() {
        while (true) {
            int supply = supply_sequence.next();
            inventory_optimizer.update_stock(supply);
            inventory_optimizer.process_demand();
        }
    }

private:
    InventoryOptimizer inventory_optimizer;
    SequenceGenerator supply_sequence;
};

int main() {
    int initial_stock = 100;
    int demand_a = 10;
    int demand_b = 5;
    int supply_a = 20;
    int supply_b = 10;
    SupplyChainSimulator simulator(initial_stock, demand_a, demand_b, supply_a, supply_b);
    simulator.run();
    return 0;
}