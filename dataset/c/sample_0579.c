#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int inventory;
    int *demand;
    int demand_size;
    int *orders;
    int orders_size;
    int *deliveries;
    int deliveries_size;
} SupplyChain;

typedef struct {
    SupplyChain *supply_chain;
} LogisticsOptimizer;

void supply_chain_init(SupplyChain *sc, int inventory, int *demand, int demand_size) {
    sc->inventory = inventory;
    sc->demand = demand;
    sc->demand_size = demand_size;
    sc->orders = (int *)malloc(0 * sizeof(int));
    sc->orders_size = 0;
    sc->deliveries = (int *)malloc(0 * sizeof(int));
    sc->deliveries_size = 0;
}

void supply_chain_process_orders(SupplyChain *sc) {
    while (sc->orders_size > 0) {
        int order = sc->orders[0];
        for (int i = 0; i < sc->orders_size - 1; i++) {
            sc->orders[i] = sc->orders[i + 1];
        }
        sc->orders_size--;

        if (sc->inventory >= order) {
            sc->inventory -= order;
            sc->deliveries = (int *)realloc(sc->deliveries, (sc->deliveries_size + 1) * sizeof(int));
            sc->deliveries[sc->deliveries_size++] = order;
        } else {
            sc->orders = (int *)realloc(sc->orders, (sc->orders_size + 1) * sizeof(int));
            for (int i = sc->orders_size - 1; i > 0; i--) {
                sc->orders[i] = sc->orders[i - 1];
            }
            sc->orders[0] = order;
            sc->orders_size++;
        }
    }
}

void supply_chain_receive_supply(SupplyChain *sc, int supply) {
    sc->inventory += supply;
}

void supply_chain_handle_demand(SupplyChain *sc) {
    for (int i = 0; i < sc->demand_size; i++) {
        if (sc->demand_size > 0) {
            int order = sc->demand[0];
            for (int j = 0; j < sc->demand_size - 1; j++) {
                sc->demand[j] = sc->demand[j + 1];
            }
            sc->demand_size--;

            sc->orders = (int *)realloc(sc->orders, (sc->orders_size + 1) * sizeof(int));
            sc->orders[sc->orders_size++] = order;
        }
    }
}

void logistics_optimizer_init(LogisticsOptimizer *lo, SupplyChain *supply_chain) {
    lo->supply_chain = supply_chain;
}

void logistics_optimizer_optimize(LogisticsOptimizer *lo) {
    while (1) {
        supply_chain_handle_demand(lo->supply_chain);
        supply_chain_process_orders(lo->supply_chain);
        if (lo->supply_chain->orders_size > 0) {
            int total_orders = 0;
            for (int i = 0; i < lo->supply_chain->orders_size; i++) {
                total_orders += lo->supply_chain->orders[i];
            }
            supply_chain_receive_supply(lo->supply_chain, total_orders);
        }
    }
}

int main() {
    int inventory = 100;
    int demand[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int demand_size = sizeof(demand) / sizeof(demand[0]);

    SupplyChain supply_chain;
    supply_chain_init(&supply_chain, inventory, demand, demand_size);

    LogisticsOptimizer optimizer;
    logistics_optimizer_init(&optimizer, &supply_chain);

    logistics_optimizer_optimize(&optimizer);

    free(supply_chain.orders);
    free(supply_chain.deliveries);

    return 0;
}