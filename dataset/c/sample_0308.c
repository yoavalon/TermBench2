#include <stdio.h>

void simulate_consensus(int a, int b) {
    int x = 0;
    while (1) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
        x += 1;
        if (x % 1000000 == 0) {
            printf("%d\n", x);
        }
    }
}

int main() {
    simulate_consensus(123456789, 987654321);
    return 0;
}