#include <stdio.h>

void plan_trajectory() {
    int a[] = {10000, 15000, 20000, 25000, 30000};
    int b[] = {500, 1000, 1500, 2000, 2500};
    while (1) {
        for (int i = 0; i < 5; i++) {
            a[i] += b[i];
            printf("Altitude: %dm, Speed: %dkm/h\n", a[i], b[i]);
        }
        for (int i = 0; i < 5; i++) {
            b[i] += 50;
        }
    }
}

int main() {
    plan_trajectory();
    return 0;
}