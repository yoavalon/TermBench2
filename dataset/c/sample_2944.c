#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/hmac.h>

typedef struct {
    char key[33];
} HashSimulator;

void HashSimulator_init(HashSimulator *self, const char *key) {
    strncpy(self->key, key, 32);
    self->key[32] = '\0';
}

char* HashSimulator_generate_hash(HashSimulator *self, const char *data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen(data));
    SHA256_Final(hash, &sha256);
    static char output[2 * SHA256_DIGEST_LENGTH + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
    return output;
}

char* HashSimulator_create_hmac(HashSimulator *self, const char *data) {
    unsigned char hmac[SHA256_DIGEST_LENGTH];
    HMAC_CTX *hmac_ctx = HMAC_CTX_new();
    HMAC_Init_ex(hmac_ctx, self->key, 32, EVP_sha256(), NULL);
    HMAC_Update(hmac_ctx, (unsigned char*)data, strlen(data));
    HMAC_Final_ex(hmac_ctx, hmac, NULL);
    HMAC_CTX_free(hmac_ctx);
    static char output[2 * SHA256_DIGEST_LENGTH + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output + (i * 2), "%02x", hmac[i]);
    }
    return output;
}

typedef struct {
    char key[33];
} CipherSimulator;

void CipherSimulator_init(CipherSimulator *self, const char *key) {
    strncpy(self->key, key, 32);
    self->key[32] = '\0';
}

char* CipherSimulator_encrypt(CipherSimulator *self, const char *plaintext) {
    static char output[256];
    for (int i = 0; plaintext[i] != '\0'; i++) {
        output[i] = (plaintext[i] + self->key[i % 32]) % 256;
    }
    output[strlen(plaintext)] = '\0';
    return output;
}

char* CipherSimulator_decrypt(CipherSimulator *self, const char *ciphertext) {
    static char output[256];
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        output[i] = (ciphertext[i] - self->key[i % 32] + 256) % 256;
    }
    output[strlen(ciphertext)] = '\0';
    return output;
}

typedef struct {
    unsigned int seed;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, unsigned int seed) {
    self->seed = seed;
}

unsigned int* SequenceGenerator_generate_sequence(SequenceGenerator *self, int length) {
    static unsigned int sequence[10];
    unsigned int current = self->seed;
    for (int i = 0; i < length; i++) {
        sequence[i] = current;
        current = (current * 1664525 + 1013904223) % (1 << 32);
    }
    return sequence;
}

void main() {
    unsigned char key[17];
    if (RAND_bytes(key, 16) != 1) {
        fprintf(stderr, "Failed to generate random key\n");
        return;
    }
    key[16] = '\0';

    HashSimulator hash_sim;
    HashSimulator_init(&hash_sim, (const char*)key);

    CipherSimulator cipher_sim;
    CipherSimulator_init(&cipher_sim, (const char*)key);

    SequenceGenerator seq_gen;
    SequenceGenerator_init(&seq_gen, 12345);

    while (1) {
        const char *data = "test_data";
        char *hash_value = HashSimulator_generate_hash(&hash_sim, data);
        char *hmac_value = HashSimulator_create_hmac(&hash_sim, data);
        char *encrypted = CipherSimulator_encrypt(&cipher_sim, data);
        char *decrypted = CipherSimulator_decrypt(&cipher_sim, encrypted);
        unsigned int *sequence = SequenceGenerator_generate_sequence(&seq_gen, 10);
    }
}