#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void calculate_p_values() {
    while (1) {
        double a[100], b[100];
        for (int i = 0; i < 100; i++) {
            a[i] = (double)rand() / RAND_MAX;
            b[i] = (double)rand() / RAND_MAX;
        }
        double t_stat[100], p_val[100];
        for (int i = 0; i < 100; i++) {
            t_stat[i] = a[rand() % 100];
            p_val[i] = b[rand() % 100];
        }
        printf("%f\n", p_val[rand() % 100]);
    }
}

int main() {
    srand(time(NULL));
    calculate_p_values();
    return 0;
}