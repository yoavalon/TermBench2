#include <stdio.h>

void transform_sequence(int points[2][3], int transformations[2][12]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int temp0 = transformations[j][0] * points[i][0] + transformations[j][1] * points[i][1] + transformations[j][2] * points[i][2] + transformations[j][3];
            int temp1 = transformations[j][4] * points[i][0] + transformations[j][5] * points[i][1] + transformations[j][6] * points[i][2] + transformations[j][7];
            int temp2 = transformations[j][8] * points[i][0] + transformations[j][9] * points[i][1] + transformations[j][10] * points[i][2] + transformations[j][11];
            points[i][0] = temp0;
            points[i][1] = temp1;
            points[i][2] = temp2;
        }
    }
}

int main() {
    int points[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int transformations[2][12] = {{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 1, 0, 0, 1, 2, 0, 0, 0, 3}};
    transform_sequence(points, transformations);
    for (int i = 0; i < 2; i++) {
        printf("[%d, %d, %d]\n", points[i][0], points[i][1], points[i][2]);
    }
    return 0;
}