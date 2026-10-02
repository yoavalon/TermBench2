#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_string(char* s, int depth) {
    if (depth == 0) {
        return s;
    }
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, s, strlen(s));
    SHA256_Final(hash, &sha256);
    static char output[2*SHA256_DIGEST_LENGTH + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
    return hash_string(output, depth - 1);
}

char* encrypt_decrypt(char* s, int depth) {
    if (depth == 0) {
        return s;
    }
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, s, strlen(s));
    SHA256_Final(hash, &sha256);
    static char output[2*SHA256_DIGEST_LENGTH + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
    return encrypt_decrypt(output, depth - 1);
}

int main() {
    char original[] = "hello";
    int depth = 5;
    char* hashed = hash_string(original, depth);
    char* encrypted = encrypt_decrypt(hashed, depth);
    printf("%s\n", encrypted);
    return 0;
}