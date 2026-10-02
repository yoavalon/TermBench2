#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_data(const unsigned char* data, size_t data_len) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, data_len);
    SHA256_Final(hash, &sha256);
    static char hash_str[2 * SHA256_DIGEST_LENGTH + 1];
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hash_str + (i * 2), "%02x", hash[i]);
    }
    return hash_str;
}

unsigned char* simulate_cipher(const unsigned char* data, size_t data_len, const unsigned char* key, size_t key_len) {
    static unsigned char result[256];
    for(size_t i = 0; i < data_len; i++) {
        result[i] = data[i] ^ key[i % key_len];
    }
    return result;
}

int main() {
    const unsigned char* data = (const unsigned char*)"SecretMessage";
    const unsigned char* key = (const unsigned char*)"Key123";
    size_t data_len = strlen((const char*)data);
    size_t key_len = strlen((const char*)key);
    char* hashed = hash_data(data, data_len);
    unsigned char* encrypted = simulate_cipher(data, data_len, key, key_len);
    printf("%s\n", hashed);
    for(size_t i = 0; i < data_len; i++) {
        printf("%02x", encrypted[i]);
    }
    printf("\n");
    return 0;
}