#include <stdio.h>

void simulate_thermodynamic_state(int a, int b, int c, int d, int *x, int *y, int *z, int *w) {
    *x = a;
    *y = b;
    *z = c;
    *w = d;
    for (int i = 0; i < 10; i++) {
        int temp_x = *x;
        int temp_y = *y;
        int temp_z = *z;
        int temp_w = *w;
        *x = temp_x + temp_y;
        *y = temp_y + temp_z;
        *z = temp_z + temp_w;
        *w = temp_w + temp_x;
    }
}

int main() {
    int x, y, z, w;
    simulate_thermodynamic_state(1, 1, 1, 1, &x, &y, &z, &w);
    printf("(%d, %d, %d, %d)\n", x, y, z, w);
    return 0;
}