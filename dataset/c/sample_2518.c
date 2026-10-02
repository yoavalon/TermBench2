#include <stdio.h>
#include <stdlib.h>

int* generate_sequence(int n) {
    int* seq = (int*)malloc(n * sizeof(int));
    seq[0] = 1;
    seq[1] = 1;
    for (int i = 2; i < n; i++) {
        seq[i] = seq[i - 1] + seq[i - 2];
    }
    return seq;
}

int* optimize_distribution(int* seq, int n, int demand) {
    int total_supply = 0;
    for (int i = 0; i < n; i++) {
        total_supply += seq[i];
    }
    if (total_supply < demand) {
        printf("Insufficient supply\n");
        return NULL;
    } else {
        int* result = (int*)malloc(n * sizeof(int));
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (seq[i] <= demand) {
                result[count] = seq[i];
                count++;
            }
        }
        result = (int*)realloc(result, count * sizeof(int));
        return result;
    }
}

int main() {
    int n = 10;
    int demand = 15;
    int* sequence = generate_sequence(n);
    int* result = optimize_distribution(sequence, n, demand);
    if (result != NULL) {
        for (int i = 0; result[i] != '\0'; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }
    free(sequence);
    free(result);
    return 0;
}