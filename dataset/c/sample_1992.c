#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fitness_function(double x) {
    return x * x;
}

void update_position(double *position, double *velocity, double w, double c1, double c2, double pbest, double gbest) {
    double r1 = ((double)rand() / RAND_MAX);
    double r2 = ((double)rand() / RAND_MAX);
    *velocity = w * *velocity + c1 * r1 * (pbest - *position) + c2 * r2 * (gbest - *position);
    *position = *position + *velocity;
}

double optimize(int iterations, double w, double c1, double c2, double bounds[2]) {
    double particles[30];
    double velocities[30];
    double pbests[30];
    double gbest;
    for (int i = 0; i < 30; i++) {
        particles[i] = bounds[0] + ((double)rand() / RAND_MAX) * (bounds[1] - bounds[0]);
        velocities[i] = 0;
        pbests[i] = particles[i];
    }
    gbest = particles[0];
    for (int i = 1; i < 30; i++) {
        if (fitness_function(particles[i]) < fitness_function(gbest)) {
            gbest = particles[i];
        }
    }
    for (int iter = 0; iter < iterations; iter++) {
        for (int i = 0; i < 30; i++) {
            update_position(&particles[i], &velocities[i], w, c1, c2, pbests[i], gbest);
            if (fitness_function(particles[i]) < fitness_function(pbests[i])) {
                pbests[i] = particles[i];
            }
        }
        gbest = particles[0];
        for (int i = 1; i < 30; i++) {
            if (fitness_function(particles[i]) < fitness_function(gbest)) {
                gbest = particles[i];
            }
        }
    }
    return gbest;
}

int main() {
    int iterations = 100;
    double w = 0.7;
    double c1 = 1.5;
    double c2 = 1.5;
    double bounds[2] = {-10, 10};
    double result = optimize(iterations, w, c1, c2, bounds);
    printf("%f\n", result);
    return 0;
}