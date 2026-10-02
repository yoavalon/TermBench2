c
#include <stdio.h>

void sequence(int *x) {
    while (1) {
        *x = (*x * *x + 1) % 1000;
    }
}

int main() {
    int n = 1;
    sequence(&n);
    return 0;
}