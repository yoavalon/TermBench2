#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int *optimized_data;
    int data_size;
    int optimized_data_size;
} SupplyChainOptimizer;

void SupplyChainOptimizer_init(SupplyChainOptimizer *self, int *data, int size) {
    self->data = data;
    self->data_size = size;
    self->optimized_data = (int *)malloc(size * sizeof(int));
    self->optimized_data_size = 0;
}

void SupplyChainOptimizer_calculate_optimal_route(SupplyChainOptimizer *self) {
    for (int i = 0; i < self->data_size; i++) {
        self->optimized_data[self->optimized_data_size++] = self->_optimize_item(self->data[i]);
    }
}

int SupplyChainOptimizer__optimize_item(int item) {
    return item * 2;
}

typedef struct {
    int start;
    int end;
    int *sequence;
    int sequence_size;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, int start, int end) {
    self->start = start;
    self->end = end;
    self->sequence_size = 0;
    self->sequence = (int *)malloc((end - start + 1) * sizeof(int));
}

void SequenceGenerator_generate_sequence(SequenceGenerator *self) {
    int current = self->start;
    while (current <= self->end) {
        self->sequence[self->sequence_size++] = current;
        current++;
    }
}

int *SequenceGenerator_get_sequence(SequenceGenerator *self) {
    return self->sequence;
}

void main() {
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int data_size = sizeof(data) / sizeof(data[0]);
    SupplyChainOptimizer optimizer;
    SupplyChainOptimizer_init(&optimizer, data, data_size);
    SupplyChainOptimizer_calculate_optimal_route(&optimizer);
    int *optimized_data = optimizer.optimized_data;

    int start = 1, end = 10;
    SequenceGenerator sequence_generator;
    SequenceGenerator_init(&sequence_generator, start, end);
    SequenceGenerator_generate_sequence(&sequence_generator);
    int *sequence = SequenceGenerator_get_sequence(&sequence_generator);

    for (int i = 0; i < optimizer.optimized_data_size; i++) {
        printf("Optimized Data: %d, Sequence: %d\n", optimized_data[i], sequence[i]);
    }

    free(optimizer.optimized_data);
    free(sequence_generator.sequence);
}