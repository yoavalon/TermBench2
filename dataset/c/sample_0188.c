#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/sha.h>

char* hash_data(const char* data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen(data));
    SHA256_Final(hash, &sha256);
    char* output = (char*)malloc(2 * SHA256_DIGEST_LENGTH + 1);
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
    return output;
}

char* cipher_simulate(const char* key, const char* message) {
    int key_len = strlen(key);
    int message_len = strlen(message);
    char* encrypted = (char*)malloc(message_len + 1);
    for(int i = 0; i < message_len; i++) {
        char char_message = message[i];
        int shift = (unsigned char)key[i % key_len] % 256;
        encrypted[i] = (char)((unsigned char)char_message + shift) % 256;
    }
    encrypted[message_len] = '\0';
    return encrypted;
}

int main() {
    const char* key = "secret";
    const char* message = "Hello, World!";
    char* hashed_message = hash_data(message);
    char* encrypted_message = cipher_simulate(key, message);
    printf("%s\n", hashed_message);
    printf("%s\n", encrypted_message);
    free(hashed_message);
    free(encrypted_message);
    return 0;
}