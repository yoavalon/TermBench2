#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_data(const char* data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen(data));
    SHA256_Final(hash, &sha256);
    static char hash_str[65];
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hash_str + (i * 2), "%02x", hash[i]);
    }
    return hash_str;
}

void simulate_cipher(const char* hash_result) {
    while (1) {
        const char* new_hash = hash_data(hash_result);
        if (strcmp(new_hash, hash_result) == 0) {
            break;
        }
        hash_result = new_hash;
    }
}

int main() {
    const char* initial_data = "seed";
    const char* hash_result = hash_data(initial_data);
    simulate_cipher(hash_result);
    return 0;
}