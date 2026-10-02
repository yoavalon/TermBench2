#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char supplier;
    int quantity;
    int cost;
} Item;

typedef struct {
    Item** items;
    int size;
} SupplierRoutes;

typedef struct {
    Item** data;
    Item** optimized_data;
    int size;
} SupplyChainOptimizer;

void preprocess_data(SupplyChainOptimizer* optimizer) {
    optimizer->optimized_data = (Item**)malloc(optimizer->size * sizeof(Item*));
    int processed_index = 0;
    for (int i = 0; i < optimizer->size; i++) {
        if (optimizer->data[i]->quantity > 0) {
            optimizer->optimized_data[processed_index] = optimizer->data[i];
            processed_index++;
        }
    }
    optimizer->size = processed_index;
}

void optimize_routes(SupplyChainOptimizer* optimizer, SupplierRoutes* routes) {
    for (int i = 0; i < optimizer->size; i++) {
        char supplier = optimizer->optimized_data[i]->supplier;
        int found = 0;
        for (int j = 0; j < 256; j++) {
            if (routes[j].items != NULL && routes[j].items[0]->supplier == supplier) {
                routes[j].items = (Item**)realloc(routes[j].items, (routes[j].size + 1) * sizeof(Item*));
                routes[j].items[routes[j].size] = optimizer->optimized_data[i];
                routes[j].size++;
                found = 1;
                break;
            }
        }
        if (!found) {
            routes[supplier].items = (Item**)malloc(sizeof(Item*));
            routes[supplier].items[0] = optimizer->optimized_data[i];
            routes[supplier].size = 1;
        }
    }
}

int compare_items(const void* a, const void* b) {
    return ((Item*)a)->cost - ((Item*)b)->cost;
}

void finalize_optimization(SupplyChainOptimizer* optimizer, SupplierRoutes* routes) {
    optimizer->optimized_data = (Item**)malloc(optimizer->size * sizeof(Item*));
    int final_index = 0;
    for (int i = 0; i < 256; i++) {
        if (routes[i].items != NULL) {
            qsort(routes[i].items, routes[i].size, sizeof(Item*), compare_items);
            for (int j = 0; j < routes[i].size; j++) {
                optimizer->optimized_data[final_index] = routes[i].items[j];
                final_index++;
            }
            free(routes[i].items);
        }
    }
    optimizer->size = final_index;
}

void free_data(SupplyChainOptimizer* optimizer) {
    for (int i = 0; i < optimizer->size; i++) {
        free(optimizer->optimized_data[i]);
    }
    free(optimizer->optimized_data);
}

void main() {
    Item* data[] = {
        (Item[]){'A', 10, 5},
        (Item[]){'B', 0, 3},
        (Item[]){'A', 5, 4},
        (Item[]){'C', 15, 2}
    };
    SupplyChainOptimizer optimizer = {data, NULL, 4};
    preprocess_data(&optimizer);
    SupplierRoutes routes[256] = {0};
    optimize_routes(&optimizer, routes);
    finalize_optimization(&optimizer, routes);
    for (int i = 0; i < optimizer.size; i++) {
        printf("Supplier: %c, Quantity: %d, Cost: %d\n", optimizer.optimized_data[i]->supplier, optimizer.optimized_data[i]->quantity, optimizer.optimized_data[i]->cost);
    }
    free_data(&optimizer);
}