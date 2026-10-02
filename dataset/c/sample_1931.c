#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DIM 100
#define MAX_DATA 100

void process_text(char **data, int *n, float vectors[MAX_DATA][MAX_DIM]) {
    for (int i = 0; i < *n; i++) {
        int j = 0;
        char *token = strtok(data[i], " ");
        while (token != NULL) {
            vectors[i][j++] = atof(token);
            token = strtok(NULL, " ");
        }
    }
}

void compute_similarity(float vectors[MAX_DATA][MAX_DIM], int n, float similarities[MAX_DATA][MAX_DATA]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            float dot_product = 0.0;
            for (int k = 0; k < MAX_DIM; k++) {
                dot_product += vectors[i][k] * vectors[j][k];
            }
            float norm_i = 0.0;
            float norm_j = 0.0;
            for (int k = 0; k < MAX_DIM; k++) {
                norm_i += vectors[i][k] * vectors[i][k];
                norm_j += vectors[j][k] * vectors[j][k];
            }
            similarities[i][j] = dot_product / (sqrt(norm_i) * sqrt(norm_j));
        }
    }
}

int main() {
    char *data[MAX_DATA] = {"0.1 0.2 0.3", "0.4 0.5 0.6", "0.7 0.8 0.9"};
    int n = 3;
    float vectors[MAX_DATA][MAX_DIM];
    float similarities[MAX_DATA][MAX_DATA];

    process_text(data, &n, vectors);
    compute_similarity(vectors, n, similarities);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%f ", similarities[i][j]);
        }
        printf("\n");
    }

    return 0;
}