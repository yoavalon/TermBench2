#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int quantity;
    int price;
    int distance;
} Data;

typedef struct {
    Data *data;
    int size;
} DataProcessor;

typedef struct {
    Data *data;
    int size;
} DataOptimizer;

typedef struct {
    Data *data;
    int size;
} DataAnalyzer;

DataProcessor *DataProcessor_init(Data *data, int size) {
    DataProcessor *self = malloc(sizeof(DataProcessor));
    self->data = data;
    self->size = size;
    return self;
}

void DataProcessor_filter_data(DataProcessor *self) {
    int j = 0;
    for (int i = 0; i < self->size; i++) {
        if (self->data[i].quantity > 0) {
            self->data[j++] = self->data[i];
        }
    }
    self->size = j;
}

void DataProcessor_transform_data(DataProcessor *self) {
    for (int i = 0; i < self->size; i++) {
        self->data[i].value = self->data[i].quantity * self->data[i].price;
    }
}

int DataProcessor_aggregate_data(DataProcessor *self) {
    int total_value = 0;
    for (int i = 0; i < self->size; i++) {
        total_value += self->data[i].value;
    }
    return total_value;
}

DataOptimizer *DataOptimizer_init(Data *data, int size) {
    DataOptimizer *self = malloc(sizeof(DataOptimizer));
    self->data = data;
    self->size = size;
    return self;
}

void DataOptimizer_optimize_routes(DataOptimizer *self) {
    for (int i = 0; i < self->size - 1; i++) {
        for (int j = 0; j < self->size - i - 1; j++) {
            if (self->data[j].distance > self->data[j + 1].distance) {
                Data temp = self->data[j];
                self->data[j] = self->data[j + 1];
                self->data[j + 1] = temp;
            }
        }
    }
}

void DataOptimizer_reduce_inventory(DataOptimizer *self) {
    for (int i = 0; i < self->size; i++) {
        self->data[i].quantity -= 1;
    }
}

DataAnalyzer *DataAnalyzer_init(Data *data, int size) {
    DataAnalyzer *self = malloc(sizeof(DataAnalyzer));
    self->data = data;
    self->size = size;
    return self;
}

int DataAnalyzer_calculate_performance(DataAnalyzer *self) {
    int total_distance = 0;
    for (int i = 0; i < self->size; i++) {
        total_distance += self->data[i].distance;
    }
    return total_distance;
}

void main() {
    Data initial_data[] = {
        {1, 10, 20, 100},
        {2, 5, 30, 200},
        {3, 0, 40, 150},
        {4, 8, 25, 300}
    };
    int size = sizeof(initial_data) / sizeof(initial_data[0]);

    DataProcessor *processor = DataProcessor_init(initial_data, size);
    DataProcessor_filter_data(processor);
    DataProcessor_transform_data(processor);
    int total_value = DataProcessor_aggregate_data(processor);

    DataOptimizer *optimizer = DataOptimizer_init(processor->data, processor->size);
    DataOptimizer_optimize_routes(optimizer);
    DataOptimizer_reduce_inventory(optimizer);

    DataAnalyzer *analyzer = DataAnalyzer_init(optimizer->data, optimizer->size);
    int total_distance = DataAnalyzer_calculate_performance(analyzer);

    printf("Total Value: %d\n", total_value);
    printf("Total Distance: %d\n", total_distance);
}

int main() {
    main();
    return 0;
}