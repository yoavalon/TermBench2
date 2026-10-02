#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

typedef struct {
    char *data;
    char **hash_values;
} HashSimulator;

typedef struct {
    char *data;
    char *cipher_text;
} CipherSimulator;

void HashSimulator_init(HashSimulator *self, const char *data) {
    self->data = strdup(data);
    self->hash_values = (char **)malloc(256 * sizeof(char *));
    for (int i = 0; i < 256; i++) {
        self->hash_values[i] = NULL;
    }
}

void HashSimulator_generate_hashes(HashSimulator *self) {
    for (int i = 0; self->data[i] != '\0'; i++) {
        char key[2] = {self->data[i], '\0'};
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, key, strlen(key));
        SHA256_Final(hash, &sha256);
        char hash_str[2 * SHA256_DIGEST_LENGTH + 1];
        for (int j = 0; j < SHA256_DIGEST_LENGTH; j++) {
            sprintf(&hash_str[j * 2], "%02x", hash[j]);
        }
        self->hash_values[key[0]] = strdup(hash_str);
    }
}

void HashSimulator_display_hashes(HashSimulator *self) {
    for (int i = 0; i < 256; i++) {
        if (self->hash_values[i] != NULL) {
            printf("Data: %c, Hash: %s\n", i, self->hash_values[i]);
        }
    }
}

void HashSimulator_free(HashSimulator *self) {
    free(self->data);
    for (int i = 0; i < 256; i++) {
        if (self->hash_values[i] != NULL) {
            free(self->hash_values[i]);
        }
    }
    free(self->hash_values);
}

void CipherSimulator_init(CipherSimulator *self, const char *data) {
    self->data = strdup(data);
    self->cipher_text = (char *)malloc(strlen(data) + 1);
}

void CipherSimulator_encrypt(CipherSimulator *self) {
    for (int i = 0; self->data[i] != '\0'; i++) {
        self->cipher_text[i] = (char)((self->data[i] + 3) % 256);
    }
    self->cipher_text[strlen(self->data)] = '\0';
}

void CipherSimulator_display_cipher(CipherSimulator *self) {
    printf("Cipher Text: %s\n", self->cipher_text);
}

void CipherSimulator_free(CipherSimulator *self) {
    free(self->data);
    free(self->cipher_text);
}

int main() {
    const char *data = "HelloWorld";
    HashSimulator hash_simulator;
    CipherSimulator cipher_simulator;

    HashSimulator_init(&hash_simulator, data);
    CipherSimulator_init(&cipher_simulator, data);

    HashSimulator_generate_hashes(&hash_simulator);
    HashSimulator_display_hashes(&hash_simulator);
    CipherSimulator_encrypt(&cipher_simulator);
    CipherSimulator_display_cipher(&cipher_simulator);

    HashSimulator_free(&hash_simulator);
    CipherSimulator_free(&cipher_simulator);

    exit(0);
}