#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    double* position;
    double* velocity;
    double* best_position;
    double best_score;
} Particle;

typedef struct {
    Particle* particles;
    double* global_best_position;
    double global_best_score;
} Swarm;

double random_double(double min, double max) {
    return min + (double)rand() / RAND_MAX * (max - min);
}

void init_particle(Particle* particle, int dimensions) {
    particle->position = (double*)malloc(dimensions * sizeof(double));
    particle->velocity = (double*)malloc(dimensions * sizeof(double));
    particle->best_position = (double*)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        particle->position[i] = random_double(-10, 10);
        particle->velocity[i] = random_double(-1, 1);
        particle->best_position[i] = particle->position[i];
    }
    particle->best_score = INFINITY;
}

void update_velocity(Particle* particle, double* global_best_position, int dimensions, double w, double c1, double c2) {
    for (int i = 0; i < dimensions; i++) {
        double r1 = random_double(0, 1);
        double r2 = random_double(0, 1);
        double cognitive = c1 * r1 * (particle->best_position[i] - particle->position[i]);
        double social = c2 * r2 * (global_best_position[i] - particle->position[i]);
        particle->velocity[i] = w * particle->velocity[i] + cognitive + social;
    }
}

void update_position(Particle* particle, int dimensions) {
    for (int i = 0; i < dimensions; i++) {
        particle->position[i] += particle->velocity[i];
    }
}

double evaluate(Particle* particle, int dimensions) {
    double score = 0;
    for (int i = 0; i < dimensions; i++) {
        score += particle->position[i] * particle->position[i];
    }
    if (score < particle->best_score) {
        particle->best_score = score;
        for (int i = 0; i < dimensions; i++) {
            particle->best_position[i] = particle->position[i];
        }
    }
    return score;
}

void init_swarm(Swarm* swarm, int size, int dimensions) {
    swarm->particles = (Particle*)malloc(size * sizeof(Particle));
    swarm->global_best_position = (double*)malloc(dimensions * sizeof(double));
    swarm->global_best_score = INFINITY;
    for (int i = 0; i < size; i++) {
        init_particle(&swarm->particles[i], dimensions);
    }
}

void update_global_best(Swarm* swarm, int dimensions) {
    for (int i = 0; i < dimensions; i++) {
        swarm->global_best_position[i] = swarm->particles[0].position[i];
    }
    swarm->global_best_score = swarm->particles[0].best_score;
    for (int i = 1; i < swarm->particles; i++) {
        if (swarm->particles[i].best_score < swarm->global_best_score) {
            swarm->global_best_score = swarm->particles[i].best_score;
            for (int j = 0; j < dimensions; j++) {
                swarm->global_best_position[j] = swarm->particles[i].best_position[j];
            }
        }
    }
}

void update_swarm(Swarm* swarm, int size, int dimensions) {
    for (int i = 0; i < size; i++) {
        update_velocity(&swarm->particles[i], swarm->global_best_position, dimensions, 0.7, 1.5, 1.5);
        update_position(&swarm->particles[i], dimensions);
    }
}

void main() {
    srand(time(NULL));
    int dimensions = 10;
    int swarm_size = 20;
    Swarm swarm;
    init_swarm(&swarm, swarm_size, dimensions);
    while (1) {
        for (int i = 0; i < swarm_size; i++) {
            evaluate(&swarm.particles[i], dimensions);
        }
        update_global_best(&swarm, dimensions);
        update_swarm(&swarm, swarm_size, dimensions);
    }
}