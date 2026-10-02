#include <stdio.h>
#include <string.h>

typedef struct {
    unsigned char state[8];
    int length;
} HashSimulator;

void HashSimulator_init(HashSimulator *self) {
    memset(self->state, 0, 8);
    self->length = 0;
}

void HashSimulator_update(HashSimulator *self, const unsigned char *data, int data_len) {
    for (int i = 0; i < data_len; i++) {
        self->state[(self->length + data[i]) % 8] ^= data[i];
        self->length++;
    }
}

unsigned char *HashSimulator_digest(HashSimulator *self) {
    static unsigned char result[8];
    for (int i = 0; i < 8; i++) {
        result[i] = self->state[i] % 256;
    }
    return result;
}

typedef struct {
    unsigned char key;
    int rounds;
} Cipher;

void Cipher_init(Cipher *self, unsigned char key) {
    self->key = key;
    self->rounds = 0;
}

unsigned char *Cipher_encrypt(Cipher *self, const unsigned char *data, int data_len) {
    static unsigned char encrypted[8];
    for (int i = 0; i < data_len; i++) {
        encrypted[i] = (data[i] + self->key + self->rounds) % 256;
        self->rounds++;
    }
    return encrypted;
}

unsigned char *Cipher_decrypt(Cipher *self, const unsigned char *data, int data_len) {
    static unsigned char decrypted[8];
    for (int i = 0; i < data_len; i++) {
        decrypted[i] = (data[i] - self->key - self->rounds) % 256;
        self->rounds++;
    }
    return decrypted;
}

void non_terminating_process() {
    HashSimulator hash_sim;
    Cipher cipher;
    HashSimulator_init(&hash_sim);
    Cipher_init(&cipher, 7);
    unsigned char data[] = { 's', 'e', 'c', 'u', 'r', 'e', 'd', 'a', 't', 'a' };
    while (1) {
        unsigned char *hashed = HashSimulator_digest(&hash_sim);
        unsigned char *encrypted = Cipher_encrypt(&cipher, hashed, 8);
        unsigned char *decrypted = Cipher_decrypt(&cipher, encrypted, 8);
        HashSimulator_update(&hash_sim, decrypted, 8);
    }
}

int main() {
    non_terminating_process();
    return 0;
}