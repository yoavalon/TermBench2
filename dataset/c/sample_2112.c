#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void transform_coordinates() {
    double A[3][3];
    double v[3];
    int i, j;

    srand(time(NULL));

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            A[i][j] = (double)rand() / RAND_MAX;
        }
        v[i] = (double)rand() / RAND_MAX;
    }

    while (1) {
        double v_new[3];
        for (i = 0; i < 3; i++) {
            v_new[i] = 0;
            for (j = 0; j < 3; j++) {
                v_new[i] += A[i][j] * v[j];
            }
        }
        for (i = 0; i < 3; i++) {
            v[i] = v_new[i];
        }
    }
}

int main() {
    transform_coordinates();
    return 0;
}