c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_RECORDS 100

typedef struct {
    int id;
    int quantity;
    double cost;
    double optimized_quantity;
    double total_cost;
} DataRecord;

DataRecord* load_data() {
    DataRecord* data = (DataRecord*)malloc(NUM_RECORDS * sizeof(DataRecord));
    for (int i = 0; i < NUM_RECORDS; i++) {
        data[i].id = i + 1;
        data[i].quantity = rand() % 99 + 1;
        data[i].cost = (double)rand() / RAND_MAX * 1000;
    }
    return data;
}

DataRecord* optimize_supply_chain(DataRecord* data) {
    for (int i = 0; i < NUM_RECORDS; i++) {
        data[i].optimized_quantity = data[i].quantity * 1.1;
        data[i].total_cost = data[i].optimized_quantity * data[i].cost;
    }
    return data;
}

DataRecord* process_data() {
    DataRecord* df = load_data();
    DataRecord* optimized_df = optimize_supply_chain(df);
    return optimized_df;
}

void print_data(DataRecord* data, int num_records) {
    printf("ID\tQuantity\tCost\tOptimized Quantity\tTotal Cost\n");
    for (int i = 0; i < num_records; i++) {
        printf("%d\t%d\t%.2f\t%.2f\t%.2f\n", data[i].id, data[i].quantity, data[i].cost, data[i].optimized_quantity, data[i].total_cost);
    }
}

int main() {
    srand(time(0));
    DataRecord* result = process_data();
    print_data(result, 5);
    free(result);
    return 0;
}