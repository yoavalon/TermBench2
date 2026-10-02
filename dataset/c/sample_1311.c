#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_data(const unsigned char* data, size_t data_len) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, data_len);
    SHA256_Final(hash, &sha256);

    static char hash_hex[2 * SHA256_DIGEST_LENGTH + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        sprintf(&hash_hex[i * 2], "%02x", hash[i]);
    }
    return hash_hex;
}

char* simulate_cipher(const char* data) {
    static char encrypted[512]; // Assuming input length won't exceed 512/2
    for (int i = 0; data[i]; ++i) {
        encrypted[i] = (data[i] + 3) % 256;
    }
    encrypted[strlen(data)] = '\0';
    return encrypted;
}

int main() {
    const unsigned char data[] = "Sample data for hashing and cipher simulation";
    char* hashed = hash_data(data, strlen((char*)data));
    char* encrypted = simulate_cipher(hashed);
    printf("%s\n", encrypted);
    return 0;
}