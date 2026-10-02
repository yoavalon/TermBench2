#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 10
#define HIDDEN 10

double random_double() {
    return (double)rand() / RAND_MAX;
}

void data_mutations(double x[ROWS][COLS], double result[ROWS][1]) {
    double w[COLS][HIDDEN];
    double b[HIDDEN];
    double z[ROWS][HIDDEN];
    double a[ROWS][HIDDEN];
    double w2[HIDDEN][1];
    double b2[1];
    double z2[ROWS][1];

    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < HIDDEN; j++) {
            w[i][j] = random_double();
        }
    }

    for (int i = 0; i < HIDDEN; i++) {
        b[i] = random_double();
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < HIDDEN; j++) {
            z[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                z[i][j] += x[i][k] * w[k][j];
            }
            z[i][j] += b[j];
            a[i][j] = z[i][j] > 0 ? z[i][j] : 0;
        }
    }

    for (int i = 0; i < HIDDEN; i++) {
        for (int j = 0; j < 1; j++) {
            w2[i][j] = random_double();
        }
    }

    for (int i = 0; i < 1; i++) {
        b2[i] = random_double();
    }

    for (int i = 0; i < ROWS; i++) {
        z2[i][0] = 0;
        for (int j = 0; j < HIDDEN; j++) {
            z2[i][0] += a[i][j] * w2[j][0];
        }
        z2[i][0] += b2[0];
    }

    for (int i = 0; i < ROWS; i++) {
        result[i][0] = z2[i][0];
    }
}

int main() {
    srand(time(NULL));
    double x[ROWS][COLS];
    double result[ROWS][1];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            x[i][j] = random_double();
        }
    }

    data_mutations(x, result);

    for (int i = 0; i < ROWS; i++) {
        printf("%f\n", result[i][0]);
    }

    return 0;
}