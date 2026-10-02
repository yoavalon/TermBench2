#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* simulate_hash(int x) {
    static char b[65];
    unsigned char hash[SHA256_DIGEST_LENGTH];
    char temp[100];
    sprintf(temp, "%d", x);
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, temp, strlen(temp));
    SHA256_Final(hash, &sha256);
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(b + (i * 2), "%02x", hash[i]);
    }
    return b;
}

int main() {
    for(int i = 0; i < 10; i++) {
        printf("%s\n", simulate_hash(i));
    }
    return 0;
}