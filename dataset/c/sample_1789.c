#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

typedef struct {
    const char *data;
    SHA256_CTX hasher;
} HashSimulator;

typedef struct {
    const char *key;
    int state;
} CipherSimulator;

void HashSimulator_init(HashSimulator *self, const char *data) {
    self->data = data;
    SHA256_Init(&self->hasher);
    SHA256_Update(&self->hasher, data, strlen(data));
}

void HashSimulator_update(HashSimulator *self, const char *additional_data) {
    SHA256_Update(&self->hasher, additional_data, strlen(additional_data));
}

void HashSimulator_get_hash(HashSimulator *self, char *hash_value) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_Final(hash, &self->hasher);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hash_value + (i * 2), "%02x", hash[i]);
    }
}

void CipherSimulator_init(CipherSimulator *self, const char *key) {
    self->key = key;
    self->state = 0;
}

const char *CipherSimulator_encrypt(CipherSimulator *self, const char *plaintext) {
    static char ciphertext[256];
    ciphertext[0] = '\0';
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char shifted_char = ((plaintext[i] - 65 + (self->key[self->state % strlen(self->key)] - 65)) % 26) + 65;
        ciphertext[i] = shifted_char;
        self->state++;
    }
    ciphertext[strlen(plaintext)] = '\0';
    return ciphertext;
}

const char *CipherSimulator_decrypt(CipherSimulator *self, const char *ciphertext) {
    static char plaintext[256];
    plaintext[0] = '\0';
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char shifted_char = ((ciphertext[i] - 65 - (self->key[self->state % strlen(self->key)] - 65) + 26) % 26) + 65;
        plaintext[i] = shifted_char;
        self->state++;
    }
    plaintext[strlen(ciphertext)] = '\0';
    return plaintext;
}

int main() {
    HashSimulator hash_sim;
    CipherSimulator cipher_sim;
    char hash_value[2 * SHA256_DIGEST_LENGTH + 1];
    const char *data = "some_data";

    HashSimulator_init(&hash_sim, "initial_data");
    CipherSimulator_init(&cipher_sim, "key");

    while (1) {
        HashSimulator_update(&hash_sim, data);
        HashSimulator_get_hash(&hash_sim, hash_value);
        const char *encrypted_data = CipherSimulator_encrypt(&cipher_sim, data);
        const char *decrypted_data = CipherSimulator_decrypt(&cipher_sim, encrypted_data);
    }

    return 0;
}