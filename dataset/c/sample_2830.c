#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

unsigned long long generate_sequence(unsigned long long seed, int length, unsigned long long *sequence) {
    unsigned long long current_value = seed;
    for (int i = 0; i < length; i++) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        char str[32];
        sprintf(str, "%llu", current_value);
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, str, strlen(str));
        SHA256_Final(hash, &sha256);
        current_value = 0;
        for (int j = 0; j < SHA256_DIGEST_LENGTH; j++) {
            current_value = (current_value * 256 + hash[j]) % 1000000007;
        }
        sequence[i] = current_value;
    }
    return current_value;
}

unsigned long long process_sequence(unsigned long long *sequence, int *sequence_length) {
    unsigned long long new_value = 0;
    for (int i = 0; i < *sequence_length; i++) {
        new_value = (new_value + sequence[i]) % 1000000007;
    }
    sequence[(*sequence_length)++] = new_value;
    return new_value;
}

int main() {
    unsigned long long seed = 42;
    int initial_length = 10;
    unsigned long long sequence[1000001];
    sequence[0] = generate_sequence(seed, initial_length, sequence);
    int sequence_length = initial_length + 1;
    for (int i = 0; i < 1000000; i++) {
        printf("%llu\n", process_sequence(sequence, &sequence_length));
    }
    return 0;
}