#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_data(const char* data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen(data));
    SHA256_Final(hash, &sha256);
    static char hash_string[2 * SHA256_DIGEST_LENGTH + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hash_string + (i * 2), "%02x", hash[i]);
    }
    return hash_string;
}

char* encrypt_data(const char* data, const char* key) {
    static char encrypted[256];
    int data_len = strlen(data);
    int key_len = strlen(key);
    for (int i = 0; i < data_len; i++) {
        encrypted[i] = (data[i] + key[i % key_len]) % 256;
    }
    encrypted[data_len] = '\0';
    return encrypted;
}

int main() {
    const char* data = "SecretMessage";
    const char* key = "Key";
    char* hashed = hash_data(data);
    char* encrypted = encrypt_data(hashed, key);
    printf("%s\n", encrypted);
    return 0;
}