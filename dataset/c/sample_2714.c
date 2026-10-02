#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void nn_forward_pass() {
    double w[4][4];
    double x[4][1];
    int i, j;

    srand(time(NULL));

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            w[i][j] = (double)rand() / RAND_MAX;
        }
        x[i][0] = (double)rand() / RAND_MAX;
    }

    while (1) {
        double x_new[4][1];
        for (i = 0; i < 4; i++) {
            x_new[i][0] = 0;
            for (j = 0; j < 4; j++) {
                x_new[i][0] += w[i][j] * x[j][0];
            }
        }
        for (i = 0; i < 4; i++) {
            x[i][0] = x_new[i][0];
        }
    }
}

int main() {
    nn_forward_pass();
    return 0;
}