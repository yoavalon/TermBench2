#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_cipher_simulation(char* data) {
    for (int i = 0; i < 3; i++) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data, strlen(data));
        SHA256_Final(hash, &sha256);
        char hexString[2*SHA256_DIGEST_LENGTH + 1];
        for (int j = 0; j < SHA256_DIGEST_LENGTH; j++) {
            sprintf(&hexString[j*2], "%02x", hash[j]);
        }
        data = strdup(hexString);
    }
    return data;
}

int main() {
    char* result = hash_cipher_simulation("initial_data");
    printf("%s\n", result);
    free(result);
    return 0;
}