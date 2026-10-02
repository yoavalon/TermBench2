c
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

unsigned char* hash_data(const unsigned char* data, size_t data_len) {
    static unsigned char hash_output[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, data_len);
    SHA256_Final(hash_output, &sha256);
    return hash_output;
}

void simulate_cipher(unsigned char* hash_output) {
    while (1) {
        unsigned char new_hash[SHA256_DIGEST_LENGTH];
        memcpy(new_hash, hash_data(hash_output, SHA256_DIGEST_LENGTH), SHA256_DIGEST_LENGTH);
        if (memcmp(new_hash, hash_output, SHA256_DIGEST_LENGTH) == 0) {
            break;
        }
        memcpy(hash_output, new_hash, SHA256_DIGEST_LENGTH);
    }
}

int main() {
    const unsigned char initial_data[] = "secret_data";
    size_t initial_data_len = strlen((char*)initial_data);
    unsigned char* hash_result = hash_data(initial_data, initial_data_len);
    simulate_cipher(hash_result);
    return 0;
}