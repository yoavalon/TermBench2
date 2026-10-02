#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 30
#define DIMENSIONS 2
#define SEARCH_SPACE_MIN -10
#define SEARCH_SPACE_MAX 10
#define MAX_ITERATIONS 100

typedef struct {
    double position[DIMENSIONS];
    double velocity[DIMENSIONS];
    double best_position[DIMENSIONS];
    double best_fitness;
} Particle;

typedef struct {
    int size;
    int dimensions;
    double search_space[2];
    Particle *particles;
} Swarm;

void Particle_init(Particle *p, int dimensions, double search_space[2]) {
    for (int i = 0; i < dimensions; i++) {
        p->position[i] = (double)rand() / RAND_MAX * (search_space[1] - search_space[0]) + search_space[0];
        p->velocity[i] = (double)rand() / RAND_MAX * 2 - 1;
    }
    for (int i = 0; i < dimensions; i++) {
        p->best_position[i] = p->position[i];
    }
    p->best_fitness = INFINITY;
}

void Particle_update_velocity(Particle *p) {
    double w = 0.7;
    double c1 = 1.5;
    double c2 = 1.5;
    for (int i = 0; i < DIMENSIONS; i++) {
        double r1 = (double)rand() / RAND_MAX;
        double r2 = (double)rand() / RAND_MAX;
        double cognitive = c1 * r1 * (p->best_position[i] - p->position[i]);
        double social = c2 * r2 * (p->best_position[i] - p->position[i]);
        p->velocity[i] = w * p->velocity[i] + cognitive + social;
    }
}

void Particle_update_position(Particle *p, double search_space[2]) {
    for (int i = 0; i < DIMENSIONS; i++) {
        p->position[i] += p->velocity[i];
        p->position[i] = fmax(search_space[0], fmin(search_space[1], p->position[i]));
    }
}

double fitness_function(double position[DIMENSIONS]) {
    double sum = 0;
    for (int i = 0; i < DIMENSIONS; i++) {
        sum += position[i] * position[i];
    }
    return sum;
}

void Swarm_init(Swarm *s, int size, int dimensions, double search_space[2]) {
    s->size = size;
    s->dimensions = dimensions;
    s->search_space[0] = search_space[0];
    s->search_space[1] = search_space[1];
    s->particles = (Particle *)malloc(size * sizeof(Particle));
    for (int i = 0; i < size; i++) {
        Particle_init(&s->particles[i], dimensions, search_space);
    }
}

void Swarm_update(Swarm *s) {
    for (int i = 0; i < s->size; i++) {
        Particle_update_velocity(&s->particles[i]);
        Particle_update_position(&s->particles[i], s->search_space);
    }
}

void optimize(Swarm *swarm, int max_iterations) {
    for (int iteration = 0; iteration < max_iterations; iteration++) {
        for (int i = 0; i < swarm->size; i++) {
            double current_fitness = fitness_function(swarm->particles[i].position);
            if (current_fitness < swarm->particles[i].best_fitness) {
                swarm->particles[i].best_fitness = current_fitness;
                for (int j = 0; j < swarm->dimensions; j++) {
                    swarm->particles[i].best_position[j] = swarm->particles[i].position[j];
                }
            }
        }
        Swarm_update(swarm);
    }
}

void main() {
    srand(time(NULL));
    Swarm swarm;
    double search_space[2] = {SEARCH_SPACE_MIN, SEARCH_SPACE_MAX};
    Swarm_init(&swarm, SIZE, DIMENSIONS, search_space);
    optimize(&swarm, MAX_ITERATIONS);
    free(swarm.particles);
}