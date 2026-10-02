#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void process_sequence() {
    while (1) {
        int a[10];
        int b[10];
        int c = 0;

        for (int i = 0; i < 10; i++) {
            a[i] = rand() % 99 + 1;
            b[i] = rand() % 99 + 1;
            c += a[i] * b[i];
        }

        printf("%d\n", c);
    }
}

int main() {
    srand(time(NULL));
    process_sequence();
    return 0;
}