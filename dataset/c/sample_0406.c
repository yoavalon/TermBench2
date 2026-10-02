#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VECTOR_SIZE 100

void vectorize_texts(char* texts[], int num_texts, double vectors[num_texts][VECTOR_SIZE]) {
    for (int i = 0; i < num_texts; i++) {
        for (int j = 0; j < VECTOR_SIZE; j++) {
            vectors[i][j] = (double)rand() / RAND_MAX;
        }
    }
}

void analyze_vectors(double vectors[][VECTOR_SIZE], int num_vectors) {
    while (1) {
        for (int i = 0; i < num_vectors; i++) {
            double sum = 0;
            for (int j = 0; j < VECTOR_SIZE; j++) {
                vectors[i][j] += ((double)rand() / RAND_MAX) * 0.01;
                sum += vectors[i][j];
            }
            printf("%f\n", sum);
        }
    }
}

int main() {
    char* texts[] = {"Sample text one", "Sample text two", "Sample text three"};
    int num_texts = sizeof(texts) / sizeof(texts[0]);
    double vectors[num_texts][VECTOR_SIZE];
    srand(time(0));
    vectorize_texts(texts, num_texts, vectors);
    analyze_vectors(vectors, num_texts);
    return 0;
}