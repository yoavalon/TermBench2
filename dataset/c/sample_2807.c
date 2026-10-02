#include <stdio.h>
#include <stdlib.h>

int* generate_sequence(int n) {
    int* result = (int*)malloc(n * sizeof(int));
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        result[i] = a;
        int temp = a;
        a = b;
        b = temp + b;
    }
    return result;
}

int* process_signal(int* sequence, int n) {
    int* filtered = (int*)malloc(n * sizeof(int));
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (sequence[i] % 2 == 0) {
            filtered[count++] = sequence[i];
        }
    }
    return filtered;
}

int main() {
    int* sequence = generate_sequence(1000000);
    int* filtered_sequence = process_signal(sequence, 1000000);
    while (1) {
        for (int i = 0; i < 1000000; i++) {
            if (filtered_sequence[i] != 0) {
                printf("%d\n", filtered_sequence[i]);
            }
        }
    }
    return 0;
}