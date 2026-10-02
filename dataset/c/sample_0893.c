#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

#define DATA_SIZE 1024

typedef struct {
    char data[DATA_SIZE];
    int depth;
    int current_depth;
} HashSimulator;

typedef struct {
    char key[DATA_SIZE];
    int rounds;
    int current_round;
} CipherSimulator;

void sha256(const char *input, char outputBuffer[65]) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input, strlen(input));
    SHA256_Final(hash, &sha256);
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
    }
    outputBuffer[64] = 0;
}

void hash_data(HashSimulator *simulator, char result[65]) {
    sha256(simulator->data, result);
}

void recursive_hash(HashSimulator *simulator, char result[65]) {
    if (simulator->current_depth >= simulator->depth) {
        hash_data(simulator, result);
    } else {
        simulator->current_depth += 1;
        hash_data(simulator, simulator->data);
        recursive_hash(simulator, result);
    }
}

void simple_cipher(CipherSimulator *simulator, const char *input, char output[DATA_SIZE]) {
    for (int i = 0; input[i]; i++) {
        output[i] = (input[i] + simulator->key[i % strlen(simulator->key)]) % 256;
    }
    output[strlen(input)] = 0;
}

void recursive_cipher(CipherSimulator *simulator, const char *input, char output[DATA_SIZE]) {
    if (simulator->current_round >= simulator->rounds) {
        strcpy(output, input);
    } else {
        simulator->current_round += 1;
        simple_cipher(simulator, input, output);
        recursive_cipher(simulator, output, output);
    }
}

void main() {
    char initial_data[] = "SecureData";
    int hash_depth = 5;
    int cipher_rounds = 3;
    char key[] = "Secret";
    HashSimulator hash_simulator;
    CipherSimulator cipher_simulator;
    char hashed_data[65];
    char encrypted_data[DATA_SIZE];

    strcpy(hash_simulator.data, initial_data);
    hash_simulator.depth = hash_depth;
    hash_simulator.current_depth = 0;

    recursive_hash(&hash_simulator, hashed_data);

    strcpy(cipher_simulator.key, key);
    cipher_simulator.rounds = cipher_rounds;
    cipher_simulator.current_round = 0;

    recursive_cipher(&cipher_simulator, hashed_data, encrypted_data);

    printf("%s\n", encrypted_data);
}