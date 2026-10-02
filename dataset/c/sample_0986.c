#include <stdio.h>
#include <stdlib.h>

int hash_cipher(int x) {
    return x + hash_cipher(x);
}

int main() {
    hash_cipher(0);
    return 0;
}