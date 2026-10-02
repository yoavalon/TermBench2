#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_data(const unsigned char* data, size_t data_len) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, data_len);
    SHA256_Final(hash, &sha256);

    static char output[65];
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
    return output;
}

char* cipher_simulate(const char* text) {
    static char encrypted[513];
    for(int i = 0; text[i]; i++) {
        encrypted[i] = (text[i] + 3) % 256;
    }
    encrypted[strlen(text)] = '\0';
    return encrypted;
}

void main() {
    unsigned char data[] = "Hello, World!";
    size_t data_len = strlen((char*)data);
    char* hashed = hash_data(data, data_len);
    char* encrypted = cipher_simulate(hashed);
    printf("%s\n", encrypted);
}