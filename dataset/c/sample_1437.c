#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/hmac.h>
#include <openssl/rand.h>

typedef struct {
    unsigned char *data;
    size_t length;
} HashSimulator;

typedef struct {
    unsigned char *data;
    size_t length;
} CipherSimulator;

void HashSimulator_init(HashSimulator *self, unsigned char *data, size_t length) {
    self->data = data;
    self->length = length;
}

void CipherSimulator_init(CipherSimulator *self, unsigned char *data, size_t length) {
    self->data = data;
    self->length = length;
}

void compute_hash(HashSimulator *self, unsigned char *result, const char *algorithm) {
    if (strcmp(algorithm, "sha256") == 0) {
        SHA256(self->data, self->length, result);
    }
}

void compute_hmac(HashSimulator *self, unsigned char *result, const unsigned char *key, size_t key_length, const char *algorithm) {
    if (strcmp(algorithm, "sha256") == 0) {
        HMAC(EVP_sha256(), key, key_length, self->data, self->length, result, NULL);
    }
}

void xor_cipher(CipherSimulator *self, unsigned char *result, unsigned char key) {
    for (size_t i = 0; i < self->length; i++) {
        result[i] = self->data[i] ^ key;
    }
}

void caesar_cipher(CipherSimulator *self, unsigned char *result, int shift) {
    for (size_t i = 0; i < self->length; i++) {
        if (65 <= self->data[i] && self->data[i] <= 90) {
            result[i] = ((self->data[i] - 65 + shift) % 26) + 65;
        } else {
            result[i] = self->data[i];
        }
    }
}

void data_mutations() {
    unsigned char data[32];
    if (!RAND_bytes(data, sizeof(data))) {
        fprintf(stderr, "Failed to generate random data\n");
        return;
    }

    HashSimulator hash_simulator;
    CipherSimulator cipher_simulator;
    HashSimulator_init(&hash_simulator, data, sizeof(data));
    CipherSimulator_init(&cipher_simulator, data, sizeof(data));

    unsigned char hash_result[SHA256_DIGEST_LENGTH];
    unsigned char hmac_result[HMAC_SIZE];
    unsigned char xor_result[sizeof(data)];
    unsigned char caesar_result[sizeof(data)];

    compute_hash(&hash_simulator, hash_result, "sha256");
    compute_hmac(&hash_simulator, hmac_result, (const unsigned char *)"secret_key", strlen("secret_key"), "sha256");
    xor_cipher(&cipher_simulator, xor_result, 170);
    caesar_cipher(&cipher_simulator, caesar_result, 3);

    printf("Hash: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash_result[i]);
    }
    printf("\n");

    printf("HMAC: ");
    for (int i = 0; i < HMAC_SIZE; i++) {
        printf("%02x", hmac_result[i]);
    }
    printf("\n");

    printf("XOR Cipher: ");
    for (int i = 0; i < sizeof(data); i++) {
        printf("%02x", xor_result[i]);
    }
    printf("\n");

    printf("Caesar Cipher: ");
    for (int i = 0; i < sizeof(data); i++) {
        printf("%02x", caesar_result[i]);
    }
    printf("\n");
}

int main() {
    data_mutations();
    return 0;
}