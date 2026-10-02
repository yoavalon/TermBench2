c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double *position;
    double *velocity;
    double *best_position;
} Particle;

double random_double() {
    return (double)rand() / RAND_MAX * 20 - 10;
}

Particle* initialize_particles(int dimensions, int population_size) {
    Particle *particles = (Particle*)malloc(population_size * sizeof(Particle));
    for (int i = 0; i < population_size; i++) {
        particles[i].position = (double*)malloc(dimensions * sizeof(double));
        particles[i].velocity = (double*)malloc(dimensions * sizeof(double));
        particles[i].best_position = (double*)malloc(dimensions * sizeof(double));
        for (int j = 0; j < dimensions; j++) {
            particles[i].position[j] = random_double();
            particles[i].velocity[j] = 0;
            particles[i].best_position[j] = particles[i].position[j];
        }
    }
    return particles;
}

void update_particles(Particle *particles, Particle global_best, int dimensions, int population_size) {
    for (int i = 0; i < population_size; i++) {
        for (int j = 0; j < dimensions; j++) {
            double r1 = (double)rand() / RAND_MAX;
            double r2 = (double)rand() / RAND_MAX;
            double cognitive_velocity = r1 * (particles[i].best_position[j] - particles[i].position[j]);
            double social_velocity = r2 * (global_best.position[j] - particles[i].position[j]);
            particles[i].velocity[j] = 0.7 * particles[i].velocity[j] + cognitive_velocity + social_velocity;
            particles[i].position[j] += particles[i].velocity[j];
        }
        if (evaluate(particles[i].position, dimensions) < evaluate(particles[i].best_position, dimensions)) {
            for (int j = 0; j < dimensions; j++) {
                particles[i].best_position[j] = particles[i].position[j];
            }
        }
    }
}

double evaluate(double *position, int dimensions) {
    double sum = 0;
    for (int i = 0; i < dimensions; i++) {
        sum += position[i] * position[i];
    }
    return sum;
}

Particle find_global_best(Particle *particles, int population_size, int dimensions) {
    Particle global_best = particles[0];
    for (int i = 1; i < population_size; i++) {
        if (evaluate(particles[i].position, dimensions) < evaluate(global_best.position, dimensions)) {
            global_best = particles[i];
        }
    }
    return global_best;
}

void free_particles(Particle *particles, int population_size) {
    for (int i = 0; i < population_size; i++) {
        free(particles[i].position);
        free(particles[i].velocity);
        free(particles[i].best_position);
    }
    free(particles);
}

int main() {
    int dimensions = 2;
    int population_size = 10;
    srand(time(NULL));
    Particle *particles = initialize_particles(dimensions, population_size);
    Particle global_best = find_global_best(particles, population_size, dimensions);
    while (1) {
        update_particles(particles, global_best, dimensions, population_size);
        global_best = find_global_best(particles, population_size, dimensions);
    }
    free_particles(particles, population_size);
    return 0;
}