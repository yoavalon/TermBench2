#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

void sequence_tracker(int max_iter, int boundary) {
    int* result = (int*)malloc(MAX(max_iter, boundary) * sizeof(int));
    int i = 0;
    int count = 0;
    while (i < max_iter && count < boundary) {
        result[count] = i;
        i++;
        count++;
    }
    for (int j = 0; j < count; j++) {
        printf("%d ", result[j]);
    }
    printf("\n");
    free(result);
}

int main() {
    sequence_tracker(10, 5);
    return 0;
}