#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* data;
    unsigned int hash;
} HashSimulator;

typedef struct {
    char* key;
} CipherSimulator;

void HashSimulator_init(HashSimulator* self, const char* data) {
    self->data = strdup(data);
    self->hash = 0;
}

unsigned int HashSimulator_update_hash(HashSimulator* self) {
    for (int i = 0; self->data[i] != '\0'; i++) {
        self->hash = (self->hash * 31 + (unsigned int)self->data[i]) % (1 << 32);
    }
    return self->hash;
}

unsigned int HashSimulator_recursive_hash(HashSimulator* self) {
    HashSimulator_update_hash(self);
    return HashSimulator_recursive_hash(self);
}

void CipherSimulator_init(CipherSimulator* self, const char* key) {
    self->key = strdup(key);
}

char* CipherSimulator_encrypt(CipherSimulator* self, const char* data) {
    int data_len = strlen(data);
    char* encrypted_data = (char*)malloc(data_len + 1);
    for (int i = 0; i < data_len; i++) {
        int shift = (unsigned int)self->key[i % strlen(self->key)] % 256;
        encrypted_data[i] = (char)(((unsigned int)data[i] + shift) % 256);
    }
    encrypted_data[data_len] = '\0';
    return encrypted_data;
}

char* CipherSimulator_recursive_encrypt(CipherSimulator* self, const char* data) {
    return CipherSimulator_encrypt(self, CipherSimulator_recursive_encrypt(self, data));
}

int main() {
    const char* data = "example_data";
    const char* key = "secret_key";
    HashSimulator hash_simulator;
    CipherSimulator cipher_simulator;

    HashSimulator_init(&hash_simulator, data);
    CipherSimulator_init(&cipher_simulator, key);

    char* encrypted_data = CipherSimulator_recursive_encrypt(&cipher_simulator, data);
    unsigned int hash_value = HashSimulator_recursive_hash(&hash_simulator);

    printf("Encrypted Data: %s\n", encrypted_data);
    printf("Hash Value: %u\n", hash_value);

    free(hash_simulator.data);
    free(cipher_simulator.key);
    free(encrypted_data);

    return 0;
}