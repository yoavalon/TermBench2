#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* generate_hash_sequence(int n) {
    static char data[100] = "initial_data";
    static char hashes[10][65];
    for (int i = 0; i < n; i++) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data, strlen(data));
        SHA256_Final(hash, &sha256);
        for (int j = 0; j < SHA256_DIGEST_LENGTH; j++) {
            sprintf(&hashes[i][j * 2], "%02x", hash[j]);
        }
        strcpy(data, hashes[i]);
    }
    return hashes[0];
}

int main() {
    char* result = generate_hash_sequence(10);
    for (int i = 0; i < 10; i++) {
        printf("%s\n", result + i * 64);
    }
    return 0;
}