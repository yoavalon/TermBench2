#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char** generate_hash_sequence(char* seed, int length) {
    char** sequence = (char**)malloc(length * sizeof(char*));
    for (int i = 0; i < length; i++) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, seed, strlen(seed));
        SHA256_Final(hash, &sha256);
        sequence[i] = (char*)malloc(65 * sizeof(char));
        for (int j = 0; j < SHA256_DIGEST_LENGTH; j++) {
            sprintf(&sequence[i][j*2], "%02x", hash[j]);
        }
        seed = sequence[i];
    }
    return sequence;
}

int main() {
    char* seed = "start";
    int length = 10;
    char** sequence = generate_hash_sequence(seed, length);
    for (int i = 0; i < length; i++) {
        printf("%s\n", sequence[i]);
        free(sequence[i]);
    }
    free(sequence);
    return 0;
}