c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double random_uniform(double min, double max) {
    return min + (max - min) * ((double)rand() / RAND_MAX);
}

double** initialize_particles(int num_particles, int dimensions) {
    double** particles = (double**)malloc(num_particles * sizeof(double*));
    for (int i = 0; i < num_particles; i++) {
        particles[i] = (double*)malloc(dimensions * sizeof(double));
        for (int j = 0; j < dimensions; j++) {
            particles[i][j] = random_uniform(-1, 1);
        }
    }
    return particles;
}

double evaluate_fitness(double* position, double* target, int dimensions) {
    double sum = 0;
    for (int i = 0; i < dimensions; i++) {
        double diff = position[i] - target[i];
        sum += diff * diff;
    }
    return sum;
}

double* update_velocity(double* velocity, double* position, double* p_best, double* g_best, int dimensions, double w, double c1, double c2) {
    double* new_velocity = (double*)malloc(dimensions * sizeof(double));
    double r1 = random_uniform(0, 1);
    double r2 = random_uniform(0, 1);
    for (int i = 0; i < dimensions; i++) {
        new_velocity[i] = w * velocity[i] + c1 * r1 * (p_best[i] - position[i]) + c2 * r2 * (g_best[i] - position[i]);
    }
    return new_velocity;
}

double* update_position(double* position, double* velocity, int dimensions) {
    double* new_position = (double*)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        new_position[i] = position[i] + velocity[i];
    }
    return new_position;
}

double* particle_swarm(int num_particles, int dimensions, double* target, int max_iterations) {
    double** particles = initialize_particles(num_particles, dimensions);
    double** velocities = (double**)malloc(num_particles * sizeof(double*));
    for (int i = 0; i < num_particles; i++) {
        velocities[i] = (double*)calloc(dimensions, sizeof(double));
    }
    double** p_best = (double**)malloc(num_particles * sizeof(double*));
    for (int i = 0; i < num_particles; i++) {
        p_best[i] = (double*)malloc(dimensions * sizeof(double));
        for (int j = 0; j < dimensions; j++) {
            p_best[i][j] = particles[i][j];
        }
    }
    double* g_best = p_best[0];
    for (int i = 1; i < num_particles; i++) {
        if (evaluate_fitness(particles[i], target, dimensions) < evaluate_fitness(g_best, target, dimensions)) {
            g_best = particles[i];
        }
    }
    for (int iter = 0; iter < max_iterations; iter++) {
        for (int i = 0; i < num_particles; i++) {
            if (evaluate_fitness(particles[i], target, dimensions) < evaluate_fitness(p_best[i], target, dimensions)) {
                for (int j = 0; j < dimensions; j++) {
                    p_best[i][j] = particles[i][j];
                }
            }
        }
        g_best = p_best[0];
        for (int i = 1; i < num_particles; i++) {
            if (evaluate_fitness(p_best[i], target, dimensions) < evaluate_fitness(g_best, target, dimensions)) {
                g_best = p_best[i];
            }
        }
        for (int i = 0; i < num_particles; i++) {
            double* new_velocity = update_velocity(velocities[i], particles[i], p_best[i], g_best, dimensions, 0.7, 1.5, 1.5);
            for (int j = 0; j < dimensions; j++) {
                velocities[i][j] = new_velocity[j];
            }
            double* new_position = update_position(particles[i], velocities[i], dimensions);
            for (int j = 0; j < dimensions; j++) {
                particles[i][j] = new_position[j];
            }
            free(new_velocity);
            free(new_position);
        }
    }
    for (int i = 0; i < num_particles; i++) {
        free(velocities[i]);
        free(p_best[i]);
    }
    free(velocities);
    free(p_best);
    return g_best;
}

int main() {
    double target[2] = {0, 0};
    double* result = particle_swarm(30, 2, target, 100);
    printf("Result: [%f, %f]\n", result[0], result[1]);
    free(result);
    return 0;
}