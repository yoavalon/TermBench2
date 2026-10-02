#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_data(const char* data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen(data));
    SHA256_Final(hash, &sha256);

    char* output = (char*)malloc(SHA256_DIGEST_LENGTH * 2 + 1);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
    return output;
}

char* cipher_simulate(const char* key, const char* data) {
    int data_len = strlen(data);
    int key_len = strlen(key);
    char* encrypted = (char*)malloc(data_len + 1);

    for (int i = 0; i < data_len; i++) {
        char char_data = data[i];
        char key_char = key[i % key_len];
        encrypted[i] = (char_data + key_char) % 256;
    }
    encrypted[data_len] = '\0';
    return encrypted;
}

void main() {
    const char* key = "secretkey";
    const char* data = "sensitiveinformation";
    char* hashed = hash_data(data);
    char* encrypted = cipher_simulate(key, hashed);

    printf("%s\n", encrypted);

    free(hashed);
    free(encrypted);
}