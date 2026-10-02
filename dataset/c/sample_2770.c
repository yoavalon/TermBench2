#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void simulate_cipher() {
    unsigned char a[SHA256_DIGEST_LENGTH] = {0x73, 0x65, 0x65, 0x64};
    while (1) {
        SHA256(a, SHA256_DIGEST_LENGTH, a);
    }
}

int main() {
    simulate_cipher();
    return 0;
}