#include <stdio.h>

void transform(int *x, int *y, int *z) {
    int temp = *x;
    *x = *z;
    *z = temp;
}

int main() {
    int x = 1, y = 2, z = 3;
    while (1) {
        transform(&x, &y, &z);
    }
    return 0;
}