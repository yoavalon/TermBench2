#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    double *position;
    double *velocity;
    double *best_position;
    double best_fitness;
} Particle;

typedef struct {
    Particle *particles;
    double *global_best_position;
    double global_best_fitness;
} Swarm;

double random_double(double min, double max) {
    return min + (double)rand() / RAND_MAX * (max - min);
}

void init_particle(Particle *particle, int dimensions) {
    particle->position = (double *)malloc(dimensions * sizeof(double));
    particle->velocity = (double *)malloc(dimensions * sizeof(double));
    particle->best_position = (double *)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        particle->position[i] = random_double(-10, 10);
        particle->velocity[i] = random_double(-1, 1);
        particle->best_position[i] = particle->position[i];
    }
    particle->best_fitness = INFINITY;
}

void update_velocity(Particle *particle, double *global_best, int dimensions, double w, double c1, double c2) {
    for (int i = 0; i < dimensions; i++) {
        double r1 = (double)rand() / RAND_MAX;
        double r2 = (double)rand() / RAND_MAX;
        double cognitive = c1 * r1 * (particle->best_position[i] - particle->position[i]);
        double social = c2 * r2 * (global_best[i] - particle->position[i]);
        particle->velocity[i] = w * particle->velocity[i] + cognitive + social;
    }
}

void update_position(Particle *particle, int dimensions) {
    for (int i = 0; i < dimensions; i++) {
        particle->position[i] += particle->velocity[i];
    }
}

double evaluate_fitness(double *position, int dimensions) {
    double fitness = 0;
    for (int i = 0; i < dimensions; i++) {
        fitness += position[i] * position[i];
    }
    return fitness;
}

void init_swarm(Swarm *swarm, int dimensions, int num_particles) {
    swarm->particles = (Particle *)malloc(num_particles * sizeof(Particle));
    for (int i = 0; i < num_particles; i++) {
        init_particle(&swarm->particles[i], dimensions);
    }
    swarm->global_best_position = (double *)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        swarm->global_best_position[i] = swarm->particles[0].best_position[i];
    }
    swarm->global_best_fitness = swarm->particles[0].best_fitness;
}

void update_global_best(Swarm *swarm, int dimensions) {
    for (int i = 0; i < dimensions; i++) {
        swarm->global_best_position[i] = swarm->particles[0].best_position[i];
    }
    swarm->global_best_fitness = swarm->particles[0].best_fitness;
    for (int i = 1; i < swarm->particles; i++) {
        double fitness = evaluate_fitness(swarm->particles[i].position, dimensions);
        if (fitness < swarm->particles[i].best_fitness) {
            swarm->particles[i].best_fitness = fitness;
            for (int j = 0; j < dimensions; j++) {
                swarm->particles[i].best_position[j] = swarm->particles[i].position[j];
            }
        }
        if (swarm->particles[i].best_fitness < swarm->global_best_fitness) {
            swarm->global_best_fitness = swarm->particles[i].best_fitness;
            for (int j = 0; j < dimensions; j++) {
                swarm->global_best_position[j] = swarm->particles[i].best_position[j];
            }
        }
    }
}

void optimize(Swarm *swarm, int dimensions, int num_particles, double w, double c1, double c2, int iterations) {
    for (int iter = 0; iter < iterations; iter++) {
        update_global_best(swarm, dimensions);
        for (int i = 0; i < num_particles; i++) {
            update_velocity(&swarm->particles[i], swarm->global_best_position, dimensions, w, c1, c2);
            update_position(&swarm->particles[i], dimensions);
        }
    }
}

int main() {
    int dimensions = 3;
    int num_particles = 10;
    double w = 0.7;
    double c1 = 1.5;
    double c2 = 1.5;
    int iterations = 100;

    srand(time(NULL));

    Swarm swarm;
    init_swarm(&swarm, dimensions, num_particles);
    optimize(&swarm, dimensions, num_particles, w, c1, c2, iterations);

    printf("Global Best Position: ");
    for (int i = 0; i < dimensions; i++) {
        printf("%f ", swarm.global_best_position[i]);
    }
    printf("\nGlobal Best Fitness: %f\n", swarm.global_best_fitness);

    return 0;
}