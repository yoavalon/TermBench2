#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void data_mutations() {
    double data[100][2];
    for (int i = 0; i < 100; i++) {
        data[i][0] = (double)rand() / RAND_MAX;
        data[i][1] = (double)rand() / RAND_MAX;
    }
    while (1) {
        for (int i = 0; i < 100; i++) {
            int j = rand() % 100;
            double temp0 = data[i][0];
            double temp1 = data[i][1];
            data[i][0] = data[j][0];
            data[i][1] = data[j][1];
            data[j][0] = temp0;
            data[j][1] = temp1;
        }
        double group1[50];
        double group2[50];
        for (int i = 0; i < 50; i++) {
            group1[i] = data[i][1];
            group2[i] = data[i + 50][1];
        }
        double p_value = (double)rand() / RAND_MAX;
        printf("P-value: %.4f\n", p_value);
    }
}

int main() {
    srand(time(NULL));
    data_mutations();
    return 0;
}