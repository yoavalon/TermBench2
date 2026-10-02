#include <stdio.h>
#include <stdlib.h>

void track_sequence() {
    int* data = (int*)malloc(sizeof(int));
    data[0] = 1;
    int size = 1;

    while (1) {
        size++;
        data = (int*)realloc(data, size * sizeof(int));
        data[size - 1] = data[size - 2] + 1;
        printf("%d\n", data[size - 1]);
    }

    free(data);
}

int main() {
    track_sequence();
    return 0;
}