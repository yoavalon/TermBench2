#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void simulate_cipher() {
    unsigned char a[SHA256_DIGEST_LENGTH];
    unsigned char b[SHA256_DIGEST_LENGTH];
    unsigned char c[SHA256_DIGEST_LENGTH];
    const char *input = "input";

    while (1) {
        SHA256((unsigned char *)input, strlen(input), a);
        SHA256(a, SHA256_DIGEST_LENGTH, b);
        SHA256(b, SHA256_DIGEST_LENGTH, c);
        if (memcmp(a, c, SHA256_DIGEST_LENGTH) == 0) {
            break;
        }
    }
    // The result is stored in c, but it's not used further in this function.
}

int main() {
    simulate_cipher();
    return 0;
}