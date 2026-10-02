#include <stdio.h>

typedef struct {
    int capacity;
    int demand;
    int cost;
    int inventory;
    int revenue;
    int total_cost;
} SupplyChainModel;

void update_inventory(SupplyChainModel *model) {
    if (model->demand > model->capacity) {
        model->inventory += model->capacity;
    } else {
        model->inventory += model->demand;
    }
}

void calculate_revenue(SupplyChainModel *model) {
    model->revenue = (model->demand < model->inventory ? model->demand : model->inventory) * model->cost;
}

void calculate_total_cost(SupplyChainModel *model) {
    model->total_cost = model->capacity * model->cost;
}

int optimize(SupplyChainModel *model) {
    update_inventory(model);
    calculate_revenue(model);
    calculate_total_cost(model);
    return model->revenue - model->total_cost;
}

int run_optimization() {
    int capacity = 100;
    int demand = 80;
    int cost = 10;
    SupplyChainModel model = {capacity, demand, cost, 0, 0, 0};
    int profit = optimize(&model);
    return profit;
}

void main() {
    int profit = run_optimization();
    printf("Optimized Profit: %d\n", profit);
}