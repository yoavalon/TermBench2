#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double* position;
    double* velocity;
    double fitness;
    double* best_position;
} Particle;

typedef struct {
    Particle* particles;
    double* best_position;
    int size;
} Swarm;

void Particle_init(Particle* self, int dimensions) {
    self->position = (double*)malloc(dimensions * sizeof(double));
    self->velocity = (double*)malloc(dimensions * sizeof(double));
    self->best_position = (double*)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        self->position[i] = 0.0;
        self->velocity[i] = 0.0;
        self->best_position[i] = 0.0;
    }
    self->fitness = 0.0;
}

void Particle_update_velocity(Particle* self, double* best_position, int dimensions) {
    double w = 0.7, c1 = 1.5, c2 = 1.5;
    for (int i = 0; i < dimensions; i++) {
        double r1 = 0.5, r2 = 0.5;
        double cognitive = c1 * r1 * (best_position[i] - self->position[i]);
        double social = c2 * r2 * (self->best_position[i] - self->position[i]);
        self->velocity[i] = w * self->velocity[i] + cognitive + social;
    }
}

void Particle_update_position(Particle* self, int dimensions) {
    for (int i = 0; i < dimensions; i++) {
        self->position[i] += self->velocity[i];
    }
    self->fitness = self->calculate_fitness(dimensions);
}

double Particle_calculate_fitness(Particle* self, int dimensions) {
    double fitness = 0.0;
    for (int i = 0; i < dimensions; i++) {
        fitness += self->position[i] * self->position[i];
    }
    return fitness;
}

void Swarm_init(Swarm* self, int size, int dimensions) {
    self->particles = (Particle*)malloc(size * sizeof(Particle));
    self->best_position = (double*)malloc(dimensions * sizeof(double));
    self->size = size;
    for (int i = 0; i < size; i++) {
        Particle_init(&self->particles[i], dimensions);
    }
}

void Swarm_update_best_position(Swarm* self, int dimensions) {
    if (self->best_position == NULL) {
        for (int i = 0; i < dimensions; i++) {
            self->best_position[i] = self->particles[0].position[i];
        }
    } else {
        for (int i = 0; i < self->size; i++) {
            if (self->particles[i].fitness > Particle_calculate_fitness(&self->particles[i], dimensions)) {
                for (int j = 0; j < dimensions; j++) {
                    self->best_position[j] = self->particles[i].position[j];
                }
            }
        }
    }
}

void Swarm_update_particles(Swarm* self, int iterations, int dimensions) {
    if (iterations > 0) {
        for (int i = 0; i < self->size; i++) {
            Particle_update_velocity(&self->particles[i], self->best_position, dimensions);
            Particle_update_position(&self->particles[i], dimensions);
        }
        Swarm_update_best_position(self, dimensions);
        Swarm_update_particles(self, iterations - 1, dimensions);
    }
}

void optimize(Swarm* swarm, int iterations, int dimensions) {
    Swarm_update_particles(swarm, iterations, dimensions);
}

void main() {
    int dimensions = 2;
    int swarm_size = 10;
    int iterations = 50;
    Swarm swarm;
    Swarm_init(&swarm, swarm_size, dimensions);
    optimize(&swarm, iterations, dimensions);
    for (int i = 0; i < swarm.size; i++) {
        free(swarm.particles[i].position);
        free(swarm.particles[i].velocity);
        free(swarm.particles[i].best_position);
    }
    free(swarm.particles);
    free(swarm.best_position);
}