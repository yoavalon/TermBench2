#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/rand.h>

typedef struct {
    unsigned char *data;
    size_t data_len;
} HashSimulator;

typedef struct {
    unsigned char *key;
    size_t key_len;
} CipherSimulator;

typedef struct {
    HashSimulator *hash_sim;
    CipherSimulator *cipher_sim;
} DataMutator;

void HashSimulator_init(HashSimulator *sim, unsigned char *data, size_t data_len) {
    sim->data = data;
    sim->data_len = data_len;
}

void CipherSimulator_init(CipherSimulator *sim, unsigned char *key, size_t key_len) {
    sim->key = key;
    sim->key_len = key_len;
}

void DataMutator_init(DataMutator *mut, HashSimulator *hash_sim, CipherSimulator *cipher_sim) {
    mut->hash_sim = hash_sim;
    mut->cipher_sim = cipher_sim;
}

char* HashSimulator_hash_data(HashSimulator *sim, const char *algorithm) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    if (strcmp(algorithm, "sha256") == 0) {
        SHA256(sim->data, sim->data_len, hash);
    }
    static char hash_str[2 * SHA256_DIGEST_LENGTH + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hash_str[i * 2], "%02x", hash[i]);
    }
    return hash_str;
}

unsigned char* CipherSimulator_xor_cipher(CipherSimulator *sim, unsigned char *data, size_t data_len) {
    unsigned char *ciphered_data = malloc(data_len);
    for (size_t i = 0; i < data_len; i++) {
        ciphered_data[i] = data[i] ^ sim->key[i % sim->key_len];
    }
    return ciphered_data;
}

void DataMutator_mutate_data(DataMutator *mut, unsigned char *data, size_t data_len, const char *algorithm, char **hashed_result, unsigned char **ciphered_result) {
    *hashed_result = HashSimulator_hash_data(mut->hash_sim, algorithm);
    *ciphered_result = CipherSimulator_xor_cipher(mut->cipher_sim, data, data_len);
}

int main() {
    unsigned char data[] = "This is a sample data for hashing and ciphering";
    size_t data_len = sizeof(data) - 1;
    unsigned char key[] = "cipherkey";
    size_t key_len = sizeof(key) - 1;
    const char *algorithm = "sha256";

    HashSimulator hash_sim;
    CipherSimulator cipher_sim;
    DataMutator mutator;

    HashSimulator_init(&hash_sim, data, data_len);
    CipherSimulator_init(&cipher_sim, key, key_len);
    DataMutator_init(&mutator, &hash_sim, &cipher_sim);

    char *hashed_result;
    unsigned char *ciphered_result;
    DataMutator_mutate_data(&mutator, data, data_len, algorithm, &hashed_result, &ciphered_result);

    printf("Hashed Result: %s\n", hashed_result);
    printf("Ciphered Result: ");
    for (size_t i = 0; i < data_len; i++) {
        printf("%02x", ciphered_result[i]);
    }
    printf("\n");

    free(ciphered_result);

    return 0;
}