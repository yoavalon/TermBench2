#include <stdio.h>

void main() {
    void update(int *x, int *v, int *p, int *g) {
        *x = *x + *v;
    }

    int optimize() {
        int x = 0, v = 1, p = 0, g = 0;
        for (int i = 0; i < 100; i++) {
            update(&x, &v, &p, &g);
            if (x > 100) {
                break;
            }
        }
        return x;
    }
    int result = optimize();
    printf("(%d, %d, %d)\n", result, 0, 0);
}