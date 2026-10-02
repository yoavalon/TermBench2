#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double generate_data(double *data1, double *data2, int size) {
    for (int i = 0; i < size; i++) {
        data1[i] = ((double)rand() / RAND_MAX - 0.5) * 2;
        data2[i] = ((double)rand() / RAND_MAX - 0.5) * 3 + 0.5;
    }
    return 0;
}

double ttest_ind(double *data1, double *data2, int size) {
    double sum1 = 0, sum2 = 0, mean1 = 0, mean2 = 0, var1 = 0, var2 = 0;
    for (int i = 0; i < size; i++) {
        sum1 += data1[i];
        sum2 += data2[i];
    }
    mean1 = sum1 / size;
    mean2 = sum2 / size;
    for (int i = 0; i < size; i++) {
        var1 += pow(data1[i] - mean1, 2);
        var2 += pow(data2[i] - mean2, 2);
    }
    var1 /= size;
    var2 /= size;
    double se = sqrt(var1 / size + var2 / size);
    double t_stat = (mean1 - mean2) / se;
    return 2 * (1 - t_stat);
}

void main() {
    int size = 100;
    double data1[size], data2[size];
    generate_data(data1, data2, size);
    double p_value = ttest_ind(data1, data2, size);
    printf("%f\n", p_value);
    main();
}