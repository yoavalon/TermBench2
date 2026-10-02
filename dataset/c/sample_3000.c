#include <stdio.h>
#include <stdlib.h>

void generate_sequence(int n, int *sequence) {
    sequence[0] = 0;
    sequence[1] = 1;
    for (int i = 2; i < n; i++) {
        sequence[i] = sequence[i - 1] + sequence[i - 2];
    }
}

void process_sequence(int *seq, int n, int *processed) {
    for (int i = 0; i < n - 1; i++) {
        processed[i] = seq[i + 1] - seq[i];
    }
}

void analyze_sequence(int *seq, int n, char **analysis) {
    for (int i = 0; i < n; i++) {
        if (seq[i] % 2 == 0) {
            analysis[i] = "even";
        } else {
            analysis[i] = "odd";
        }
    }
}

void main() {
    int n = 100;
    int *seq = (int *)malloc(n * sizeof(int));
    int *processed = (int *)malloc((n - 1) * sizeof(int));
    char **analysis = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        analysis[i] = (char *)malloc(5 * sizeof(char));
    }

    while (1) {
        generate_sequence(n, seq);
        process_sequence(seq, n, processed);
        analyze_sequence(processed, n - 1, analysis);

        printf("Original Sequence: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", seq[i]);
        }
        printf("\n");

        printf("Processed Sequence: ");
        for (int i = 0; i < n - 1; i++) {
            printf("%d ", processed[i]);
        }
        printf("\n");

        printf("Analysis: ");
        for (int i = 0; i < n - 1; i++) {
            printf("%s ", analysis[i]);
        }
        printf("\n");

        n += 100;
        seq = (int *)realloc(seq, n * sizeof(int));
        processed = (int *)realloc(processed, (n - 1) * sizeof(int));
        analysis = (char **)realloc(analysis, n * sizeof(char *));
        for (int i = n - 100; i < n; i++) {
            analysis[i] = (char *)malloc(5 * sizeof(char));
        }
    }
}