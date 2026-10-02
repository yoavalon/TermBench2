#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    double value;
} Item;

typedef struct {
    int id;
    double adjusted_value;
} AdjustedItem;

AdjustedItem* optimize_supply_chain(Item* data, int length, int precision, int* result_length) {
    AdjustedItem* result = (AdjustedItem*)malloc(length * sizeof(AdjustedItem));
    for (int i = 0; i < length; i++) {
        result[i].id = data[i].id;
        result[i].adjusted_value = round(data[i].value * pow(10, precision)) / pow(10, precision);
    }
    *result_length = length;
    return result;
}

int main() {
    Item data[] = {{1, 123.456789}, {2, 987.654321}};
    int precision = 3;
    int result_length;
    AdjustedItem* optimized_data = optimize_supply_chain(data, 2, precision, &result_length);

    printf("[");
    for (int i = 0; i < result_length; i++) {
        printf("{id: %d, adjusted_value: %.3f}", optimized_data[i].id, optimized_data[i].adjusted_value);
        if (i < result_length - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    free(optimized_data);
    return 0;
}