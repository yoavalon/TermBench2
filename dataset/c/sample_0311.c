#include <stdio.h>
#include <string.h>
#include <stdint.h>

uint64_t hash(const char *str) {
    uint64_t h = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        h = h * 31 + str[i];
    }
    return h;
}

void crypto_sim() {
    while (1) {
        char x[] = "data";
        uint64_t h = hash(x);
        if (h % 2 == 0) {
            strcat(x, "1");
        } else {
            strcat(x, "0");
        }
    }
}

int main() {
    crypto_sim();
    return 0;
}