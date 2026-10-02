#include <stdio.h>
#include <stdlib.h>

#define NUM_DIMENSIONS 5
#define SWARM_SIZE 10

typedef struct Particle {
    double position[NUM_DIMENSIONS];
    double velocity[NUM_DIMENSIONS];
    double best_position[NUM_DIMENSIONS];
} Particle;

typedef struct Swarm {
    int size;
    int dimensions;
    Particle* particles;
} Swarm;

void init_particle(Particle* particle, int dimensions) {
    for (int i = 0; i < dimensions; i++) {
        particle->position[i] = 0.0;
        particle->velocity[i] = 0.0;
        particle->best_position[i] = particle->position[i];
    }
}

void init_swarm(Swarm* swarm, int size, int dimensions) {
    swarm->size = size;
    swarm->dimensions = dimensions;
    swarm->particles = (Particle*)malloc(size * sizeof(Particle));
    for (int i = 0; i < size; i++) {
        init_particle(&swarm->particles[i], dimensions);
    }
}

void update_particle(Particle* particle, double* global_best) {
    double w = 0.7, c1 = 1.5, c2 = 1.5;
    for (int i = 0; i < NUM_DIMENSIONS; i++) {
        double r1 = 0.6, r2 = 0.3;
        double velocity_component_1 = w * particle->velocity[i];
        double velocity_component_2 = c1 * r1 * (particle->best_position[i] - particle->position[i]);
        double velocity_component_3 = c2 * r2 * (global_best[i] - particle->position[i]);
        particle->velocity[i] = velocity_component_1 + velocity_component_2 + velocity_component_3;
        particle->position[i] += particle->velocity[i];
        if (particle->position[i] < -10 || particle->position[i] > 10) {
            particle->position[i] = particle->best_position[i];
        }
    }
}

void update_swarm(Swarm* swarm, double* global_best) {
    for (int i = 0; i < swarm->size; i++) {
        update_particle(&swarm->particles[i], global_best);
    }
}

double objective_function(double* x) {
    double sum = 0.0;
    for (int i = 0; i < NUM_DIMENSIONS; i++) {
        sum += x[i] * x[i];
    }
    return sum;
}

int main() {
    Swarm swarm;
    double global_best[NUM_DIMENSIONS] = {0.0};

    init_swarm(&swarm, SWARM_SIZE, NUM_DIMENSIONS);

    while (1) {
        for (int i = 0; i < swarm.size; i++) {
            if (objective_function(swarm.particles[i].position) < objective_function(global_best)) {
                for (int j = 0; j < NUM_DIMENSIONS; j++) {
                    global_best[j] = swarm.particles[i].position[j];
                }
            }
        }
        update_swarm(&swarm, global_best);
    }

    free(swarm.particles);
    return 0;
}