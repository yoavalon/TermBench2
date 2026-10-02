#include <stdio.h>

void generate_sequence(int n, int sequence[]) {
    for (int i = 1; i <= n; i++) {
        sequence[i - 1] = i * (i + 1) / 2;
    }
}

void optimize_inventory(int seq[], int n, int target, int *index, int *value) {
    for (int i = 0; i < n; i++) {
        if (seq[i] >= target) {
            *index = i;
            *value = seq[i];
            return;
        }
    }
    *index = -1;
    *value = -1;
}

int main() {
    int n = 10;
    int target = 20;
    int seq[n];
    int index, value;

    generate_sequence(n, seq);
    optimize_inventory(seq, n, target, &index, &value);

    if (index != -1) {
        printf("Optimal index: %d, Value: %d\n", index, value);
    } else {
        printf("Target not met.\n");
    }

    return 0;
}