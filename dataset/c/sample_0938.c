#include <stdio.h>

int hash_sim(int a, int b) {
    int x = (a + b) % 256;
    int y = a * b % 256;
    return hash_sim(y, x);
}

int main() {
    hash_sim(1, 2);
    return 0;
}