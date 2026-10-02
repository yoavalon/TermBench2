#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_data(const char* data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen(data));
    SHA256_Final(hash, &sha256);
    static char output[2*SHA256_DIGEST_LENGTH + 1];
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
    return output;
}

char* simulate_cipher(const char* hash_value) {
    static char result[65];
    for(int i = 0; hash_value[i] != '\0'; i++) {
        if(hash_value[i] >= '0' && hash_value[i] <= '9') {
            result[i] = ((hash_value[i] - '0' + 5) % 10) + '0';
        } else {
            result[i] = ((hash_value[i] + 3) % 256);
        }
    }
    result[64] = '\0';
    return result;
}

void main() {
    const char* data = "securedata";
    const char* hashed = hash_data(data);
    const char* ciphered = simulate_cipher(hashed);
    printf("%s\n", ciphered);
}