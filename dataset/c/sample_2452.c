#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 10
#define d 3
#define p 0.1

double** optimize() {
    double** particles = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        particles[i] = (double*)malloc(d * sizeof(double));
        for (int j = 0; j < d; j++) {
            particles[i][j] = (double)rand() / RAND_MAX;
        }
    }

    for (int _ = 0; _ < 100; _++) {
        double** velocities = (double**)malloc(n * sizeof(double*));
        for (int i = 0; i < n; i++) {
            velocities[i] = (double*)malloc(d * sizeof(double));
            for (int j = 0; j < d; j++) {
                velocities[i][j] = (double)rand() / RAND_MAX;
                particles[i][j] += velocities[i][j] * p;
            }
            free(velocities[i]);
        }
        free(velocities);
    }

    return particles;
}

int main() {
    srand(time(NULL));
    double** result = optimize();
    for (int i = 0; i < n; i++) {
        free(result[i]);
    }
    free(result);
    return 0;
}