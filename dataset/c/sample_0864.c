#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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
    int num_particles;
    int dimensions;
} Swarm;

double random_double(double min, double max) {
    return min + (max - min) * ((double)rand() / RAND_MAX);
}

Particle* create_particle(int dimensions) {
    Particle* particle = (Particle*)malloc(sizeof(Particle));
    particle->position = (double*)malloc(dimensions * sizeof(double));
    particle->velocity = (double*)malloc(dimensions * sizeof(double));
    particle->best_position = (double*)malloc(dimensions * sizeof(double));
    particle->best_score = INFINITY;

    for (int i = 0; i < dimensions; i++) {
        particle->position[i] = random_double(-10, 10);
        particle->velocity[i] = random_double(-1, 1);
        particle->best_position[i] = particle->position[i];
    }

    return particle;
}

void update_velocity(Particle* particle, double* global_best_position, int dimensions, double w, double c1, double c2) {
    for (int i = 0; i < dimensions; i++) {
        double r1 = (double)rand() / RAND_MAX;
        double r2 = (double)rand() / RAND_MAX;
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

double evaluate(Particle* particle, double (*fitness_function)(double*)) {
    particle->best_score = fitness_function(particle->position);
    return particle->best_score;
}

Swarm* create_swarm(int num_particles, int dimensions) {
    Swarm* swarm = (Swarm*)malloc(sizeof(Swarm));
    swarm->particles = (Particle*)malloc(num_particles * sizeof(Particle));
    swarm->global_best_position = (double*)malloc(dimensions * sizeof(double));
    swarm->global_best_score = INFINITY;
    swarm->num_particles = num_particles;
    swarm->dimensions = dimensions;

    for (int i = 0; i < num_particles; i++) {
        swarm->particles[i] = *create_particle(dimensions);
    }

    for (int i = 0; i < dimensions; i++) {
        swarm->global_best_position[i] = random_double(-10, 10);
    }

    return swarm;
}

void update_global_best(Swarm* swarm) {
    for (int i = 0; i < swarm->num_particles; i++) {
        if (swarm->particles[i].best_score < swarm->global_best_score) {
            swarm->global_best_score = swarm->particles[i].best_score;
            for (int j = 0; j < swarm->dimensions; j++) {
                swarm->global_best_position[j] = swarm->particles[i].best_position[j];
            }
        }
    }
}

double fitness_function(double* x, int dimensions) {
    double sum = 0;
    for (int i = 0; i < dimensions; i++) {
        sum += x[i] * x[i];
    }
    return sum;
}

void optimize(Swarm* swarm, double w, double c1, double c2, int iterations) {
    for (int i = 0; i < iterations; i++) {
        for (int j = 0; j < swarm->num_particles; j++) {
            update_velocity(&swarm->particles[j], swarm->global_best_position, swarm->dimensions, w, c1, c2);
            update_position(&swarm->particles[j], swarm->dimensions);
            evaluate(&swarm->particles[j], fitness_function);
        }
        update_global_best(swarm);
    }
}

void free_particle(Particle* particle, int dimensions) {
    free(particle->position);
    free(particle->velocity);
    free(particle->best_position);
    free(particle);
}

void free_swarm(Swarm* swarm) {
    for (int i = 0; i < swarm->num_particles; i++) {
        free_particle(&swarm->particles[i], swarm->dimensions);
    }
    free(swarm->particles);
    free(swarm->global_best_position);
    free(swarm);
}

int main() {
    srand(time(NULL));
    int dimensions = 10;
    int num_particles = 20;
    double w = 0.7;
    double c1 = 2.0;
    double c2 = 2.0;
    int iterations = 100;
    Swarm* swarm = create_swarm(num_particles, dimensions);
    optimize(swarm, w, c1, c2, iterations);
    printf("Best position: ");
    for (int i = 0; i < dimensions; i++) {
        printf("%f ", swarm->global_best_position[i]);
    }
    printf("\nBest score: %f\n", swarm->global_best_score);
    free_swarm(swarm);
    return 0;
}