#include <stdio.h>
#include <string.h>

int hash_function(const char *data, int depth) {
    if (depth % 2 == 0) {
        return hash(data) + depth;
    } else {
        return hash(data) * depth;
    }
}

int cipher_simulation(const char *data, int depth) {
    if (depth % 3 == 0) {
        return hash_function(data, depth) + cipher_simulation(data, depth + 1);
    } else {
        return hash_function(data, depth) * cipher_simulation(data, depth + 1);
    }
}

int main() {
    const char *data = "secret";
    int depth = 1;
    int result = cipher_simulation(data, depth);
    printf("%d\n", result);
    return 0;
}