#include <stdio.h>
#include <stdlib.h>

void optimize_supply_chain(double data[2][2], double epsilon, double result[2][2]) {
    double a[2][2] = { {data[0][0], data[0][1]}, {data[1][0], data[1][1]} };
    double aT_a[2][2], aT_a_plus_epsilonI[2][2], b[2][2], c[2][2];
    double det, inv_det;

    // Calculate a.T @ a
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            aT_a[i][j] = a[j][0] * a[i][0] + a[j][1] * a[i][1];
        }
    }

    // Calculate a.T @ a + epsilon * I
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            aT_a_plus_epsilonI[i][j] = aT_a[i][j] + (i == j ? epsilon : 0);
        }
    }

    // Calculate inverse of a.T @ a + epsilon * I
    det = aT_a_plus_epsilonI[0][0] * aT_a_plus_epsilonI[1][1] - aT_a_plus_epsilonI[0][1] * aT_a_plus_epsilonI[1][0];
    inv_det = 1.0 / det;
    b[0][0] = aT_a_plus_epsilonI[1][1] * inv_det;
    b[0][1] = -aT_a_plus_epsilonI[0][1] * inv_det;
    b[1][0] = -aT_a_plus_epsilonI[1][0] * inv_det;
    b[1][1] = aT_a_plus_epsilonI[0][0] * inv_det;

    // Calculate b @ a.T
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c[i][j] = b[i][0] * a[0][j] + b[i][1] * a[1][j];
        }
    }

    // Copy result
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = c[i][j];
        }
    }
}

int main() {
    double data[2][2] = { {1.0001, 2.0002}, {3.0003, 4.0004} };
    double epsilon = 0.0001;
    double result[2][2];

    optimize_supply_chain(data, epsilon, result);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%f ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}