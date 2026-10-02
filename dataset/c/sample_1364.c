#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_data(const char* data) {
    static char hash[65];
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen(data));
    SHA256_Final(digest, &sha256);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hash[i*2], "%02x", (unsigned int)digest[i]);
    }
    return hash;
}

char* simulate_cipher(const char* data) {
    static char encrypted[1024];
    const char* key = "secret_key";
    int key_len = strlen(key);
    for (int i = 0; i < strlen(data); i++) {
        char char_data = data[i];
        char char_key = key[i % key_len];
        encrypted[i] = (char)((unsigned char)char_data + (unsigned char)char_key) % 256;
    }
    encrypted[strlen(data)] = '\0';
    return encrypted;
}

void main() {
    const char* data = "Hello, World!";
    char* hashed = hash_data(data);
    char* ciphered = simulate_cipher(hashed);
    printf("%s\n", ciphered);
}