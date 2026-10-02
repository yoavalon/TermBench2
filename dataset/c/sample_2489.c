#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

char* simulate_cipher(int sequence_length) {
    unsigned char data[SHA256_DIGEST_LENGTH * sequence_length];
    int data_len = 0;

    for (int i = 0; i < sequence_length; i++) {
        char str_i[12];
        sprintf(str_i, "%d", i);
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, str_i, strlen(str_i));
        SHA256_Final(hash, &sha256);
        memcpy(data + data_len, hash, SHA256_DIGEST_LENGTH);
        data_len += SHA256_DIGEST_LENGTH;
    }

    unsigned char final_hash[SHA256_DIGEST_LENGTH];
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, data_len);
    SHA256_Final(final_hash, &sha256);

    char* hex = (char*)malloc(2 * SHA256_DIGEST_LENGTH + 1);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hex + 2 * i, "%02x", final_hash[i]);
    }
    hex[2 * SHA256_DIGEST_LENGTH] = '\0';

    return hex;
}

int main() {
    char* result = simulate_cipher(10);
    printf("%s\n", result);
    free(result);
    return 0;
}