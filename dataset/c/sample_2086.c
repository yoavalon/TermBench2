#include <stdio.h>
#include <math.h>

typedef struct {
    int demand;
    int supply;
    double transport_cost;
    double holding_cost;
    int inventory;
} SupplyChain;

SupplyChain create_supply_chain(int demand, int supply, double transport_cost, double holding_cost) {
    SupplyChain sc;
    sc.demand = demand;
    sc.supply = supply;
    sc.transport_cost = transport_cost;
    sc.holding_cost = holding_cost;
    sc.inventory = supply;
    return sc;
}

double calculate_total_cost(SupplyChain *sc, int quantity) {
    if (quantity > sc->supply) {
        return INFINITY;
    }
    double transport = quantity * sc->transport_cost;
    double holding = sc->holding_cost * pow(sc->supply - quantity, 2);
    return transport + holding;
}

int optimize_order_quantity(SupplyChain *sc) {
    double min_cost = INFINITY;
    int optimal_quantity = 0;
    for (int quantity = 1; quantity <= sc->supply; quantity++) {
        double cost = calculate_total_cost(sc, quantity);
        if (cost < min_cost) {
            min_cost = cost;
            optimal_quantity = quantity;
        }
    }
    return optimal_quantity;
}

int main() {
    int demand = 100;
    int supply = 150;
    double transport_cost = 2.5;
    double holding_cost = 0.1;
    SupplyChain supply_chain = create_supply_chain(demand, supply, transport_cost, holding_cost);
    int optimal_quantity = optimize_order_quantity(&supply_chain);
    printf("Optimal Order Quantity: %d\n", optimal_quantity);
    return 0;
}