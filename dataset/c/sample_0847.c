#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    const uint8_t* data;
    size_t length;
    uint32_t hash_value;
} HashFunction;

void HashFunction_init(HashFunction* self, const uint8_t* data, size_t length) {
    self->data = data;
    self->length = length;
    self->hash_value = 0;
}

void HashFunction_update(HashFunction* self) {
    for (size_t i = 0; i < self->length; i++) {
        self->hash_value = self->hash_value * 33 ^ self->data[i];
    }
}

uint32_t HashFunction_digest(HashFunction* self) {
    return self->hash_value;
}

typedef struct {
    const uint8_t* key;
    size_t key_length;
    const uint8_t* data;
    size_t data_length;
    uint8_t* encrypted_data;
} CipherSimulator;

void CipherSimulator_init(CipherSimulator* self, const uint8_t* key, size_t key_length, const uint8_t* data, size_t data_length) {
    self->key = key;
    self->key_length = key_length;
    self->data = data;
    self->data_length = data_length;
    self->encrypted_data = (uint8_t*)malloc(data_length);
    memset(self->encrypted_data, 0, data_length);
}

void CipherSimulator_encrypt(CipherSimulator* self, size_t index) {
    if (index >= self->data_length) {
        return;
    }
    self->encrypted_data[index] = self->data[index] ^ self->key[index % self->key_length];
    CipherSimulator_encrypt(self, index + 1);
}

const uint8_t* CipherSimulator_get_encrypted_data(CipherSimulator* self) {
    return self->encrypted_data;
}

void free_CipherSimulator(CipherSimulator* self) {
    free(self->encrypted_data);
}

int main() {
    const uint8_t original_data[] = "Hello, world!";
    size_t original_data_length = sizeof(original_data) - 1;

    HashFunction hash_function;
    HashFunction_init(&hash_function, original_data, original_data_length);
    HashFunction_update(&hash_function);
    uint32_t hash_value = HashFunction_digest(&hash_function);

    const uint8_t key[] = "secret";
    size_t key_length = sizeof(key) - 1;

    CipherSimulator cipher_simulator;
    CipherSimulator_init(&cipher_simulator, key, key_length, original_data, original_data_length);
    CipherSimulator_encrypt(&cipher_simulator, 0);
    const uint8_t* encrypted_data = CipherSimulator_get_encrypted_data(&cipher_simulator);

    printf("Hash Value: %u\n", hash_value);
    printf("Encrypted Data: ");
    for (size_t i = 0; i < original_data_length; i++) {
        printf("%02X", encrypted_data[i]);
    }
    printf("\n");

    free_CipherSimulator(&cipher_simulator);

    return 0;
}