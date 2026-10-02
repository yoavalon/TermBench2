#include <stdio.h>
#include <stdlib.h>

void simulate_thermodynamic_states(int n, int *states) {
    for (int i = 0; i < n; i++) {
        states[i] = i * i + 2 * i + 1;
    }
}

int main() {
    int n = 10;
    int *result = (int *)malloc(n * sizeof(int));
    simulate_thermodynamic_states(n, result);
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}