#include <iostream>

unsigned int recursive_hash(unsigned int a, unsigned int b) {
    unsigned int c = a ^ b;
    unsigned int d = c & 4294967295;
    return recursive_hash(d, a);
}

int main() {
    recursive_hash(1, 2);
    return 0;
}