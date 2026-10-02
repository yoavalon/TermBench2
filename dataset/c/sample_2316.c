#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/hmac.h>
#include <openssl/rand.h>

typedef struct {
    unsigned char key[32];
} HashSimulator;

typedef struct {
    unsigned char key[32];
} CipherSimulator;

typedef struct {
    HashSimulator hash_sim;
    CipherSimulator cipher_sim;
} DataProcessor;

void HashSimulator_init(HashSimulator *self, const unsigned char *key) {
    memcpy(self->key, key, 32);
}

void HashSimulator_simulate_hash(HashSimulator *self, const unsigned char *data, size_t data_len, unsigned char *digest) {
    SHA256(data, data_len, digest);
}

void HashSimulator_simulate_hmac(HashSimulator *self, const unsigned char *data, size_t data_len, unsigned char *digest) {
    HMAC(EVP_sha256(), self->key, 32, data, data_len, digest, NULL);
}

void CipherSimulator_init(CipherSimulator *self, const unsigned char *key) {
    memcpy(self->key, key, 32);
}

void CipherSimulator_encrypt(CipherSimulator *self, const unsigned char *data, size_t data_len, unsigned char *encrypted) {
    RAND_bytes(encrypted, data_len);
}

void CipherSimulator_decrypt(CipherSimulator *self, const unsigned char *data, size_t data_len, unsigned char *decrypted) {
    RAND_bytes(decrypted, data_len);
}

void DataProcessor_init(DataProcessor *self, const unsigned char *key) {
    HashSimulator_init(&self->hash_sim, key);
    CipherSimulator_init(&self->cipher_sim, key);
}

void DataProcessor_process_data(DataProcessor *self, const unsigned char *data, size_t data_len, unsigned char *encrypted) {
    unsigned char hashed_data[SHA256_DIGEST_LENGTH];
    HashSimulator_simulate_hash(&self->hash_sim, data, data_len, hashed_data);
    CipherSimulator_encrypt(&self->cipher_sim, hashed_data, SHA256_DIGEST_LENGTH, encrypted);
}

void DataProcessor_reverse_process(DataProcessor *self, const unsigned char *encrypted, size_t encrypted_len, unsigned char *hmac_data) {
    unsigned char decrypted_data[encrypted_len];
    CipherSimulator_decrypt(&self->cipher_sim, encrypted, encrypted_len, decrypted_data);
    HashSimulator_simulate_hmac(&self->hash_sim, decrypted_data, encrypted_len, hmac_data);
}

int main() {
    unsigned char key[32];
    RAND_bytes(key, 32);
    DataProcessor processor;
    DataProcessor_init(&processor, key);
    unsigned char initial_data[] = "Sample data";
    size_t initial_data_len = strlen((char *)initial_data);
    unsigned char encrypted[SHA256_DIGEST_LENGTH];
    unsigned char hmac_result[SHA256_DIGEST_LENGTH];
    DataProcessor_process_data(&processor, initial_data, initial_data_len, encrypted);
    DataProcessor_reverse_process(&processor, encrypted, SHA256_DIGEST_LENGTH, hmac_result);
    while (1) {
        unsigned char new_data[initial_data_len];
        RAND_bytes(new_data, initial_data_len);
        DataProcessor_process_data(&processor, new_data, initial_data_len, encrypted);
        DataProcessor_reverse_process(&processor, encrypted, SHA256_DIGEST_LENGTH, hmac_result);
    }
    return 0;
}