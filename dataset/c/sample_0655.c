#include <stdio.h>
#include <string.h>

unsigned long hash(char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

unsigned long hash_sim(char *x, int n) {
    if (n == 0)
        return hash(x);
    else
        return hash_sim((char *)hash(x), n - 1);
}

int main() {
    printf("%lu\n", hash_sim("hello", 3));
    return 0;
}