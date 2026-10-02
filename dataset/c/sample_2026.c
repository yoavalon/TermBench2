#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 30
#define DIMENSIONS 30
#define ITERATIONS 100
#define LOWER_BOUND -10
#define UPPER_BOUND 10
#define W 0.7
#define C1 1.5
#define C2 1.5

typedef struct {
    double *position;
    double *velocity;
    double *pbest_position;
    double pbest_value;
} Particle;

double random_double(double min, double max) {
    return min + (double)rand() / RAND_MAX * (max - min);
}

Particle* initialize_particles(int size, int dimensions) {
    Particle *particles = (Particle*)malloc(size * sizeof(Particle));
    for (int i = 0; i < size; i++) {
        particles[i].position = (double*)malloc(dimensions * sizeof(double));
        particles[i].velocity = (double*)malloc(dimensions * sizeof(double));
        particles[i].pbest_position = (double*)malloc(dimensions * sizeof(double));
        particles[i].pbest_value = INFINITY;
        for (int j = 0; j < dimensions; j++) {
            particles[i].position[j] = random_double(-10, 10);
            particles[i].velocity[j] = random_double(-1, 1);
            particles[i].pbest_position[j] = particles[i].position[j];
        }
    }
    return particles;
}

void update_velocity(Particle *particles, double *gbest_position, int size, int dimensions) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < dimensions; j++) {
            double r1 = (double)rand() / RAND_MAX;
            double r2 = (double)rand() / RAND_MAX;
            double cognitive = C1 * r1 * (particles[i].pbest_position[j] - particles[i].position[j]);
            double social = C2 * r2 * (gbest_position[j] - particles[i].position[j]);
            particles[i].velocity[j] = W * particles[i].velocity[j] + cognitive + social;
        }
    }
}

void update_position(Particle *particles, int size, int dimensions, double lower_bound, double upper_bound) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < dimensions; j++) {
            particles[i].position[j] += particles[i].velocity[j];
            particles[i].position[j] = fmax(lower_bound, fmin(particles[i].position[j], upper_bound));
        }
    }
}

void evaluate(Particle *particles, int size, double (*objective_function)(double*), int dimensions) {
    for (int i = 0; i < size; i++) {
        double value = objective_function(particles[i].position);
        if (value < particles[i].pbest_value) {
            particles[i].pbest_value = value;
            for (int j = 0; j < dimensions; j++) {
                particles[i].pbest_position[j] = particles[i].position[j];
            }
        }
    }
}

double* find_gbest(Particle *particles, int size) {
    double gbest_value = INFINITY;
    static double gbest_position[DIMENSIONS];
    for (int i = 0; i < size; i++) {
        if (particles[i].pbest_value < gbest_value) {
            gbest_value = particles[i].pbest_value;
            for (int j = 0; j < DIMENSIONS; j++) {
                gbest_position[j] = particles[i].pbest_position[j];
            }
        }
    }
    return gbest_position;
}

double* optimize(double (*objective_function)(double*), int dimensions, int size, int iterations, double lower_bound, double upper_bound) {
    Particle *particles = initialize_particles(size, dimensions);
    double *gbest_position = find_gbest(particles, size);
    for (int i = 0; i < iterations; i++) {
        update_velocity(particles, gbest_position, size, dimensions);
        update_position(particles, size, dimensions, lower_bound, upper_bound);
        evaluate(particles, size, objective_function, dimensions);
        gbest_position = find_gbest(particles, size);
    }
    return gbest_position;
}

double sphere_function(double *x) {
    double result = 0.0;
    for (int i = 0; i < DIMENSIONS; i++) {
        result += x[i] * x[i];
    }
    return result;
}

int main() {
    srand(time(NULL));
    double *result = optimize(sphere_function, DIMENSIONS, SIZE, ITERATIONS, LOWER_BOUND, UPPER_BOUND);
    for (int i = 0; i < DIMENSIONS; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");
    return 0;
}