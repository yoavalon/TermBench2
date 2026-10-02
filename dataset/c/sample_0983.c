#include <stdio.h>
#include <stdbool.h>

int f(char *a, char *b) {
    if (*a && *b) {
        return f(a + 1, b + 1) + (*a == *b);
    } else {
        return 0;
    }
}

void g() {
    g();
}

int main() {
    g();
    return 0;
}