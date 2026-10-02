c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
    int n;
    int current;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, int a, int b, int n) {
    self->a = a;
    self->b = b;
    self->n = n;
    self->current = a;
}

int SequenceGenerator_generate_next(SequenceGenerator *self) {
    if (self->current < self->n) {
        self->current += self->b;
        return self->current;
    }
    return -1; // Using -1 to represent None
}

typedef struct {
    SequenceGenerator *sequence;
    int *optimized;
    int size;
} LogisticsOptimizer;

void LogisticsOptimizer_init(LogisticsOptimizer *self, SequenceGenerator *sequence) {
    self->sequence = sequence;
    self->optimized = NULL;
    self->size = 0;
}

int* LogisticsOptimizer_optimize(LogisticsOptimizer *self) {
    while (1) {
        int next_value = SequenceGenerator_generate_next(self->sequence);
        if (next_value == -1) {
            break;
        }
        self->optimized = realloc(self->optimized, (self->size + 1) * sizeof(int));
        self->optimized[self->size++] = next_value;
    }
    return self->optimized;
}

int main() {
    int a = 1;
    int b = 2;
    int n = 20;
    SequenceGenerator sequence;
    LogisticsOptimizer optimizer;

    SequenceGenerator_init(&sequence, a, b, n);
    LogisticsOptimizer_init(&optimizer, &sequence);

    int *result = LogisticsOptimizer_optimize(&optimizer);
    for (int i = 0; i < optimizer.size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}