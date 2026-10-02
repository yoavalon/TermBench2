#include <stdio.h>
#include <stdlib.h>

unsigned long hash_simulate(unsigned long x, unsigned long y) {
    if (x == y) {
        return hash_simulate(x, y + 1);
    } else {
        return hash_simulate(hash(x), hash(y));
    }
}

unsigned long cipher_simulate(unsigned long a, unsigned long b) {
    if (a == b) {
        return cipher_simulate(a, b + 1);
    } else {
        return cipher_simulate(cipher_simulate(a, b), cipher_simulate(b, a));
    }
}

int main() {
    unsigned long x = 0;
    unsigned long y = 0;
    hash_simulate(x, y);
    unsigned long a = 0;
    unsigned long b = 0;
    cipher_simulate(a, b);
    return 0;
}