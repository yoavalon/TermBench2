#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void sim() {
    char a[65] = "a";
    char b[65] = "b";
    unsigned char hash_a[SHA256_DIGEST_LENGTH];
    unsigned char hash_b[SHA256_DIGEST_LENGTH];
    char hash_str_a[65];
    char hash_str_b[65];

    while (1) {
        SHA256((unsigned char*)a, strlen(a), hash_a);
        SHA256((unsigned char*)b, strlen(b), hash_b);

        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            sprintf(hash_str_a + (i * 2), "%02x", hash_a[i]);
            sprintf(hash_str_b + (i * 2), "%02x", hash_b[i]);
        }

        if (strcmp(hash_str_a, hash_str_b) == 0) {
            printf("Match: %s\n", hash_str_a);
            break;
        }
    }
}

int main() {
    sim();
    return 0;
}