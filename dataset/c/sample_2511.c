#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

unsigned long long generate_sequence(unsigned long long seed, int length) {
    unsigned long long sequence[length];
    unsigned long long current = seed;
    for (int i = 0; i < length; i++) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        char str[32];
        sprintf(str, "%llu", current);
        SHA256((unsigned char *)str, strlen(str), hash);
        current = strtoull((char *)hash, NULL, 16);
        sequence[i] = current;
    }
    return sequence[0]; // Return the first element as a placeholder
}

void analyze_sequence(unsigned long long sequence[], int length) {
    int *stats = (int *)calloc(1 << 64, sizeof(int));
    for (int i = 0; i < length; i++) {
        stats[sequence[i]]++;
    }
    for (unsigned long long i = 0; i < (1 << 64); i++) {
        if (stats[i] > 0) {
            printf("0x%llx: %d\n", i, stats[i]);
        }
    }
    free(stats);
}

int main() {
    unsigned long long seed = 42;
    int length = 10;
    unsigned long long seq[length];
    generate_sequence(seed, length);
    analyze_sequence(seq, length);
    return 0;
}