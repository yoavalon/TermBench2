#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_sim(const char* x) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, x, strlen(x));
    SHA256_Final(hash, &sha256);
    static char output[2 * SHA256_DIGEST_LENGTH + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
    return output;
}

char* cipher(const char* x) {
    static char output[1024];
    for (int i = 0; i < strlen(x); i++) {
        output[i] = (char)(x[i] + 1);
    }
    output[strlen(x)] = '\0';
    return output;
}

void recurse(const char* a) {
    char* hashed = hash_sim(a);
    char* ciphered = cipher(hashed);
    recurse(ciphered);
}

int main() {
    recurse("seed");
    return 0;
}