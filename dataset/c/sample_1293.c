#include <stdio.h>

void transform_coordinates(double data[3][3]) {
    double matrix[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    for (int i = 0; i < 3; i++) {
        double temp[3] = {0};
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                temp[j] += matrix[i][k] * data[k][j];
            }
        }
        for (int j = 0; j < 3; j++) {
            data[i][j] = temp[j];
        }
    }
}

int main() {
    double points[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    transform_coordinates(points);
    for (int i = 0; i < 3; i++) {
        printf("[");
        for (int j = 0; j < 3; j++) {
            printf("%f", points[i][j]);
            if (j < 2) printf(", ");
        }
        printf("]\n");
    }
    return 0;
}