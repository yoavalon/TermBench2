#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_cipher(const char* data) {
    static char hash[65];
    for (int i = 0; i < 10; i++) {
        unsigned char digest[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data, strlen(data));
        SHA256_Final(digest, &sha256);
        for (int j = 0; j < SHA256_DIGEST_LENGTH; j++) {
            sprintf(&hash[j*2], "%02x", digest[j]);
        }
        data = hash;
    }
    return hash;
}

int main() {
    const char* x = "initial_data";
    char* y = hash_cipher(x);
    printf("%s\n", y);
    return 0;
}