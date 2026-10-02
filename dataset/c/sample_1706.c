#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 1e9

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

double random_uniform(double min, double max) {
    return min + (max - min) * ((double)rand() / RAND_MAX);
}

void Particle_init(Particle *particle, int dim) {
    particle->position = (double *)malloc(dim * sizeof(double));
    particle->velocity = (double *)malloc(dim * sizeof(double));
    particle->best_position = (double *)malloc(dim * sizeof(double));
    for (int i = 0; i < dim; i++) {
        particle->position[i] = random_uniform(-10, 10);
        particle->velocity[i] = random_uniform(-1, 1);
        particle->best_position[i] = particle->position[i];
    }
    particle->best_fitness = INF;
}

void Particle_update_velocity(Particle *particle, double *global_best, int dim, double w, double c1, double c2) {
    for (int i = 0; i < dim; i++) {
        double r1 = (double)rand() / RAND_MAX;
        double r2 = (double)rand() / RAND_MAX;
        double cognitive = c1 * r1 * (particle->best_position[i] - particle->position[i]);
        double social = c2 * r2 * (global_best[i] - particle->position[i]);
        particle->velocity[i] = w * particle->velocity[i] + cognitive + social;
    }
}

void Particle_update_position(Particle *particle, int dim) {
    for (int i = 0; i < dim; i++) {
        particle->position[i] += particle->velocity[i];
    }
}

void Swarm_init(Swarm *swarm, int dim, int num_particles) {
    swarm->particles = (Particle *)malloc(num_particles * sizeof(Particle));
    swarm->global_best_position = (double *)malloc(dim * sizeof(double));
    for (int i = 0; i < num_particles; i++) {
        Particle_init(&swarm->particles[i], dim);
    }
    for (int i = 0; i < dim; i++) {
        swarm->global_best_position[i] = INF;
    }
    swarm->global_best_fitness = INF;
}

void Swarm_update_global_best(Swarm *swarm, int dim) {
    for (int i = 0; i < dim; i++) {
        swarm->global_best_position[i] = INF;
    }
    swarm->global_best_fitness = INF;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            double fitness = swarm->particles[i].position[j] * swarm->particles[i].position[j];
            if (fitness < swarm->particles[i].best_fitness) {
                swarm->particles[i].best_fitness = fitness;
                for (int k = 0; k < dim; k++) {
                    swarm->particles[i].best_position[k] = swarm->particles[i].position[k];
                }
            }
            if (fitness < swarm->global_best_fitness) {
                swarm->global_best_fitness = fitness;
                for (int k = 0; k < dim; k++) {
                    swarm->global_best_position[k] = swarm->particles[i].position[k];
                }
            }
        }
    }
}

void Swarm_iterate(Swarm *swarm, int dim) {
    Swarm_update_global_best(swarm, dim);
    for (int i = 0; i < dim; i++) {
        Particle_update_velocity(&swarm->particles[i], swarm->global_best_position, dim, 0.5, 1.5, 1.5);
        Particle_update_position(&swarm->particles[i], dim);
    }
}

void main() {
    int dim = 2;
    int num_particles = 10;
    Swarm swarm;
    Swarm_init(&swarm, dim, num_particles);
    while (1) {
        Swarm_iterate(&swarm, dim);
    }
}