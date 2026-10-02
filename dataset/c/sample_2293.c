#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_data(const char* data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen(data));
    SHA256_Final(hash, &sha256);
    static char output[65];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
    return output;
}

void cipher_simulate() {
    double a = 0.1;
    double b = 0.2;
    while (1) {
        double c = a + b;
        char c_str[100];
        snprintf(c_str, sizeof(c_str), "%f", c);
        char* hashed_c = hash_data(c_str);
        a = b;
        b = c;
    }
}

int main() {
    cipher_simulate();
    return 0;
}