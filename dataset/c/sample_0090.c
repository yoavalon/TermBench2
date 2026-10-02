#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* crypto_simulation(const unsigned char* data, size_t data_len) {
    unsigned char hash_digest[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, data_len);
    SHA256_Final(hash_digest, &sha256);

    static char hash_string[11];
    for (int i = 0; i < 10; i++) {
        sprintf(&hash_string[i*2], "%02x", hash_digest[i]);
    }
    hash_string[20] = '\0';
    return hash_string;
}

int main() {
    const unsigned char data[] = "Sample data for hashing";
    char* result = crypto_simulation(data, strlen((char*)data));
    printf("%s\n", result);
    return 0;
}