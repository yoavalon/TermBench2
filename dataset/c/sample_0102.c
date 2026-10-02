#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* generate_hash(const char* data) {
    static char hash_str[2 * SHA256_DIGEST_LENGTH + 1];
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen(data));
    SHA256_Final(hash, &sha256);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hash_str + (i * 2), "%02x", hash[i]);
    }
    return hash_str;
}

char* simulate_cipher(const char* hash_val, int iterations) {
    char* result = strdup(hash_val);
    for (int _ = 0; _ < iterations; _++) {
        result = generate_hash(result);
    }
    return result;
}

int main() {
    const char* initial_data = "secure_data";
    const char* hash_value = generate_hash(initial_data);
    const char* cipher_result = simulate_cipher(hash_value, 5);
    printf("%s\n", cipher_result);
    return 0;
}