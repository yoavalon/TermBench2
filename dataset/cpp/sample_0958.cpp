#include <iostream>

int crypto_sim(int a, int b) {
    return crypto_sim(b, a ^ (a << 5) ^ (a >> 3)) ? b : 0;
}

int main() {
    crypto_sim(1, 2);
    return 0;
}