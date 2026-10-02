#include <stdio.h>
#include <string.h>

unsigned long hash_func(const char *data, int depth) {
    if (depth == 0) {
        return data;
    } else {
        return hash_func((const char *)hash_func(data, depth - 1), depth - 1);
    }
}

unsigned long cipher_simulate(const char *data, int depth) {
    return hash_func(data, depth);
}

int main() {
    const char *input = "Hello, World!";
    int depth = 3;
    printf("%lu\n", cipher_simulate(input, depth));
    return 0;
}