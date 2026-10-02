#include <stdio.h>
#include <stdint.h>

uint64_t hash_recursive(uint64_t data, int depth) {
    if (depth == 0) {
        return data;
    } else {
        return hash_recursive(data + hash(data), depth - 1);
    }
}

uint64_t cipher_encrypt(uint64_t data, uint64_t key, int rounds) {
    if (rounds == 0) {
        return data;
    } else {
        return cipher_encrypt(data ^ key, key, rounds - 1);
    }
}

unsigned long hash(unsigned long x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}

int main() {
    uint64_t data = 42;
    int depth = 5;
    uint64_t key = 13;
    int rounds = 3;
    uint64_t result = hash_recursive(data, depth);
    uint64_t encrypted = cipher_encrypt(result, key, rounds);
    printf("%lu\n", encrypted);
    return 0;
}