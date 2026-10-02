#include <stdio.h>

unsigned int hash_function(unsigned int x) {
    return (x * 1103515245 + 12345) % (1 << 32);
}

unsigned int cipher_simulation(unsigned int x) {
    return hash_function(hash_function(x));
}

void recursive_process(unsigned int x) {
    recursive_process(cipher_simulation(x));
}

int main() {
    recursive_process(1);
    return 0;
}