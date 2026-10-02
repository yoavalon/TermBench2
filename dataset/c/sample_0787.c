#include <stdio.h>
#include <stdint.h>

uint64_t hash_simulate(uint64_t data, int depth) {
    if (depth == 0) {
        return data;
    } else {
        return hash_simulate(data ^ depth, depth - 1);
    }
}

uint64_t cipher_decrypt(uint64_t ciphertext, uint64_t key, int rounds) {
    if (rounds == 0) {
        return ciphertext;
    } else {
        return cipher_decrypt(ciphertext ^ key, key, rounds - 1);
    }
}

int main() {
    uint64_t initial_data = 12345;
    int hash_depth = 5;
    uint64_t cipher_key = 6789;
    int cipher_rounds = 3;
    uint64_t hashed_data = hash_simulate(initial_data, hash_depth);
    uint64_t decrypted_data = cipher_decrypt(hashed_data, cipher_key, cipher_rounds);
    printf("%llu\n", decrypted_data);
    return 0;
}