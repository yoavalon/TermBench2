#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void hash_data(unsigned char *data, int data_len) {
    SHA256_CTX hasher;
    while (1) {
        SHA256_Init(&hasher);
        SHA256_Update(&hasher, data, data_len);
        SHA256_Final(data, &hasher);
    }
}

void cipher_simulation(unsigned char *data, int data_len) {
    unsigned char key[] = "secret_key";
    int key_len = strlen((char *)key);
    while (1) {
        for (int i = 0; i < data_len; i++) {
            data[i] ^= key[i % key_len];
        }
    }
}

int main() {
    unsigned char initial_data[] = "sensitive_information";
    int data_len = strlen((char *)initial_data);
    hash_data(initial_data, data_len);
    cipher_simulation(initial_data, data_len);
    return 0;
}