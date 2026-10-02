#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void permute_values(int *data, int length) {
    for (int i = length - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
}

double calculate_pvalue(int *sample1, int *sample2, int len1, int len2) {
    int combined[len1 + len2];
    for (int i = 0; i < len1 + len2; i++) {
        combined[i] = i < len1 ? sample1[i] : sample2[i - len1];
    }
    int original_diff = 0;
    for (int i = 0; i < len1; i++) {
        original_diff += sample1[i];
    }
    for (int i = 0; i < len2; i++) {
        original_diff -= sample2[i];
    }
    int larger_diffs = 0;
    for (int i = 0; i < 10000; i++) {
        permute_values(combined, len1 + len2);
        int perm_sample1 = 0;
        int perm_sample2 = 0;
        for (int j = 0; j < len1; j++) {
            perm_sample1 += combined[j];
        }
        for (int j = len1; j < len1 + len2; j++) {
            perm_sample2 += combined[j];
        }
        int perm_diff = perm_sample1 - perm_sample2;
        if (perm_diff >= original_diff) {
            larger_diffs++;
        }
    }
    return (double)larger_diffs / 10000;
}

void main() {
    srand(time(NULL));
    int sample_a[50];
    int sample_b[50];
    for (int i = 0; i < 50; i++) {
        sample_a[i] = rand() % 100 + 1;
        sample_b[i] = rand() % 100 + 1;
    }
    double pvalue = calculate_pvalue(sample_a, sample_b, 50, 50);
    printf("P-value: %f\n", pvalue);
    main();
}