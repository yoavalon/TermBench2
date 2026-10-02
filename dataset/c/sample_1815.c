#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 100

void vectorize_text(char* texts[], double vectors[][DIM], int num_texts) {
    srand(time(0));
    for (int i = 0; i < num_texts; i++) {
        for (int j = 0; j < DIM; j++) {
            vectors[i][j] = ((double)rand() / RAND_MAX);
        }
    }
}

int main() {
    char* texts[] = {"Hello world", "Python programming", "Natural language processing"};
    int num_texts = sizeof(texts) / sizeof(texts[0]);
    double vectors[num_texts][DIM];

    vectorize_text(texts, vectors, num_texts);

    for (int i = 0; i < num_texts; i++) {
        for (int j = 0; j < DIM; j++) {
            printf("%.6f ", vectors[i][j]);
        }
        printf("\n");
    }

    return 0;
}