#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct Particle {
    double* position;
    double* velocity;
    double* best_position;
    double fitness;
} Particle;

typedef struct Swarm {
    int size;
    int dimensions;
    double* bounds;
    Particle* particles;
    Particle* gbest;
} Swarm;

void Particle_init(Particle* particle, int dimensions, double* bounds) {
    particle->position = (double*)malloc(dimensions * sizeof(double));
    particle->velocity = (double*)malloc(dimensions * sizeof(double));
    particle->best_position = (double*)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        particle->position[i] = bounds[0] + ((double)rand() / RAND_MAX) * (bounds[1] - bounds[0]);
        particle->velocity[i] = -1 + ((double)rand() / RAND_MAX) * 2;
        particle->best_position[i] = particle->position[i];
    }
    particle->fitness = INFINITY;
}

void Particle_update_velocity(Particle* particle, Particle* gbest, int dimensions) {
    double w = 0.5, c1 = 1.5, c2 = 1.5;
    for (int i = 0; i < dimensions; i++) {
        double r1 = (double)rand() / RAND_MAX;
        double r2 = (double)rand() / RAND_MAX;
        double cognitive = c1 * r1 * (particle->best_position[i] - particle->position[i]);
        double social = c2 * r2 * (gbest->position[i] - particle->position[i]);
        particle->velocity[i] = w * particle->velocity[i] + cognitive + social;
    }
}

void Particle_update_position(Particle* particle, int dimensions, double* bounds) {
    for (int i = 0; i < dimensions; i++) {
        particle->position[i] += particle->velocity[i];
        if (particle->position[i] < bounds[0]) {
            particle->position[i] = bounds[0];
        }
        if (particle->position[i] > bounds[1]) {
            particle->position[i] = bounds[1];
        }
    }
}

void Swarm_init(Swarm* swarm, int size, int dimensions, double* bounds) {
    swarm->size = size;
    swarm->dimensions = dimensions;
    swarm->bounds = bounds;
    swarm->particles = (Particle*)malloc(size * sizeof(Particle));
    for (int i = 0; i < size; i++) {
        Particle_init(&swarm->particles[i], dimensions, bounds);
    }
    swarm->gbest = NULL;
}

void Swarm_update_gbest(Swarm* swarm) {
    for (int i = 0; i < swarm->size; i++) {
        if (swarm->gbest == NULL || swarm->particles[i].fitness < swarm->gbest->fitness) {
            swarm->gbest = &swarm->particles[i];
        }
    }
}

void Swarm_update_particles(Swarm* swarm) {
    for (int i = 0; i < swarm->size; i++) {
        Particle_update_velocity(&swarm->particles[i], swarm->gbest, swarm->dimensions);
        Particle_update_position(&swarm->particles[i], swarm->dimensions, swarm->bounds);
    }
}

double objective_function(double* x, int dimensions) {
    double sum = 0;
    for (int i = 0; i < dimensions; i++) {
        sum += x[i] * x[i];
    }
    return sum;
}

void optimize(Swarm* swarm, int max_iterations) {
    for (int i = 0; i < max_iterations; i++) {
        Swarm_update_gbest(swarm);
        for (int j = 0; j < swarm->size; j++) {
            swarm->particles[j].fitness = objective_function(swarm->particles[j].position, swarm->dimensions);
        }
        Swarm_update_particles(swarm);
    }
}

void main() {
    int size = 30;
    int dimensions = 2;
    double bounds[] = {-10, 10};
    int max_iterations = 100;
    Swarm swarm;
    srand(time(NULL));
    Swarm_init(&swarm, size, dimensions, bounds);
    optimize(&swarm, max_iterations);
    for (int i = 0; i < dimensions; i++) {
        printf("%f ", swarm.gbest->position[i]);
    }
    printf("\n");
}