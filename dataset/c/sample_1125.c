#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* data;
} HashSimulator;

typedef struct {
    char* data;
} CipherSimulator;

typedef struct {
    char* data;
    int iterations;
} RecursiveSimulator;

char* hash_function(HashSimulator* self, char* value, int iterations) {
    if (iterations == 0) {
        return value;
    } else {
        char* new_value = cipher_function(self, value);
        return hash_function(self, new_value, iterations - 1);
    }
}

char* cipher_function(HashSimulator* self, char* value) {
    int new_value = 0;
    for (int i = 0; i < strlen(value); i++) {
        new_value += value[i];
    }
    char* result = (char*)malloc(20);
    sprintf(result, "%d", new_value);
    return result;
}

char* cipher_function_cipher(CipherSimulator* self, char* value) {
    char* new_value = (char*)malloc(strlen(value) + 1);
    for (int i = 0; i < strlen(value); i++) {
        new_value[i] = value[i] + 1;
    }
    new_value[strlen(value)] = '\0';
    return new_value;
}

void run_simulation(RecursiveSimulator* self) {
    HashSimulator hash_simulator;
    hash_simulator.data = self->data;

    CipherSimulator cipher_simulator;
    cipher_simulator.data = self->data;

    self->data = cipher_function_cipher(&cipher_simulator, self->data);
    self->data = hash_function(&hash_simulator, self->data, self->iterations);
    run_simulation(self);
}

int main() {
    char* initial_data = "start";
    int iterations = 10;
    RecursiveSimulator simulator;
    simulator.data = initial_data;
    simulator.iterations = iterations;
    run_simulation(&simulator);
    return 0;
}