#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Particle {
    double *position;
    double *velocity;
    double *best_position;
    double best_value;
} Particle;

typedef struct Swarm {
    int size;
    int dimensions;
    Particle *particles;
    double *best_position;
    double best_value;
} Swarm;

void initialize_particle(Particle *particle, int dimensions) {
    particle->position = (double *)malloc(dimensions * sizeof(double));
    particle->velocity = (double *)malloc(dimensions * sizeof(double));
    particle->best_position = (double *)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        particle->position[i] = ((double)rand() / RAND_MAX) * 20 - 10;
        particle->velocity[i] = ((double)rand() / RAND_MAX) * 2 - 1;
        particle->best_position[i] = particle->position[i];
    }
    particle->best_value = 0;
    for (int i = 0; i < dimensions; i++) {
        particle->best_value += particle->position[i] * particle->position[i];
    }
}

void initialize_swarm(Swarm *swarm, int size, int dimensions) {
    swarm->size = size;
    swarm->dimensions = dimensions;
    swarm->particles = (Particle *)malloc(size * sizeof(Particle));
    for (int i = 0; i < size; i++) {
        initialize_particle(&swarm->particles[i], dimensions);
    }
    swarm->best_position = (double *)malloc(dimensions * sizeof(double));
    swarm->best_value = INFINITY;
    for (int i = 0; i < size; i++) {
        if (swarm->particles[i].best_value < swarm->best_value) {
            swarm->best_value = swarm->particles[i].best_value;
            for (int j = 0; j < dimensions; j++) {
                swarm->best_position[j] = swarm->particles[i].best_position[j];
            }
        }
    }
}

void update_best(Swarm *swarm) {
    for (int i = 0; i < swarm->size; i++) {
        if (swarm->particles[i].best_value < swarm->best_value) {
            swarm->best_value = swarm->particles[i].best_value;
            for (int j = 0; j < swarm->dimensions; j++) {
                swarm->best_position[j] = swarm->particles[i].best_position[j];
            }
        }
    }
}

void optimize(Swarm *swarm, int iterations) {
    for (int iter = 0; iter < iterations; iter++) {
        for (int i = 0; i < swarm->size; i++) {
            double w = 0.7;
            double c1 = 1.5;
            double c2 = 1.5;
            Particle *particle = &swarm->particles[i];
            for (int j = 0; j < swarm->dimensions; j++) {
                double r1 = ((double)rand() / RAND_MAX);
                double r2 = ((double)rand() / RAND_MAX);
                particle->velocity[j] = w * particle->velocity[j] + c1 * r1 * (particle->best_position[j] - particle->position[j]) + c2 * r2 * (swarm->best_position[j] - particle->position[j]);
                particle->position[j] += particle->velocity[j];
            }
            particle->best_value = 0;
            for (int j = 0; j < swarm->dimensions; j++) {
                particle->best_value += particle->position[j] * particle->position[j];
            }
            if (particle->best_value < particle->best_value) {
                particle->best_value = particle->best_value;
                for (int j = 0; j < swarm->dimensions; j++) {
                    particle->best_position[j] = particle->position[j];
                }
            }
        }
        update_best(swarm);
    }
}

void main() {
    int dimensions = 2;
    int swarm_size = 30;
    int iterations = 100;
    Swarm swarm;
    initialize_swarm(&swarm, swarm_size, dimensions);
    optimize(&swarm, iterations);
    printf("Best position: ");
    for (int i = 0; i < dimensions; i++) {
        printf("%f ", swarm.best_position[i]);
    }
    printf("\nBest value: %f\n", swarm.best_value);
}