#include <iostream>
#include <cstdlib>
#include <ctime>

class Inventory {
public:
    Inventory(int initial_stock, int replenish_rate) : stock(initial_stock), replenish_rate(replenish_rate) {}

    void update_stock(double demand) {
        stock -= demand;
        if (stock < 0) {
            stock = 0;
        }
    }

    void replenish() {
        stock += replenish_rate;
    }

private:
    int stock;
    int replenish_rate;
};

class DemandGenerator {
public:
    double generate() {
        return static_cast<double>(rand()) / RAND_MAX * 9 + 1;
    }
};

class SupplyChainOptimizer {
public:
    SupplyChainOptimizer(Inventory& inventory, DemandGenerator& demand_generator) : inventory(inventory), demand_generator(demand_generator) {}

    void run_optimization() {
        while (true) {
            double demand = demand_generator.generate();
            inventory.update_stock(demand);
            inventory.replenish();
        }
    }

private:
    Inventory& inventory;
    DemandGenerator& demand_generator;
};

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int initial_stock = 100;
    int replenish_rate = 10;
    Inventory inventory(initial_stock, replenish_rate);
    DemandGenerator demand_generator;
    SupplyChainOptimizer optimizer(inventory, demand_generator);
    optimizer.run_optimization();
    return 0;
}