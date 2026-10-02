#include <stdio.h>

typedef struct {
    int capacity;
    int current_stock;
} InventoryManager;

void InventoryManager_init(InventoryManager *self, int capacity) {
    self->capacity = capacity;
    self->current_stock = 0;
}

void InventoryManager_update_stock(InventoryManager *self, int amount) {
    if (self->current_stock + amount <= self->capacity) {
        self->current_stock += amount;
    } else {
        self->current_stock = self->capacity;
    }
}

int InventoryManager_get_stock_level(InventoryManager *self) {
    return self->current_stock;
}

typedef struct {
    InventoryManager *manager;
} LogisticsPlanner;

void LogisticsPlanner_init(LogisticsPlanner *self, InventoryManager *manager) {
    self->manager = manager;
}

void LogisticsPlanner_plan_shipment(LogisticsPlanner *self, int demand) {
    if (demand > InventoryManager_get_stock_level(self->manager)) {
        int shortage = demand - InventoryManager_get_stock_level(self->manager);
        InventoryManager_update_stock(self->manager, -shortage);
    } else {
        InventoryManager_update_stock(self->manager, -demand);
    }
}

int LogisticsPlanner_monitor_inventory(LogisticsPlanner *self) {
    return InventoryManager_get_stock_level(self->manager);
}

typedef struct {
    LogisticsPlanner *planner;
} SupplyChainOptimizer;

void SupplyChainOptimizer_init(SupplyChainOptimizer *self, LogisticsPlanner *planner) {
    self->planner = planner;
}

void SupplyChainOptimizer_optimize(SupplyChainOptimizer *self) {
    while (1) {
        int demand = 10;
        LogisticsPlanner_plan_shipment(self->planner, demand);
        int stock = LogisticsPlanner_monitor_inventory(self->planner);
        if (stock < 5) {
            InventoryManager_update_stock(self->planner->manager, 20);
        }
    }
}

int main() {
    InventoryManager inventory_manager;
    LogisticsPlanner logistics_planner;
    SupplyChainOptimizer supply_chain_optimizer;

    InventoryManager_init(&inventory_manager, 100);
    LogisticsPlanner_init(&logistics_planner, &inventory_manager);
    SupplyChainOptimizer_init(&supply_chain_optimizer, &logistics_planner);
    SupplyChainOptimizer_optimize(&supply_chain_optimizer);
    return 0;
}