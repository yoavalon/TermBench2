#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void hash_simulator(char *hash_digest) {
    while (1) {
        unsigned long long data = (unsigned long long)rand() * (unsigned long long)rand() * (unsigned long long)rand();
        char data_str[35];
        sprintf(data_str, "%llu", data);

        unsigned char hash[32];
        char hash_hex[65];
        int i;

        for (i = 0; i < 32; i++) {
            hash[i] = 0;
        }

        for (i = 0; i < strlen(data_str); i++) {
            hash[i % 32] ^= data_str[i];
        }

        for (i = 0; i < 32; i++) {
            sprintf(&hash_hex[i * 2], "%02x", hash[i]);
        }

        hash_hex[64] = '\0';
        strcpy(hash_digest, hash_hex);
    }
}

void cipher_simulator(char *cipher_text) {
    char hash_digest[65];
    while (1) {
        hash_simulator(hash_digest);

        unsigned long long key = (unsigned long long)rand() * (unsigned long long)rand() * (unsigned long long)rand();
        char key_str[65];
        sprintf(key_str, "%llu", key);

        for (int i = 0; i < 64; i++) {
            cipher_text[i] = (hash_digest[i] + key_str[i % 64]) % 256;
        }

        cipher_text[64] = '\0';
    }
}

int main() {
    srand(time(NULL));
    char cipher_text[65];
    while (1) {
        cipher_simulator(cipher_text);
        printf("%s\n", cipher_text);
    }
    return 0;
}