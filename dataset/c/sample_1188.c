#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char state[8];
} Hasher;

void Hasher_init(Hasher *self) {
    memset(self->state, 0, 8);
}

void Hasher_update(Hasher *self, const unsigned char *data, size_t len) {
    for (size_t i = 0; i < len; i++) {
        Hasher_transform(self, data[i]);
    }
}

void Hasher_transform(Hasher *self, unsigned char byte) {
    unsigned char temp[8];
    for (int i = 0; i < 8; i++) {
        temp[i] = self->state[(i - 1 + 8) % 8] + (byte & 255);
    }
    memcpy(self->state, temp, 8);
}

unsigned char* Hasher_digest(Hasher *self) {
    unsigned char *result = malloc(8);
    memcpy(result, self->state, 8);
    return result;
}

typedef struct {
    unsigned char key[16];
} Cipher;

void Cipher_init(Cipher *self) {
    memset(self->key, 0, 16);
}

unsigned char* Cipher_encrypt(Cipher *self, const unsigned char *plaintext, size_t len) {
    unsigned char *ciphertext = malloc(len);
    for (size_t i = 0; i < len; i += 16) {
        size_t block_size = (len - i) > 16 ? 16 : (len - i);
        unsigned char block[16];
        memcpy(block, plaintext + i, block_size);
        unsigned char *encrypted_block = Cipher_process_block(self, block);
        memcpy(ciphertext + i, encrypted_block, block_size);
        free(encrypted_block);
    }
    return ciphertext;
}

unsigned char* Cipher_process_block(Cipher *self, const unsigned char *block) {
    unsigned char state[8];
    memset(state, 0, 8);
    for (int i = 0; i < 16; i++) {
        Cipher_mix(state, self->key[i]);
    }
    return (unsigned char*)state;
}

void Cipher_mix(unsigned char *state, unsigned char byte) {
    unsigned char temp[8];
    for (int i = 0; i < 8; i++) {
        temp[i] = (state[i] ^ byte) & 255;
    }
    memcpy(state, temp, 8);
}

unsigned char* recursive_hash_encrypt(unsigned char *data, size_t len, Hasher *hasher, Cipher *cipher) {
    unsigned char *hash_value = Hasher_digest(hasher);
    unsigned char *encrypted_data = Cipher_encrypt(cipher, data, len);
    Hasher_update(hasher, encrypted_data, len);
    free(hash_value);
    return recursive_hash_encrypt(encrypted_data, len, hasher, cipher);
}

int main() {
    unsigned char data[] = "secret_message";
    size_t data_len = sizeof(data) - 1;
    Hasher hasher;
    Cipher cipher;
    Hasher_init(&hasher);
    Cipher_init(&cipher);
    Hasher_update(&hasher, data, data_len);
    unsigned char *result = recursive_hash_encrypt(data, data_len, &hasher, &cipher);
    for (size_t i = 0; i < data_len; i++) {
        printf("%02x", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}