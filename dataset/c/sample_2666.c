#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
} Sequence;

void Sequence_init(Sequence *self, int n) {
    self->n = n;
}

int Sequence_transform(Sequence *self, int x) {
    return (x * x + 3 * x + 1) % 101;
}

int* Sequence_generate(Sequence *self, int *length) {
    int *result = (int *)malloc(self->n * sizeof(int));
    for (int i = 0; i < self->n; i++) {
        result[i] = Sequence_transform(self, i);
    }
    *length = self->n;
    return result;
}

typedef struct {
    int *sequence;
    int sequence_length;
} HashSimulator;

void HashSimulator_init(HashSimulator *self, int *sequence, int sequence_length) {
    self->sequence = sequence;
    self->sequence_length = sequence_length;
}

int HashSimulator_hash(HashSimulator *self) {
    int total = 0;
    for (int i = 0; i < self->sequence_length; i++) {
        total = (total + self->sequence[i] * 23) % 1001;
    }
    return total;
}

typedef struct {
    int hash_value;
} CipherSimulator;

void CipherSimulator_init(CipherSimulator *self, int hash_value) {
    self->hash_value = hash_value;
}

int* CipherSimulator_encrypt(CipherSimulator *self, int *length) {
    int *encrypted = (int *)malloc(self->hash_value * sizeof(int));
    for (int i = 0; i < self->hash_value; i++) {
        encrypted[i] = (i * self->hash_value + i) % 1009;
    }
    *length = self->hash_value;
    return encrypted;
}

void main() {
    int n = 50;
    Sequence sequence;
    Sequence_init(&sequence, n);
    int sequence_length;
    int *sequence_data = Sequence_generate(&sequence, &sequence_length);
    HashSimulator hash_simulator;
    HashSimulator_init(&hash_simulator, sequence_data, sequence_length);
    int hash_value = HashSimulator_hash(&hash_simulator);
    CipherSimulator cipher_simulator;
    CipherSimulator_init(&cipher_simulator, hash_value);
    int cipher_length;
    int *encrypted = CipherSimulator_encrypt(&cipher_simulator, &cipher_length);
    for (int i = 0; i < cipher_length; i++) {
        printf("%d ", encrypted[i]);
    }
    printf("\n");
    free(sequence_data);
    free(encrypted);
}