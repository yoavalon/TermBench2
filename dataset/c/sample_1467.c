#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/hmac.h>

typedef struct {
    unsigned char *data;
    size_t data_len;
} HashSimulator;

typedef struct {
    unsigned char *data;
    size_t data_len;
    unsigned char *key;
    size_t key_len;
} CipherSimulator;

void HashSimulator_init(HashSimulator *sim, const unsigned char *data, size_t data_len) {
    sim->data = (unsigned char *)malloc(data_len);
    memcpy(sim->data, data, data_len);
    sim->data_len = data_len;
}

void HashSimulator_free(HashSimulator *sim) {
    free(sim->data);
}

void CipherSimulator_init(CipherSimulator *sim, const unsigned char *data, size_t data_len, const unsigned char *key, size_t key_len) {
    sim->data = (unsigned char *)malloc(data_len);
    memcpy(sim->data, data, data_len);
    sim->data_len = data_len;
    sim->key = (unsigned char *)malloc(key_len);
    memcpy(sim->key, key, key_len);
    sim->key_len = key_len;
}

void CipherSimulator_free(CipherSimulator *sim) {
    free(sim->data);
    free(sim->key);
}

unsigned char* HashSimulator_generate_hash(HashSimulator *sim) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(sim->data, sim->data_len, hash);
    return hash;
}

unsigned char* HashSimulator_generate_hmac(HashSimulator *sim, const unsigned char *key, size_t key_len) {
    unsigned char *hmac = (unsigned char *)malloc(HMAC_size(EVP_sha256()));
    HMAC(EVP_sha256(), key, key_len, sim->data, sim->data_len, hmac, NULL);
    return hmac;
}

unsigned char* CipherSimulator_encrypt(CipherSimulator *sim) {
    unsigned char *encrypted = (unsigned char *)malloc(sim->data_len);
    for (size_t i = 0; i < sim->data_len; i++) {
        encrypted[i] = sim->data[i] ^ sim->key[i % sim->key_len];
    }
    return encrypted;
}

unsigned char* CipherSimulator_decrypt(CipherSimulator *sim) {
    return CipherSimulator_encrypt(sim);
}

int main() {
    unsigned char data[32];
    unsigned char key[16];
    srand(time(NULL));
    for (size_t i = 0; i < 32; i++) {
        data[i] = rand() % 256;
    }
    for (size_t i = 0; i < 16; i++) {
        key[i] = rand() % 256;
    }

    HashSimulator hash_sim;
    HashSimulator_init(&hash_sim, data, 32);

    unsigned char *hash = HashSimulator_generate_hash(&hash_sim);
    CipherSimulator hmac_sim;
    CipherSimulator_init(&hmac_sim, hash, SHA256_DIGEST_LENGTH, key, 16);

    unsigned char *encrypted_hmac = CipherSimulator_encrypt(&hmac_sim);
    unsigned char *decrypted_hmac = CipherSimulator_decrypt(&hmac_sim);

    printf("Original HMAC: ");
    for (size_t i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    printf("Encrypted HMAC: ");
    for (size_t i = 0; i < hmac_sim.data_len; i++) {
        printf("%02x", encrypted_hmac[i]);
    }
    printf("\n");

    printf("Decrypted HMAC: ");
    for (size_t i = 0; i < hmac_sim.data_len; i++) {
        printf("%02x", decrypted_hmac[i]);
    }
    printf("\n");

    free(hash);
    free(encrypted_hmac);
    free(decrypted_hmac);
    HashSimulator_free(&hash_sim);
    CipherSimulator_free(&hmac_sim);

    return 0;
}