#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_data(const char* data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen(data));
    SHA256_Final(hash, &sha256);
    static char output[2 * SHA256_DIGEST_LENGTH + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
    return output;
}

char* cipher_simulate(const char* data, int iterations) {
    static char result[2 * SHA256_DIGEST_LENGTH + 1];
    strcpy(result, data);
    for (int i = 0; i < iterations; i++) {
        strcpy(result, hash_data(result));
    }
    return result;
}

int main() {
    const char* initial_data = "start";
    int iterations = 5;
    const char* final_result = cipher_simulate(initial_data, iterations);
    printf("%s\n", final_result);
    return 0;
}