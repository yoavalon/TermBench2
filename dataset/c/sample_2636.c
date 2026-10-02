#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
} SequenceGenerator;

typedef struct {
    int* sequence;
    int length;
} ConsensusMechanism;

typedef struct {
    SequenceGenerator* generator;
    ConsensusMechanism* verifier;
} Executor;

SequenceGenerator* SequenceGenerator_init(int a, int b) {
    SequenceGenerator* self = (SequenceGenerator*)malloc(sizeof(SequenceGenerator));
    self->a = a;
    self->b = b;
    return self;
}

int* SequenceGenerator_generate(SequenceGenerator* self, int n) {
    int* result = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            result[i] = self->a;
        } else {
            result[i] = self->b;
        }
    }
    return result;
}

ConsensusMechanism* ConsensusMechanism_init(int* sequence, int length) {
    ConsensusMechanism* self = (ConsensusMechanism*)malloc(sizeof(ConsensusMechanism));
    self->sequence = sequence;
    self->length = length;
    return self;
}

int ConsensusMechanism_verify(ConsensusMechanism* self) {
    int count_a = 0;
    for (int i = 0; i < self->length; i++) {
        if (self->sequence[i] == self->sequence[0]) {
            count_a++;
        }
    }
    int count_b = self->length - count_a;
    return count_a == count_b;
}

Executor* Executor_init(SequenceGenerator* generator, ConsensusMechanism* verifier) {
    Executor* self = (Executor*)malloc(sizeof(Executor));
    self->generator = generator;
    self->verifier = verifier;
    return self;
}

int* Executor_run(Executor* self, int* sequence_length) {
    int* sequence = SequenceGenerator_generate(self->generator, 10);
    self->verifier->sequence = sequence;
    self->verifier->length = 10;
    int is_valid = ConsensusMechanism_verify(self->verifier);
    *sequence_length = 10;
    return sequence;
}

void main() {
    SequenceGenerator* seq_gen = SequenceGenerator_init(1, 0);
    ConsensusMechanism* consensus = ConsensusMechanism_init(NULL, 0);
    Executor* executor = Executor_init(seq_gen, consensus);
    int sequence_length;
    int* sequence = Executor_run(executor, &sequence_length);
    printf("Sequence: ");
    for (int i = 0; i < sequence_length; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\n");
    printf("Consensus Validity: %d\n", consensus->sequence == sequence);
    free(seq_gen);
    free(consensus->sequence);
    free(consensus);
    free(executor);
}