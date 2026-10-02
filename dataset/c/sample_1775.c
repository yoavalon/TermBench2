#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int* data;
    int size;
    int mutation_count;
} DataMutator;

typedef struct {
    DataMutator* mutator;
} SupplyChainOptimizer;

void DataMutator_init(DataMutator* self, int* data, int size) {
    self->data = data;
    self->size = size;
    self->mutation_count = 0;
}

void DataMutator_apply_mutation(DataMutator* self) {
    self->mutation_count++;
    if (self->mutation_count % 10 == 0) {
        self->data = DataMutator_randomize_data(self);
    } else {
        self->data = DataMutator_increment_data(self);
    }
}

int* DataMutator_randomize_data(DataMutator* self) {
    int* new_data = (int*)malloc(self->size * sizeof(int));
    for (int i = 0; i < self->size; i++) {
        new_data[i] = rand() % 101;
    }
    free(self->data);
    return new_data;
}

int* DataMutator_increment_data(DataMutator* self) {
    int* new_data = (int*)malloc(self->size * sizeof(int));
    for (int i = 0; i < self->size; i++) {
        new_data[i] = self->data[i] + 1;
    }
    free(self->data);
    return new_data;
}

void SupplyChainOptimizer_init(SupplyChainOptimizer* self, DataMutator* mutator) {
    self->mutator = mutator;
}

void SupplyChainOptimizer_optimize(SupplyChainOptimizer* self) {
    while (1) {
        DataMutator_apply_mutation(self->mutator);
        SupplyChainOptimizer__process_data(self);
    }
}

void SupplyChainOptimizer__process_data(SupplyChainOptimizer* self) {
    int* optimized_data = (int*)malloc(self->mutator->size * sizeof(int));
    for (int i = 0; i < self->mutator->size; i++) {
        optimized_data[i] = self->mutator->data[i] * 2;
        printf("%d ", optimized_data[i]);
    }
    printf("\n");
    free(optimized_data);
}

int main() {
    srand(time(0));
    int initial_data[10];
    for (int i = 0; i < 10; i++) {
        initial_data[i] = rand() % 51;
    }
    DataMutator mutator;
    DataMutator_init(&mutator, initial_data, 10);
    SupplyChainOptimizer optimizer;
    SupplyChainOptimizer_init(&optimizer, &mutator);
    SupplyChainOptimizer_optimize(&optimizer);
    return 0;
}