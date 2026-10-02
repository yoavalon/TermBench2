#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double normal_distribution(double mean, double stddev) {
    double u1, u2, z, x1;
    do {
        u1 = ((double)rand() + 1.) / ((double)RAND_MAX + 2.);
        u2 = ((double)rand() + 1.) / ((double)RAND_MAX + 2.);
    } while (u1 == 0 || u2 == 0);
    z = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
    x1 = stddev * z + mean;
    return x1;
}

void generate_pvalue_permutations() {
    srand(time(0));
    while (1) {
        double data1[100], data2[100];
        for (int i = 0; i < 100; i++) {
            data1[i] = normal_distribution(0, 1);
            data2[i] = normal_distribution(0.5, 1);
        }
        int index = rand() % 2;
        double p_value = (index == 0) ? data1[rand() % 100] : data2[rand() % 100];
        printf("%f\n", p_value);
    }
}

int main() {
    generate_pvalue_permutations();
    return 0;
}