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
    char* hash_str = (char*)malloc(SHA256_DIGEST_LENGTH * 2 + 1);
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hash_str[i*2], "%02x", hash[i]);
    }
    return hash_str;
}

char* encrypt_message(const char* message) {
    const char* key = "secret_key";
    int key_len = strlen(key);
    int msg_len = strlen(message);
    char* encrypted = (char*)malloc(msg_len + 1);
    for(int i = 0; i < msg_len; i++) {
        char char_msg = message[i];
        char char_key = key[i % key_len];
        encrypted[i] = (char_msg + char_key) % 256;
    }
    encrypted[msg_len] = '\0';
    return encrypted;
}

int main() {
    const char* message = "Hello, World!";
    char* hashed = hash_data(message);
    char* encrypted = encrypt_message(hashed);
    printf("%s\n", encrypted);
    free(hashed);
    free(encrypted);
    return 0;
}