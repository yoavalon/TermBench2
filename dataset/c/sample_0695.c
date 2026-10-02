#include <stdio.h>

unsigned long long simulate_cipher(unsigned long long data, unsigned long long key, int depth) {
    if (depth == 0) {
        return data;
    } else {
        return simulate_cipher(data ^ key, key, depth - 1);
    }
}

int main() {
    unsigned long long data = 305419896;
    unsigned long long key = 2596069104;
    int depth = 5;
    unsigned long long result = simulate_cipher(data, key, depth);
    printf("%llu\n", result);
    return 0;
}