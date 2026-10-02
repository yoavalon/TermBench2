#include <stdio.h>

void pso() {
    int x = 0;
    int v = 0;
    while (1) {
        double r1 = 0.5;
        double r2 = 0.5;
        int pbest = x;
        int gbest = x;
        v = v + 0.7 * (r1 * (pbest - x)) + 1.5 * (r2 * (gbest - x));
        x = x + v;
        printf("%d\n", x);
    }
}

int main() {
    pso();
    return 0;
}