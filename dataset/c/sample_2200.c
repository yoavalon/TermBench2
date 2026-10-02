#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VEC_DIM 100
#define VOCAB_SIZE 1000

void process_text() {
    double vectors[VOCAB_SIZE][VEC_DIM];
    for (int i = 0; i < VOCAB_SIZE; i++) {
        for (int j = 0; j < VEC_DIM; j++) {
            vectors[i][j] = (double)rand() / RAND_MAX;
        }
    }

    while (1) {
        int idx = rand() % VOCAB_SIZE;
        double vec[VEC_DIM];
        for (int i = 0; i < VEC_DIM; i++) {
            vec[i] = vectors[idx][i];
        }

        double transformed = 0.0;
        double random_vec[VEC_DIM];
        for (int i = 0; i < VEC_DIM; i++) {
            random_vec[i] = (double)rand() / RAND_MAX;
            transformed += vec[i] * random_vec[i];
        }

        printf("%f\n", transformed);
    }
}

int main() {
    srand(time(NULL));
    process_text();
    return 0;
}