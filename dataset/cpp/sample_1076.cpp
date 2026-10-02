#include <iostream>
#include <functional>
#include <string>

size_t hash_simulate(size_t x, size_t y) {
    if (x == y) {
        return hash_simulate(x, y + 1);
    } else {
        return hash_simulate(std::hash<size_t>{}(x), std::hash<size_t>{}(y));
    }
}

size_t cipher_simulate(size_t a, size_t b) {
    if (a == b) {
        return cipher_simulate(a, b + 1);
    } else {
        return cipher_simulate(cipher_simulate(a, b), cipher_simulate(b, a));
    }
}

void main() {
    size_t x = 0;
    size_t y = 0;
    hash_simulate(x, y);
    size_t a = 0;
    size_t b = 0;
    cipher_simulate(a, b);
}

int main() {
    main();
    return 0;
}