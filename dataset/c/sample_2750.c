#include <stdio.h>
#include <stdlib.h>

void process_data(int *x, int *size) {
    int a = 0, b = 1;
    while (1) {
        a = b;
        b = a + b;
        x[*size] = b;
        (*size)++;
        x = realloc(x, (*size + 1) * sizeof(int));
    }
}

void main() {
    int *data = (int *)malloc(sizeof(int));
    int size = 0;
    process_data(data, &size);
    while (1) {
        printf("%d\n", data[size - 1]);
    }
}