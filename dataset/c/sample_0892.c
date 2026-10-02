#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define RANDOM(a, b) ((a) + ((b) - (a)) * (rand() / (double)RAND_MAX))

double sphere_function(double *x, int dimensions) {
    double sum = 0.0;
    for (int i = 0; i < dimensions; i++) {
        sum += x[i] * x[i];
    }
    return sum;
}

double** initialize_particles(int size, int dimensions, double lower_bound, double upper_bound) {
    double **particles = (double **)malloc(size * sizeof(double *));
    for (int i = 0; i < size; i++) {
        particles[i] = (double *)malloc(dimensions * sizeof(double));
        for (int j = 0; j < dimensions; j++) {
            particles[i][j] = RANDOM(lower_bound, upper_bound);
        }
    }
    return particles;
}

double* evaluate_fitness(double **particles, int size, double (*objective_function)(double *, int), int dimensions) {
    double *fitness = (double *)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        fitness[i] = objective_function(particles[i], dimensions);
    }
    return fitness;
}

double** update_particles(double **particles, double **velocities, double **pbest, double *gbest, int size, int dimensions, double w, double c1, double c2) {
    double **new_particles = (double **)malloc(size * sizeof(double *));
    for (int i = 0; i < size; i++) {
        new_particles[i] = (double *)malloc(dimensions * sizeof(double));
        double r1 = RANDOM(0.0, 1.0);
        double r2 = RANDOM(0.0, 1.0);
        for (int d = 0; d < dimensions; d++) {
            velocities[i][d] = w * velocities[i][d] + c1 * r1 * (pbest[i][d] - particles[i][d]) + c2 * r2 * (gbest[d] - particles[i][d]);
            new_particles[i][d] = particles[i][d] + velocities[i][d];
        }
    }
    return new_particles;
}

double* optimize(double (*objective_function)(double *, int), int dimensions, double bounds[2], int size, int iterations, double w, double c1, double c2) {
    double **particles = initialize_particles(size, dimensions, bounds[0], bounds[1]);
    double **velocities = (double **)malloc(size * sizeof(double *));
    for (int i = 0; i < size; i++) {
        velocities[i] = (double *)calloc(dimensions, sizeof(double));
    }
    double **pbest = initialize_particles(size, dimensions, bounds[0], bounds[1]);
    double *pbest_fitness = evaluate_fitness(pbest, size, objective_function, dimensions);
    double *gbest = (double *)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        gbest[i] = pbest[0][i];
    }
    double gbest_fitness = pbest_fitness[0];
    for (int iter = 0; iter < iterations; iter++) {
        double **new_particles = update_particles(particles, velocities, pbest, gbest, size, dimensions, w, c1, c2);
        double *fitness = evaluate_fitness(new_particles, size, objective_function, dimensions);
        for (int i = 0; i < size; i++) {
            if (fitness[i] < pbest_fitness[i]) {
                for (int d = 0; d < dimensions; d++) {
                    pbest[i][d] = new_particles[i][d];
                }
                pbest_fitness[i] = fitness[i];
            }
        }
        if (min(fitness, size) < gbest_fitness) {
            for (int d = 0; d < dimensions; d++) {
                gbest[d] = new_particles[index_of_min(fitness, size)][d];
            }
            gbest_fitness = min(fitness, size);
        }
        for (int i = 0; i < size; i++) {
            free(particles[i]);
        }
        free(particles);
        particles = new_particles;
    }
    double *result = (double *)malloc((dimensions + 1) * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        result[i] = gbest[i];
    }
    result[dimensions] = gbest_fitness;
    return result;
}

double min(double *array, int size) {
    double min_value = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min_value) {
            min_value = array[i];
        }
    }
    return min_value;
}

int index_of_min(double *array, int size) {
    int min_index = 0;
    for (int i = 1; i < size; i++) {
        if (array[i] < array[min_index]) {
            min_index = i;
        }
    }
    return min_index;
}

int main() {
    srand(time(NULL));
    int dimensions = 2;
    double bounds[2] = {-10.0, 10.0};
    int size = 30;
    int iterations = 100;
    double w = 0.7;
    double c1 = 1.5;
    double c2 = 1.5;
    double *best_solution = optimize(sphere_function, dimensions, bounds, size, iterations, w, c1, c2);
    printf("Best solution: ");
    for (int i = 0; i < dimensions; i++) {
        printf("%f ", best_solution[i]);
    }
    printf("\nBest fitness: %f\n", best_solution[dimensions]);
    return 0;
}