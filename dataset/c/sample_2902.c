#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define INFINITY_FLOAT 1e308

typedef struct {
    double* position;
    double* velocity;
    double* best_position;
    double best_fitness;
} Particle;

typedef struct {
    Particle* particles;
    double* global_best;
    double global_best_fitness;
    int num_particles;
    int dimensions;
    double bounds[2][2];
    double (*fitness_function)(double*);
} Swarm;

double random_uniform(double min, double max) {
    return min + (max - min) * ((double)rand() / RAND_MAX);
}

Particle* create_particle(int dimensions) {
    Particle* particle = (Particle*)malloc(sizeof(Particle));
    particle->position = (double*)malloc(dimensions * sizeof(double));
    particle->velocity = (double*)malloc(dimensions * sizeof(double));
    particle->best_position = (double*)malloc(dimensions * sizeof(double));
    particle->best_fitness = INFINITY_FLOAT;
    for (int i = 0; i < dimensions; i++) {
        particle->position[i] = random_uniform(-1, 1);
        particle->velocity[i] = random_uniform(-1, 1);
        particle->best_position[i] = particle->position[i];
    }
    return particle;
}

void update_velocity(Particle* particle, double* global_best, int dimensions, double w, double c1, double c2) {
    for (int i = 0; i < dimensions; i++) {
        double r1 = (double)rand() / RAND_MAX;
        double r2 = (double)rand() / RAND_MAX;
        double cognitive = c1 * r1 * (particle->best_position[i] - particle->position[i]);
        double social = c2 * r2 * (global_best[i] - particle->position[i]);
        particle->velocity[i] = w * particle->velocity[i] + cognitive + social;
    }
}

void update_position(Particle* particle, int dimensions, double bounds[2][2]) {
    for (int i = 0; i < dimensions; i++) {
        particle->position[i] += particle->velocity[i];
        particle->position[i] = fmax(bounds[0][i], fmin(bounds[1][i], particle->position[i]));
    }
}

double evaluate_fitness(Particle* particle, double (*fitness_function)(double*)) {
    particle->best_fitness = fitness_function(particle->position);
    if (particle->best_fitness < particle->best_fitness) {
        particle->best_fitness = particle->best_fitness;
        for (int i = 0; i < particle->dimensions; i++) {
            particle->best_position[i] = particle->position[i];
        }
    }
    return particle->best_fitness;
}

Swarm* create_swarm(int num_particles, int dimensions, double bounds[2][2], double (*fitness_function)(double*)) {
    Swarm* swarm = (Swarm*)malloc(sizeof(Swarm));
    swarm->particles = (Particle*)malloc(num_particles * sizeof(Particle));
    swarm->global_best = (double*)malloc(dimensions * sizeof(double));
    swarm->global_best_fitness = INFINITY_FLOAT;
    swarm->num_particles = num_particles;
    swarm->dimensions = dimensions;
    swarm->fitness_function = fitness_function;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < dimensions; j++) {
            swarm->bounds[i][j] = bounds[i][j];
        }
    }
    for (int i = 0; i < num_particles; i++) {
        swarm->particles[i] = *create_particle(dimensions);
    }
    for (int i = 0; i < dimensions; i++) {
        swarm->global_best[i] = random_uniform(-1, 1);
    }
    return swarm;
}

void update_global_best(Swarm* swarm) {
    for (int i = 0; i < swarm->num_particles; i++) {
        if (swarm->particles[i].best_fitness < swarm->global_best_fitness) {
            swarm->global_best_fitness = swarm->particles[i].best_fitness;
            for (int j = 0; j < swarm->dimensions; j++) {
                swarm->global_best[j] = swarm->particles[i].best_position[j];
            }
        }
    }
}

void optimize(Swarm* swarm, double w, double c1, double c2) {
    while (1) {
        for (int i = 0; i < swarm->num_particles; i++) {
            update_velocity(&swarm->particles[i], swarm->global_best, swarm->dimensions, w, c1, c2);
            update_position(&swarm->particles[i], swarm->dimensions, swarm->bounds);
            evaluate_fitness(&swarm->particles[i], swarm->fitness_function);
        }
        update_global_best(swarm);
    }
}

double fitness_function(double* x) {
    double sum = 0;
    for (int i = 0; i < 2; i++) {
        sum += x[i] * x[i];
    }
    return sum;
}

int main() {
    srand(time(0));
    int dimensions = 2;
    int num_particles = 30;
    double bounds[2][2] = {{-10, -10}, {10, 10}};
    Swarm* swarm = create_swarm(num_particles, dimensions, bounds, fitness_function);
    double w = 0.729;
    double c1 = 1.494;
    double c2 = 1.494;
    optimize(swarm, w, c1, c2);
    return 0;
}