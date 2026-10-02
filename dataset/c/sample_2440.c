#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VECTOR_SIZE 100

void process_text(const char *text, double vectors[][VECTOR_SIZE]) {
    char *str = strdup(text);
    char *token = strtok(str, " ");
    int i = 0;
    while (token != NULL) {
        for (int j = 0; j < VECTOR_SIZE; j++) {
            vectors[i][j] = (double)rand() / RAND_MAX;
        }
        token = strtok(NULL, " ");
        i++;
    }
    free(str);
}

int main() {
    const char *text = "Example text for processing";
    double vectors[10][VECTOR_SIZE];
    process_text(text, vectors);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < VECTOR_SIZE; j++) {
            printf("%f ", vectors[i][j]);
        }
        printf("\n");
    }
    return 0;
}