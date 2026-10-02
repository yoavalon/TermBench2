#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

typedef struct {
    char* data;
    char* hash;
    char* cipher;
} DataProcessor;

typedef struct {
    DataProcessor processor;
} DataSimulator;

void hash_data(DataProcessor* processor) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, processor->data, strlen(processor->data));
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_Final(hash, &sha256);
    processor->hash = (char*)malloc(SHA256_DIGEST_LENGTH * 2 + 1);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&processor->hash[i * 2], "%02x", hash[i]);
    }
}

void cipher_data(DataProcessor* processor) {
    processor->cipher = (char*)malloc(strlen(processor->data) + 1);
    for (int i = 0; i < strlen(processor->data); i++) {
        processor->cipher[i] = (char)((unsigned char)processor->data[i] + 3) % 256;
    }
    processor->cipher[strlen(processor->data)] = '\0';
}

void update_data(DataProcessor* processor, const char* new_data) {
    free(processor->data);
    processor->data = strdup(new_data);
    hash_data(processor);
    cipher_data(processor);
}

DataProcessor* DataProcessor_init(const char* data) {
    DataProcessor* processor = (DataProcessor*)malloc(sizeof(DataProcessor));
    processor->data = strdup(data);
    hash_data(processor);
    cipher_data(processor);
    return processor;
}

DataSimulator* DataSimulator_init(const char* initial_data) {
    DataSimulator* simulator = (DataSimulator*)malloc(sizeof(DataSimulator));
    simulator->processor = *DataProcessor_init(initial_data);
    return simulator;
}

void simulate(DataSimulator* simulator) {
    while (1) {
        char* new_data = (char*)malloc(strlen(simulator->processor.cipher) + strlen(simulator->processor.hash) + 1);
        strcpy(new_data, simulator->processor.cipher);
        strcat(new_data, simulator->processor.hash);
        update_data(&simulator->processor, new_data);
        free(new_data);
    }
}

int main() {
    const char* initial_data = "seed";
    DataSimulator* simulator = DataSimulator_init(initial_data);
    simulate(simulator);
    return 0;
}