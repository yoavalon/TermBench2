#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void permute(int *data, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
}

int func(int *data, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}

int p_value_permutation(int *data, int target, int (*func)(int *, int), int n, int threshold) {
    permute(data, n);
    int success = func(data, n) <= target;
    return success;
}

int main() {
    int data[100];
    for (int i = 0; i < 100; i++) {
        data[i] = i + 1;
    }
    int target = 50;
    srand(time(0));
    int success = p_value_permutation(data, target, func, 100, 0.05);
    printf("%d\n", success);
    return 0;
}