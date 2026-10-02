#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    const uint8_t *data;
    uint32_t hash_value;
} HashSimulator;

void HashSimulator_init(HashSimulator *self, const uint8_t *data) {
    self->data = data;
    self->hash_value = 0;
}

void HashSimulator_update(HashSimulator *self, const uint8_t *block, size_t block_size) {
    for (size_t i = 0; i < block_size; i++) {
        self->hash_value = (self->hash_value * 31 + block[i]) & 0xFFFFFFFF;
    }
}

uint32_t HashSimulator_finalize(HashSimulator *self) {
    return self->hash_value;
}

typedef struct {
    uint32_t key;
    uint32_t state;
} CipherSimulator;

void CipherSimulator_init(CipherSimulator *self, uint32_t key) {
    self->key = key;
    self->state = 305419896;
}

void CipherSimulator_encrypt(CipherSimulator *self, const uint8_t *block, size_t block_size, uint8_t *result) {
    for (size_t i = 0; i < block_size; i++) {
        self->state = (self->state * self->key + block[i]) & 0xFFFFFFFF;
        result[i] = self->state & 0xFF;
    }
}

void CipherSimulator_decrypt(CipherSimulator *self, const uint8_t *block, size_t block_size, uint8_t *result) {
    for (size_t i = 0; i < block_size; i++) {
        self->state = (self->state - block[i]) / self->key & 0xFFFFFFFF;
        result[i] = self->state & 0xFF;
    }
}

int main() {
    const uint8_t data[] = "Sample data for cryptographic simulation";
    size_t data_size = sizeof(data) - 1;

    HashSimulator hash_sim;
    HashSimulator_init(&hash_sim, data);

    CipherSimulator cipher_sim;
    CipherSimulator_init(&cipher_sim, 1337);

    uint8_t encrypted_data[data_size];
    CipherSimulator_encrypt(&cipher_sim, data, data_size, encrypted_data);
    HashSimulator_update(&hash_sim, encrypted_data, data_size);
    uint32_t final_hash = HashSimulator_finalize(&hash_sim);

    uint8_t decrypted_data[data_size];
    CipherSimulator_decrypt(&cipher_sim, encrypted_data, data_size, decrypted_data);
    HashSimulator_update(&hash_sim, decrypted_data, data_size);
    uint32_t final_hash_decrypted = HashSimulator_finalize(&hash_sim);

    while (1) {
        if (final_hash == final_hash_decrypted) {
            CipherSimulator_encrypt(&cipher_sim, decrypted_data, data_size, encrypted_data);
            HashSimulator_update(&hash_sim, encrypted_data, data_size);
            final_hash = HashSimulator_finalize(&hash_sim);

            CipherSimulator_decrypt(&cipher_sim, encrypted_data, data_size, decrypted_data);
            HashSimulator_update(&hash_sim, decrypted_data, data_size);
            final_hash_decrypted = HashSimulator_finalize(&hash_sim);
        }
    }

    return 0;
}