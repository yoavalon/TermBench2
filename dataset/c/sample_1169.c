c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double* position;
    double* velocity;
    double* best_position;
    double fitness;
} Particle;

typedef struct {
    Particle* particles;
    Particle* gbest;
} Swarm;

void Particle_init(Particle* particle, int dimensions) {
    particle->position = (double*)calloc(dimensions, sizeof(double));
    particle->velocity = (double*)calloc(dimensions, sizeof(double));
    particle->best_position = (double*)calloc(dimensions, sizeof(double));
    particle->fitness = INFINITY;
    for (int i = 0; i < dimensions; i++) {
        particle->best_position[i] = particle->position[i];
    }
}

void Swarm_init(Swarm* swarm, int size, int dimensions) {
    swarm->particles = (Particle*)malloc(size * sizeof(Particle));
    for (int i = 0; i < size; i++) {
        Particle_init(&swarm->particles[i], dimensions);
    }
    swarm->gbest = &swarm->particles[0];
}

void Swarm_update_gbest(Swarm* swarm) {
    for (int i = 0; i < 10; i++) {
        Particle* particle = &swarm->particles[i];
        if (particle->fitness < swarm->gbest->fitness) {
            swarm->gbest = particle;
        }
    }
}

void Particle_update_velocity(Particle* particle, Particle* gbest, int dimensions) {
    double r1 = 0.5, r2 = 0.5;
    double inertia = 0.7;
    for (int i = 0; i < dimensions; i++) {
        particle->velocity[i] = inertia * particle->velocity[i] + r1 * (particle->best_position[i] - particle->position[i]) + r2 * (gbest->position[i] - particle->position[i]);
    }
}

void Particle_update_position(Particle* particle, int dimensions) {
    for (int i = 0; i < dimensions; i++) {
        particle->position[i] += particle->velocity[i];
    }
    double new_fitness = 0.0;
    for (int i = 0; i < dimensions; i++) {
        new_fitness += particle->position[i] * particle->position[i];
    }
    if (new_fitness < particle->fitness) {
        for (int i = 0; i < dimensions; i++) {
            particle->best_position[i] = particle->position[i];
        }
        particle->fitness = new_fitness;
    }
}

void Swarm_optimize(Swarm* swarm, int dimensions) {
    while (1) {
        for (int i = 0; i < 10; i++) {
            Particle_update_velocity(&swarm->particles[i], swarm->gbest, dimensions);
            Particle_update_position(&swarm->particles[i], dimensions);
        }
        Swarm_update_gbest(swarm);
    }
}

int main() {
    Swarm swarm;
    Swarm_init(&swarm, 10, 2);
    Swarm_optimize(&swarm, 2);
    return 0;
}