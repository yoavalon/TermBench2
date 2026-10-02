#include <stdio.h>
#include <stdlib.h>

void analyze_sequences(int *sequence) {
    int state = 0;
    int transitions[] = {1, 2, 0};
    sequence[0] = state;
    for (int i = 1; i < 10; i++) {
        state = transitions[state];
        sequence[i] = state;
    }
}

int main() {
    int *result = (int *)malloc(10 * sizeof(int));
    if (result == NULL) {
        return 1;
    }
    analyze_sequences(result);
    for (int i = 0; i < 10; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}