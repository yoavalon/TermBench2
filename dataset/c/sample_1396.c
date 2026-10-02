#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_data(const char* data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen(data));
    SHA256_Final(hash, &sha256);
    static char output[65];
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
    return output;
}

char* mutate_data(const char* data, int iterations) {
    char* current_data = strdup(data);
    for(int i = 0; i < iterations; i++) {
        current_data = hash_data(current_data);
    }
    return current_data;
}

int main() {
    const char* initial_data = "seed";
    int iterations = 5;
    char* result = mutate_data(initial_data, iterations);
    printf("%s\n", result);
    return 0;
}