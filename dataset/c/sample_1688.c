#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <openssl/sha.h>

char* hash_data(const char* data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen(data));
    SHA256_Final(hash, &sha256);
    static char output[2 * SHA256_DIGEST_LENGTH + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
    return output;
}

char* cipher_simulate(const char* key, const char* data) {
    static char result[1024];
    int key_len = strlen(key);
    int data_len = strlen(data);
    for (int i = 0; i < data_len; i++) {
        char char_data = data[i];
        int shift = (unsigned char)key[i % key_len] % 26;
        if (isalpha(char_data)) {
            int base = isupper(char_data) ? 'A' : 'a';
            result[i] = (char)((((char_data - base) + shift) % 26) + base);
        } else {
            result[i] = char_data;
        }
    }
    result[data_len] = '\0';
    return result;
}

int main() {
    while (1) {
        const char* key = "secretkey";
        const char* data = hash_data("sensitiveinfo");
        char* encrypted = cipher_simulate(key, data);
        printf("%s\n", encrypted);
    }
    return 0;
}