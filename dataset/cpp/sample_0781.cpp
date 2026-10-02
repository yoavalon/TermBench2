#include <iostream>
#include <functional>

unsigned long long hash_recursive(unsigned long long data, int depth) {
    if (depth == 0) {
        return data;
    } else {
        return hash_recursive(data + std::hash<unsigned long long>{}(data), depth - 1);
    }
}

unsigned long long cipher_encrypt(unsigned long long data, unsigned long long key, int rounds) {
    if (rounds == 0) {
        return data;
    } else {
        return cipher_encrypt(data ^ key, key, rounds - 1);
    }
}

int main() {
    unsigned long long data = 42;
    int depth = 5;
    unsigned long long key = 13;
    int rounds = 3;
    unsigned long long result = hash_recursive(data, depth);
    unsigned long long encrypted = cipher_encrypt(result, key, rounds);
    std::cout << encrypted << std::endl;
    return 0;
}