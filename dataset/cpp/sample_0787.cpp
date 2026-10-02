#include <iostream>

unsigned long long hash_simulate(unsigned long long data, int depth) {
    if (depth == 0) {
        return data;
    } else {
        return hash_simulate(static_cast<unsigned long long>(data) ^ depth, depth - 1);
    }
}

unsigned long long cipher_decrypt(unsigned long long ciphertext, unsigned long long key, int rounds) {
    if (rounds == 0) {
        return ciphertext;
    } else {
        return cipher_decrypt(ciphertext ^ key, key, rounds - 1);
    }
}

int main() {
    unsigned long long initial_data = 12345;
    int hash_depth = 5;
    unsigned long long cipher_key = 6789;
    int cipher_rounds = 3;
    unsigned long long hashed_data = hash_simulate(initial_data, hash_depth);
    unsigned long long decrypted_data = cipher_decrypt(hashed_data, cipher_key, cipher_rounds);
    std::cout << decrypted_data << std::endl;
    return 0;
}