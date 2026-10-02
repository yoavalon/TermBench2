#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int* data;
    int* optimized_data;
    int size;
} SupplyChainOptimizer;

typedef struct {
    int* data;
    int size;
} DataMutator;

void SupplyChainOptimizer_init(SupplyChainOptimizer* optimizer, int* data, int size) {
    optimizer->data = data;
    optimizer->size = size;
    optimizer->optimized_data = (int*)malloc(size * sizeof(int));
}

void SupplyChainOptimizer_process_data(SupplyChainOptimizer* optimizer) {
    for (int i = 0; i < optimizer->size; i++) {
        optimizer->optimized_data[i] = SupplyChainOptimizer_mutate_item(optimizer, optimizer->data[i]);
    }
}

int SupplyChainOptimizer_mutate_item(SupplyChainOptimizer* optimizer, int item) {
    double mutation_factor = ((double)rand() / RAND_MAX) * 0.2 - 0.1;
    return (int)(item * (1 + mutation_factor));
}

void DataMutator_init(DataMutator* mutator, int* data, int size) {
    mutator->data = data;
    mutator->size = size;
}

void DataMutator_apply_mutations(DataMutator* mutator) {
    for (int i = 0; i < mutator->size; i++) {
        mutator->data[i] = DataMutator_mutate_value(mutator, mutator->data[i]);
    }
}

int DataMutator_mutate_value(DataMutator* mutator, int value) {
    double mutation_rate = (double)rand() / RAND_MAX;
    if (mutation_rate < 0.5) {
        return (int)(value * 1.1);
    } else {
        return (int)(value * 0.9);
    }
}

void main() {
    srand(time(NULL));
    int initial_data[50];
    for (int i = 0; i < 50; i++) {
        initial_data[i] = rand() % 100 + 1;
    }

    SupplyChainOptimizer optimizer;
    SupplyChainOptimizer_init(&optimizer, initial_data, 50);
    SupplyChainOptimizer_process_data(&optimizer);

    DataMutator mutator;
    DataMutator_init(&mutator, optimizer.optimized_data, 50);
    DataMutator_apply_mutations(&mutator);

    for (int i = 0; i < mutator.size; i++) {
        printf("%d\n", mutator.data[i]);
    }

    free(optimizer.optimized_data);
}