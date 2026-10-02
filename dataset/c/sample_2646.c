#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define INERTIA 0.5
#define COGNITIVE_FACTOR 1.5
#define SOCIAL_FACTOR 1.5

typedef struct {
    double position[2];
    double velocity[2];
    double best_position[2];
    double best_score;
} Particle;

typedef struct {
    int size;
    int dimensions;
    double search_space[2];
    Particle *particles;
    double best_position[2];
    double best_score;
} Swarm;

void Swarm_init(Swarm *swarm, int size, int dimensions, double search_space[2]) {
    swarm->size = size;
    swarm->dimensions = dimensions;
    for (int i = 0; i < 2; i++) {
        swarm->search_space[i] = search_space[i];
    }
    swarm->particles = (Particle *)malloc(size * sizeof(Particle));
    for (int i = 0; i < size; i++) {
        Particle *particle = &swarm->particles[i];
        for (int j = 0; j < dimensions; j++) {
            particle->position[j] = search_space[0] + (double)rand() / RAND_MAX * (search_space[1] - search_space[0]);
            particle->velocity[j] = 0.0;
        }
        particle->best_score = INFINITY;
        for (int j = 0; j < dimensions; j++) {
            particle->best_position[j] = particle->position[j];
        }
    }
    int best_index = rand() % size;
    for (int i = 0; i < dimensions; i++) {
        swarm->best_position[i] = swarm->particles[best_index].position[i];
    }
    swarm->best_score = INFINITY;
}

void Swarm_update_best_position(Swarm *swarm) {
    for (int i = 0; i < swarm->size; i++) {
        Particle *particle = &swarm->particles[i];
        if (particle->best_score < swarm->best_score) {
            swarm->best_score = particle->best_score;
            for (int j = 0; j < swarm->dimensions; j++) {
                swarm->best_position[j] = particle->best_position[j];
            }
        }
    }
}

void Particle_update_velocity(Particle *particle, double global_best[2]) {
    for (int i = 0; i < 2; i++) {
        double r1 = (double)rand() / RAND_MAX;
        double r2 = (double)rand() / RAND_MAX;
        double cognitive = COGNITIVE_FACTOR * r1 * (particle->best_position[i] - particle->position[i]);
        double social = SOCIAL_FACTOR * r2 * (global_best[i] - particle->position[i]);
        particle->velocity[i] = INERTIA * particle->velocity[i] + cognitive + social;
    }
}

void Particle_move(Particle *particle) {
    for (int i = 0; i < 2; i++) {
        particle->position[i] += particle->velocity[i];
    }
}

double Particle_objective_function(Particle *particle) {
    double sum = 0.0;
    for (int i = 0; i < 2; i++) {
        sum += particle->position[i] * particle->position[i];
    }
    return sum;
}

void Particle_evaluate(Particle *particle) {
    particle->best_score = Particle_objective_function(particle);
    if (particle->best_score < particle->best_score) {
        particle->best_score = particle->best_score;
        for (int i = 0; i < 2; i++) {
            particle->best_position[i] = particle->position[i];
        }
    }
}

void Swarm_iterate(Swarm *swarm) {
    for (int i = 0; i < swarm->size; i++) {
        Particle *particle = &swarm->particles[i];
        Particle_update_velocity(particle, swarm->best_position);
        Particle_move(particle);
        Particle_evaluate(particle);
    }
}

void Swarm_run(Swarm *swarm, int iterations) {
    for (int i = 0; i < iterations; i++) {
        Swarm_iterate(swarm);
        Swarm_update_best_position(swarm);
    }
}

void main() {
    srand(time(NULL));
    int swarm_size = 30;
    int dimensions = 2;
    double search_space[2] = {-10, 10};
    int iterations = 100;
    Swarm swarm;
    Swarm_init(&swarm, swarm_size, dimensions, search_space);
    Swarm_run(&swarm, iterations);
    printf("Best position: (%.2f, %.2f)\n", swarm.best_position[0], swarm.best_position[1]);
    printf("Best score: %.2f\n", swarm.best_score);
    free(swarm.particles);
}