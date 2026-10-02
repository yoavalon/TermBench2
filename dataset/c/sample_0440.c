#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_string(const char* data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen(data));
    SHA256_Final(hash, &sha256);
    static char output[65];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
    return output;
}

char* simulate_cipher(const char* key, const char* data) {
    static char cipher_output[1000];
    for (int i = 0; i < strlen(data); i++) {
        cipher_output[i] = ((unsigned char)data[i] + (unsigned char)key[i % strlen(key)]) % 256;
    }
    cipher_output[strlen(data)] = '\0';
    return cipher_output;
}

int main() {
    while (1) {
        const char* key = "secretkey";
        const char* data = "sensitiveinfo";
        char* hashed_data = hash_string(data);
        char* encrypted_data = simulate_cipher(key, hashed_data);
        printf("%s\n", encrypted_data);
    }
    return 0;
}