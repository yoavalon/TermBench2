#include <stdio.h>
#include <limits.h>

void calculate_optimal_order_quantity(int demand, double holding_cost, int ordering_cost, int lead_time, double *order_quantity, double *total_cost) {
    double safety_stock = 2 * demand * lead_time;
    *order_quantity = 2 * demand * ordering_cost / holding_cost;
    *total_cost = holding_cost * (*order_quantity / 2 + safety_stock) + ordering_cost * (demand / *order_quantity);
}

void find_minimum_cost(int *demands, double *holding_costs, int *ordering_costs, int *lead_times, int length, double *best_order_quantity, double *minimum_cost) {
    *minimum_cost = INT_MAX;
    for (int i = 0; i < length; i++) {
        double order_quantity, total_cost;
        calculate_optimal_order_quantity(demands[i], holding_costs[i], ordering_costs[i], lead_times[i], &order_quantity, &total_cost);
        if (total_cost < *minimum_cost) {
            *minimum_cost = total_cost;
            *best_order_quantity = order_quantity;
        }
    }
}

int main() {
    int demands[] = {100, 150, 200};
    double holding_costs[] = {0.5, 0.6, 0.7};
    int ordering_costs[] = {20, 25, 30};
    int lead_times[] = {5, 4, 3};
    int length = sizeof(demands) / sizeof(demands[0]);
    double best_order_quantity, minimum_cost;
    find_minimum_cost(demands, holding_costs, ordering_costs, lead_times, length, &best_order_quantity, &minimum_cost);
    printf("Best Order Quantity: %.2f Minimum Cost: %.2f\n", best_order_quantity, minimum_cost);
    return 0;
}