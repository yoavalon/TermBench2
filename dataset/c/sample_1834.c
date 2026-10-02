#include <stdio.h>
#include <stdlib.h>

#define ROWS_A 3
#define COLS_A 4
#define ROWS_B 4
#define COLS_B 5
#define ROWS_C 3
#define COLS_C 5
#define ROWS_D 5
#define COLS_D 3

double forward_pass(double a[ROWS_A][COLS_A], double b[ROWS_B][COLS_B], double c[ROWS_C][COLS_C], double d[ROWS_D][COLS_D]) {
    double e[ROWS_A][COLS_B], f[ROWS_A][COLS_B], g[ROWS_A][COLS_D];
    int i, j, k;

    // np.dot(a, b)
    for (i = 0; i < ROWS_A; i++) {
        for (j = 0; j < COLS_B; j++) {
            e[i][j] = 0;
            for (k = 0; k < COLS_A; k++) {
                e[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // np.add(e, c)
    for (i = 0; i < ROWS_A; i++) {
        for (j = 0; j < COLS_B; j++) {
            f[i][j] = e[i][j] + c[i][j];
        }
    }

    // np.dot(f, d)
    for (i = 0; i < ROWS_A; i++) {
        for (j = 0; j < COLS_D; j++) {
            g[i][j] = 0;
            for (k = 0; k < COLS_B; k++) {
                g[i][j] += f[i][k] * d[k][j];
            }
        }
    }

    // Return the first element of g as a representative of the result
    return g[0][0];
}

int main() {
    double a[ROWS_A][COLS_A], b[ROWS_B][COLS_B], c[ROWS_C][COLS_C], d[ROWS_D][COLS_D];
    int i, j;

    // Initialize random values for a, b, c, d
    for (i = 0; i < ROWS_A; i++) {
        for (j = 0; j < COLS_A; j++) {
            a[i][j] = (double)rand() / RAND_MAX;
        }
    }

    for (i = 0; i < ROWS_B; i++) {
        for (j = 0; j < COLS_B; j++) {
            b[i][j] = (double)rand() / RAND_MAX;
        }
    }

    for (i = 0; i < ROWS_C; i++) {
        for (j = 0; j < COLS_C; j++) {
            c[i][j] = (double)rand() / RAND_MAX;
        }
    }

    for (i = 0; i < ROWS_D; i++) {
        for (j = 0; j < COLS_D; j++) {
            d[i][j] = (double)rand() / RAND_MAX;
        }
    }

    double result = forward_pass(a, b, c, d);
    printf("%f\n", result);

    return 0;
}