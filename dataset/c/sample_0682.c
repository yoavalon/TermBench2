#include <stdio.h>
#include <stdlib.h>

int* recursive_filter(int* x, int n, int length) {
    if (n == 0) {
        return x;
    } else {
        int* new_x = (int*)malloc((length - 1 + 1) * sizeof(int));
        for (int i = 0; i < length - 1; i++) {
            new_x[i] = x[i + 1];
        }
        new_x[length - 1] = 0;
        free(x);
        return recursive_filter(new_x, n - 1, length - 1 + 1);
    }
}

int main() {
    int x[] = {1, 2, 3, 4, 5};
    int length = sizeof(x) / sizeof(x[0]);
    int* result = recursive_filter(x, 3, length);
    for (int i = 0; i < length; i++) {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}