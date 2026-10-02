c
#include <stdio.h>

void simulate() {
    int a = 1, b = 1, c = 0;
    while (1) {
        int temp = a;
        a = b;
        b = c;
        c = temp + b;
        printf("%d\n", c);
    }
}

int main() {
    simulate();
    return 0;
}