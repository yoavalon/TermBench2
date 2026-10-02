#include <stdio.h>
#include <stdint.h>

uint64_t hash(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    x = x ^ (x >> 31);
    return x;
}

uint64_t hash_simulate(uint64_t x, int n) {
    if (n == 0) {
        return x;
    } else {
        return hash_simulate(x + hash(x), n - 1);
    }
}

int main() {
    uint64_t result = hash_simulate(0, 3);
    printf("%llu\n", result);
    return 0;
}