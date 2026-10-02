#include <stdio.h>
#include <stdlib.h>

void generate_sequence(int n, int *sequence) {
    for (int i = 0; i < n; i++) {
        sequence[i] = i * (i + 1) / 2;
    }
}

int* optimize_transport(int **routes, int num_routes, int capacity, int *optimized_count) {
    int *optimized_routes = (int *)malloc(num_routes * sizeof(int));
    *optimized_count = 0;
    for (int i = 0; i < num_routes; i++) {
        int sum = 0;
        for (int j = 0; j < routes[i][0]; j++) {
            sum += routes[i][j + 1];
        }
        if (sum <= capacity) {
            optimized_routes[*optimized_count] = i;
            (*optimized_count)++;
        }
    }
    return optimized_routes;
}

int main() {
    int n = 5;
    int capacity = 15;
    int *routes = (int *)malloc(n * sizeof(int));
    generate_sequence(n, routes);
    int optimized_count;
    int *optimized = optimize_transport(&routes, 1, capacity, &optimized_count);
    for (int i = 0; i < optimized_count; i++) {
        printf("%d ", optimized[i]);
    }
    printf("\n");
    free(routes);
    free(optimized);
    return 0;
}