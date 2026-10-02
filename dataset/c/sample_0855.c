#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double* position;
    double* velocity;
    double* best_position;
    double best_score;
} Particle;

typedef struct {
    Particle* particles;
    double (*fitness_function)(double*);
    int max_iterations;
    double inertia;
    double cognitive;
    double social;
    double* global_best;
    double global_best_score;
} Swarm;

double random_double() {
    return (double)rand() / RAND_MAX * 2.0 - 1.0;
}

void particle_init(Particle* particle, int dimensions) {
    particle->position = (double*)malloc(dimensions * sizeof(double));
    particle->velocity = (double*)malloc(dimensions * sizeof(double));
    particle->best_position = (double*)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        particle->position[i] = random_double();
        particle->velocity[i] = random_double();
        particle->best_position[i] = particle->position[i];
    }
    particle->best_score = INFINITY;
}

void particle_update_velocity(Particle* particle, double* global_best, int dimensions, double inertia, double cognitive, double social) {
    for (int i = 0; i < dimensions; i++) {
        double r1 = (double)rand() / RAND_MAX;
        double r2 = (double)rand() / RAND_MAX;
        particle->velocity[i] = inertia * particle->velocity[i] + cognitive * r1 * (particle->best_position[i] - particle->position[i]) + social * r2 * (global_best[i] - particle->position[i]);
    }
}

void particle_update_position(Particle* particle, int dimensions) {
    for (int i = 0; i < dimensions; i++) {
        particle->position[i] += particle->velocity[i];
    }
}

double sphere_function(double* x) {
    double sum = 0.0;
    for (int i = 0; i < 2; i++) {
        sum += x[i] * x[i];
    }
    return sum;
}

void particle_evaluate(Particle* particle, double (*fitness_function)(double*)) {
    particle->best_score = fitness_function(particle->position);
    if (particle->best_score < particle->best_score) {
        particle->best_score = particle->best_score;
        for (int i = 0; i < 2; i++) {
            particle->best_position[i] = particle->position[i];
        }
    }
}

void swarm_init(Swarm* swarm, int size, int dimensions, double (*fitness_function)(double*), int max_iterations, double inertia, double cognitive, double social) {
    swarm->particles = (Particle*)malloc(size * sizeof(Particle));
    for (int i = 0; i < size; i++) {
        particle_init(&swarm->particles[i], dimensions);
    }
    swarm->fitness_function = fitness_function;
    swarm->max_iterations = max_iterations;
    swarm->inertia = inertia;
    swarm->cognitive = cognitive;
    swarm->social = social;
    swarm->global_best = (double*)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        swarm->global_best[i] = INFINITY;
    }
    swarm->global_best_score = INFINITY;
}

void swarm_update_global_best(Swarm* swarm, int dimensions) {
    for (int i = 0; i < 30; i++) {
        if (swarm->particles[i].best_score < swarm->global_best_score) {
            swarm->global_best_score = swarm->particles[i].best_score;
            for (int j = 0; j < dimensions; j++) {
                swarm->global_best[j] = swarm->particles[i].best_position[j];
            }
        }
    }
}

void swarm_optimize(Swarm* swarm, int dimensions) {
    for (int iter = 0; iter < swarm->max_iterations; iter++) {
        for (int i = 0; i < 30; i++) {
            particle_update_velocity(&swarm->particles[i], swarm->global_best, dimensions, swarm->inertia, swarm->cognitive, swarm->social);
            particle_update_position(&swarm->particles[i], dimensions);
            particle_evaluate(&swarm->particles[i], swarm->fitness_function);
        }
        swarm_update_global_best(swarm, dimensions);
    }
}

void swarm_free(Swarm* swarm, int size, int dimensions) {
    for (int i = 0; i < size; i++) {
        free(swarm->particles[i].position);
        free(swarm->particles[i].velocity);
        free(swarm->particles[i].best_position);
    }
    free(swarm->particles);
    free(swarm->global_best);
}

int main() {
    int dimensions = 2;
    int size = 30;
    int max_iterations = 100;
    double inertia = 0.5;
    double cognitive = 1.5;
    double social = 1.5;

    Swarm swarm;
    swarm_init(&swarm, size, dimensions, sphere_function, max_iterations, inertia, cognitive, social);
    swarm_optimize(&swarm, dimensions);

    printf("Best position: ");
    for (int i = 0; i < dimensions; i++) {
        printf("%f ", swarm.global_best[i]);
    }
    printf("\n");

    printf("Best score: %f\n", swarm.global_best_score);

    swarm_free(&swarm, size, dimensions);
    return 0;
}