#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *data;
    int data_length;
    int result;
} HashSimulator;

typedef struct {
    int key;
    int *data;
    int data_length;
    int *result;
} CipherSimulator;

void HashSimulator_init(HashSimulator *self, int *data, int data_length) {
    self->data = data;
    self->data_length = data_length;
    self->result = 0;
}

int _hash_recursive(HashSimulator *self, int index) {
    if (index == self->data_length) {
        return 0;
    } else {
        return (self->data[index] + _hash_recursive(self, index + 1)) % 1000000007;
    }
}

void HashSimulator_compute_hash(HashSimulator *self) {
    if (self->data_length == 0) {
        self->result = 0;
    } else {
        self->result = _hash_recursive(self, 0);
    }
}

void CipherSimulator_init(CipherSimulator *self, int key, int *data, int data_length) {
    self->key = key;
    self->data = data;
    self->data_length = data_length;
    self->result = (int *)malloc(data_length * sizeof(int));
}

int *_encrypt_recursive(CipherSimulator *self, int index) {
    if (index == self->data_length) {
        return self->result;
    } else {
        self->result[index] = (self->data[index] + self->key) % 256;
        return _encrypt_recursive(self, index + 1);
    }
}

void CipherSimulator_encrypt(CipherSimulator *self) {
    if (self->data_length == 0) {
        self->result = NULL;
    } else {
        _encrypt_recursive(self, 0);
    }
}

int main() {
    const char *str = "Hello, World!";
    int data_length = strlen(str);
    int *data = (int *)malloc(data_length * sizeof(int));
    for (int i = 0; i < data_length; i++) {
        data[i] = (int)str[i];
    }

    HashSimulator hash_sim;
    HashSimulator_init(&hash_sim, data, data_length);
    HashSimulator_compute_hash(&hash_sim);
    printf("Hash: %d\n", hash_sim.result);

    int key = 42;
    CipherSimulator cipher_sim;
    CipherSimulator_init(&cipher_sim, key, data, data_length);
    CipherSimulator_encrypt(&cipher_sim);
    printf("Encrypted: ");
    for (int i = 0; i < cipher_sim.data_length; i++) {
        printf("%d ", cipher_sim.result[i]);
    }
    printf("\n");

    free(data);
    free(cipher_sim.result);

    return 0;
}