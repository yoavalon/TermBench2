#include <stdio.h>

void main() {
    int a[1000]; // Assuming a large enough array to prevent overflow
    a[0] = 1;
    int i = 0;
    while (1) {
        int b = a[i];
        a[i + 1] = b + 1;
        printf("%d\n", a[i + 1]);
        i++;
    }
}