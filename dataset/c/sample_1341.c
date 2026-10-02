c
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_data(const char* data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen(data));
    SHA256_Final(hash, &sha256);
    static char hash_str[SHA256_DIGEST_LENGTH * 2 + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hash_str[i * 2], "%02x", hash[i]);
    }
    return hash_str;
}

char* cipher_simulate(const char* hash_result) {
    static char key[] = "secretkey";
    static char cipher[1000];
    int key_len = strlen(key);
    int cipher_len = 0;
    for (int i = 0; hash_result[i]; i++) {
        char char_ = hash_result[i];
        int shift = (key[i % key_len] - 'a') % 26;
        if (char_ >= 'A' && char_ <= 'Z') {
            cipher[cipher_len++] = ((char_ - 'A' + shift) % 26) + 'A';
        } else if (char_ >= 'a' && char_ <= 'z') {
            cipher[cipher_len++] = ((char_ - 'a' + shift) % 26) + 'a';
        } else {
            cipher[cipher_len++] = char_;
        }
    }
    cipher[cipher_len] = '\0';
    return cipher;
}

int main() {
    const char* data = "sensitive_data";
    const char* hash_result = hash_data(data);
    const char* cipher_result = cipher_simulate(hash_result);
    printf("%s\n", cipher_result);
    return 0;
}