cpp
#include <iostream>

class InventoryManager {
public:
    int capacity;
    int current_stock;

    InventoryManager(int capacity) : capacity(capacity), current_stock(0) {}

    void update_stock(int amount) {
        if (current_stock + amount <= capacity) {
            current_stock += amount;
        } else {
            current_stock = capacity;
        }
    }

    int get_stock_level() {
        return current_stock;
    }
};

class LogisticsPlanner {
public:
    InventoryManager* manager;

    LogisticsPlanner(InventoryManager* manager) : manager(manager) {}

    void plan_shipment(int demand) {
        if (demand > manager->get_stock_level()) {
            int shortage = demand - manager->get_stock_level();
            manager->update_stock(-shortage);
        } else {
            manager->update_stock(-demand);
        }
    }

    int monitor_inventory() {
        return manager->get_stock_level();
    }
};

class SupplyChainOptimizer {
public:
    LogisticsPlanner* planner;

    SupplyChainOptimizer(LogisticsPlanner* planner) : planner(planner) {}

    void optimize() {
        while (true) {
            int demand = 10;
            planner->plan_shipment(demand);
            int stock = planner->monitor_inventory();
            if (stock < 5) {
                planner->manager->update_stock(20);
            }
        }
    }
};

int main() {
    InventoryManager inventory_manager(100);
    LogisticsPlanner logistics_planner(&inventory_manager);
    SupplyChainOptimizer supply_chain_optimizer(&logistics_planner);
    supply_chain_optimizer.optimize();
    return 0;
}