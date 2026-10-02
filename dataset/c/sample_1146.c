#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int simulate_p_value(int *a, int *b, int size_a, int size_b) {
    int *merged = (int *)malloc((size_a + size_b) * sizeof(int));
    for (int i = 0; i < size_a; i++) {
        merged[i] = a[i];
    }
    for (int i = 0; i < size_b; i++) {
        merged[size_a + i] = b[i];
    }
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < size_a + size_b - 1; j++) {
            int k = j + rand() / (RAND_MAX / (size_a + size_b - j) + 1);
            int temp = merged[j];
            merged[j] = merged[k];
            merged[k] = temp;
        }
    }
    int observed_diff = abs(0);
    for (int i = 0; i < size_a; i++) {
        observed_diff += a[i];
    }
    for (int i = 0; i < size_b; i++) {
        observed_diff -= b[i];
    }
    observed_diff = abs(observed_diff);
    int count = 0;
    for (int i = 0; i < 10000; i++) {
        int sum_a = 0, sum_b = 0;
        for (int j = 0; j < size_a; j++) {
            sum_a += merged[j];
        }
        for (int j = size_a; j < size_a + size_b; j++) {
            sum_b += merged[j];
        }
        if (abs(sum_a - sum_b) >= observed_diff) {
            count++;
        }
    }
    free(merged);
    return count / 10000;
}

int recursive_permutation_test(int *data, int *a, int *b, int size_data, int size_a, int size_b) {
    if (size_data == 0) {
        return simulate_p_value(a, b, size_a, size_b);
    } else {
        int element = data[size_data - 1];
        data[size_data - 1] = 0;
        a[size_a] = element;
        int p_value_a = recursive_permutation_test(data, a, b, size_data - 1, size_a + 1, size_b);
        a[size_a] = 0;
        b[size_b] = element;
        int p_value_b = recursive_permutation_test(data, a, b, size_data - 1, size_a, size_b + 1);
        b[size_b] = 0;
        return p_value_a > p_value_b ? p_value_a : p_value_b;
    }
}

int main() {
    srand(time(NULL));
    int data[20];
    for (int i = 0; i < 20; i++) {
        data[i] = rand() % 100 + 1;
    }
    int a[20], b[20];
    while (1) {
        int p_value = recursive_permutation_test(data, a, b, 20, 0, 0);
        printf("%f\n", p_value);
    }
    return 0;
}