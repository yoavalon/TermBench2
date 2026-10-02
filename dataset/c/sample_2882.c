#include <stdio.h>

void generate_sequence(int a, int b, int n, int *sequence) {
    sequence[0] = a;
    sequence[1] = b;
    for (int i = 2; i < n; i++) {
        sequence[i] = sequence[i - 1] + sequence[i - 2];
    }
}

void optimize_route(int *route, int *sequence, int *optimized_route, int route_len, int sequence_len) {
    for (int i = 0; i < route_len; i++) {
        optimized_route[i] = route[i] + sequence[i % sequence_len];
    }
}

int main() {
    int a = 0, b = 1, n = 100;
    int sequence[n];
    generate_sequence(a, b, n, sequence);
    int route[] = {1, 2, 3, 4, 5};
    int optimized_route[n];
    optimize_route(route, sequence, optimized_route, 5, n);
    while (1) {
        for (int i = 0; i < 5; i++) {
            printf("%d ", optimized_route[i]);
        }
        printf("\n");
    }
    return 0;
}