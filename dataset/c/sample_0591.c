#include <stdio.h>

typedef struct {
    int capacity;
    int current_load;
} LogisticsSystem;

void LogisticsSystem_init(LogisticsSystem *self, int capacity) {
    self->capacity = capacity;
    self->current_load = 0;
}

int LogisticsSystem_add_load(LogisticsSystem *self, int load) {
    if (self->current_load + load <= self->capacity) {
        self->current_load += load;
        return 1;
    }
    return 0;
}

int LogisticsSystem_remove_load(LogisticsSystem *self, int load) {
    if (load <= self->current_load) {
        self->current_load -= load;
        return 1;
    }
    return 0;
}

void LogisticsSystem_get_load_status(LogisticsSystem *self, int *current_load, int *remaining_capacity) {
    *current_load = self->current_load;
    *remaining_capacity = self->capacity - self->current_load;
}

typedef struct {
    int demand;
    int current_demand;
} DemandHandler;

void DemandHandler_init(DemandHandler *self, int demand) {
    self->demand = demand;
    self->current_demand = demand;
}

void DemandHandler_update_demand(DemandHandler *self, int change) {
    self->current_demand += change;
    if (self->current_demand < 0) {
        self->current_demand = 0;
    }
}

int DemandHandler_get_demand(DemandHandler *self) {
    return self->current_demand;
}

typedef struct {
    LogisticsSystem *logistics;
    DemandHandler *demand_handler;
} SupplyOptimizer;

void SupplyOptimizer_init(SupplyOptimizer *self, LogisticsSystem *logistics, DemandHandler *demand_handler) {
    self->logistics = logistics;
    self->demand_handler = demand_handler;
}

void SupplyOptimizer_optimize(SupplyOptimizer *self) {
    int supply, remaining_capacity;
    LogisticsSystem_get_load_status(self->logistics, &supply, &remaining_capacity);
    int demand = DemandHandler_get_demand(self->demand_handler);
    if (demand > supply) {
        int shortfall = demand - supply;
        if (LogisticsSystem_add_load(self->logistics, shortfall)) {
            DemandHandler_update_demand(self->demand_handler, -shortfall);
        }
    } else if (supply > demand) {
        int excess = supply - demand;
        LogisticsSystem_remove_load(self->logistics, excess);
    }
}

int main() {
    LogisticsSystem logistics;
    LogisticsSystem_init(&logistics, 100);
    DemandHandler demand_handler;
    DemandHandler_init(&demand_handler, 50);
    SupplyOptimizer optimizer;
    SupplyOptimizer_init(&optimizer, &logistics, &demand_handler);
    while (1) {
        SupplyOptimizer_optimize(&optimizer);
    }
    return 0;
}