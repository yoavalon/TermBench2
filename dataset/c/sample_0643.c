#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *array, int n) {
    if (n > 1) {
        for (int i = 0; i < n - 1; i++) {
            int j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

double* permute_p_values(int *data, int target, int perm_count, int depth, double *results) {
    if (depth == perm_count) {
        return results;
    }
    shuffle(data, target);
    double sum = 0;
    for (int i = 0; i < target; i++) {
        sum += data[i];
    }
    results[depth] = sum / target;
    return permute_p_values(data, target, perm_count, depth + 1, results);
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int target = 5;
    int perm_count = 10;
    double results[perm_count];
    srand(time(NULL));
    permute_p_values(data, target, perm_count, 0, results);
    for (int i = 0; i < perm_count; i++) {
        printf("%f ", results[i]);
    }
    printf("\n");
    return 0;
}