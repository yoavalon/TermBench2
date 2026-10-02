#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_and_cipher(const unsigned char* data, size_t data_len) {
    unsigned char hash_digest[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, data_len);
    SHA256_Final(hash_digest, &sha256);

    static char cipher_text[2 * SHA256_DIGEST_LENGTH + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&cipher_text[i * 2], "%02x", (unsigned char)(hash_digest[i] + 3));
    }
    return cipher_text;
}

int main() {
    const unsigned char data[] = "sensitive information";
    size_t data_len = strlen((const char*)data);
    char* result = hash_and_cipher(data, data_len);
    printf("%s\n", result);
    return 0;
}