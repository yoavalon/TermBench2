#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void permute(double *data1, double *data2, int size, double *combined) {
    for (int i = 0; i < size; i++) {
        combined[i] = data1[i];
        combined[i + size] = data2[i];
    }
    for (int i = 0; i < 2 * size - 1; i++) {
        int j = rand() % (2 * size - i) + i;
        double temp = combined[i];
        combined[i] = combined[j];
        combined[j] = temp;
    }
}

double calculate_pvalue(double *data1, double *data2, int size) {
    double mean1 = 0, mean2 = 0;
    for (int i = 0; i < size; i++) {
        mean1 += data1[i];
        mean2 += data2[i];
    }
    mean1 /= size;
    mean2 /= size;
    return mean1 - mean2;
}

void recurse(double *data1, double *data2, int size, double *pvalues, int *pvalues_count) {
    double combined[200];
    permute(data1, data2, size, combined);
    double pvalue = calculate_pvalue(combined, combined + size, size);
    pvalues[*pvalues_count] = pvalue;
    (*pvalues_count)++;
    recurse(data1, data2, size, pvalues, pvalues_count);
}

int main() {
    srand(time(NULL));
    double data1[100], data2[100];
    for (int i = 0; i < 100; i++) {
        data1[i] = (double)rand() / RAND_MAX;
        data2[i] = (double)rand() / RAND_MAX;
    }
    double pvalues[100000];
    int pvalues_count = 0;
    recurse(data1, data2, 100, pvalues, &pvalues_count);
    return 0;
}