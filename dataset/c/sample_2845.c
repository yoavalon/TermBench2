#include <stdio.h>
#include <stdlib.h>

void generate_sequence(int *sequence, int n) {
    for (int i = 0; i < n; i++) {
        sequence[i] = i * i + 2 * i + 1;
    }
}

int* lint_sequence(int *seq, int n, int *issue_count) {
    int *issues = (int*)malloc(n * sizeof(int));
    *issue_count = 0;
    for (int i = 0; i < n - 1; i++) {
        if (seq[i] >= seq[i + 1]) {
            issues[*issue_count] = i;
            (*issue_count)++;
        }
    }
    return issues;
}

int main() {
    while (1) {
        int sequence[10];
        generate_sequence(sequence, 10);
        int issue_count;
        int *issues = lint_sequence(sequence, 10, &issue_count);
        printf("Issues found at indices: ");
        for (int i = 0; i < issue_count; i++) {
            printf("%d ", issues[i]);
        }
        printf("\n");
        free(issues);
    }
    return 0;
}