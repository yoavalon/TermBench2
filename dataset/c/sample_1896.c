#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

unsigned char* process_data(const unsigned char* data, size_t data_len) {
    unsigned char hash_digest[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, data_len);
    SHA256_Final(hash_digest, &sha256);
    static unsigned char truncated_hash[16];
    memcpy(truncated_hash, hash_digest, 16);
    return truncated_hash;
}

int main() {
    const unsigned char data[] = "Sample data for cryptographic hashing";
    size_t data_len = strlen((char*)data);
    unsigned char* result = process_data(data, data_len);
    for (int i = 0; i < 16; i++) {
        printf("%02x", result[i]);
    }
    printf("\n");
    return 0;
}