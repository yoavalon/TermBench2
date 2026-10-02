#include <stdio.h>

typedef struct {
    int *demand_sequence;
    int production_capacity;
    int inventory;
    int backlog;
    int total_cost;
    int *production_plan;
} SupplyChainOptimization;

void SupplyChainOptimization_init(SupplyChainOptimization *self, int *demand_sequence, int production_capacity) {
    self->demand_sequence = demand_sequence;
    self->production_capacity = production_capacity;
    self->inventory = 0;
    self->backlog = 0;
    self->total_cost = 0;
    self->production_plan = (int *)malloc(10 * sizeof(int)); // Assuming a maximum of 10 demands
}

int SupplyChainOptimization_calculate_production(SupplyChainOptimization *self, int demand) {
    int production;
    if (demand > self->production_capacity) {
        production = self->production_capacity;
        self->backlog += demand - self->production_capacity;
    } else {
        production = demand;
    }
    return production;
}

void SupplyChainOptimization_update_inventory(SupplyChainOptimization *self, int production, int demand) {
    self->inventory += production - demand;
}

void SupplyChainOptimization_update_cost(SupplyChainOptimization *self, int production, int demand) {
    if (self->backlog > 0) {
        self->total_cost += self->backlog * 10;
    }
    self->total_cost += production * 5;
}

void SupplyChainOptimization_run_optimization(SupplyChainOptimization *self) {
    for (int i = 0; self->demand_sequence[i] != 0; i++) {
        int demand = self->demand_sequence[i];
        int production = SupplyChainOptimization_calculate_production(self, demand);
        self->production_plan[i] = production;
        SupplyChainOptimization_update_inventory(self, production, demand);
        SupplyChainOptimization_update_cost(self, production, demand);
    }
}

void main() {
    int demand_sequence[] = {100, 150, 200, 250, 300, 350, 400, 450, 500, 550, 0}; // Add 0 to indicate end of sequence
    int production_capacity = 250;
    SupplyChainOptimization optimizer;
    SupplyChainOptimization_init(&optimizer, demand_sequence, production_capacity);
    SupplyChainOptimization_run_optimization(&optimizer);
    printf("Total Cost: %d\n", optimizer.total_cost);
    printf("Final Inventory: %d\n", optimizer.inventory);
    printf("Final Backlog: %d\n", optimizer.backlog);
    printf("Production Plan: ");
    for (int i = 0; demand_sequence[i] != 0; i++) {
        printf("%d ", optimizer.production_plan[i]);
    }
    printf("\n");
    free(optimizer.production_plan);
}

int main() {
    main();
    return 0;
}