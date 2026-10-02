#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

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
    return min + (double)rand() / RAND_MAX * (max - min);
}

void particle_init(Particle* particle, int dimensions) {
    particle->position = (double*)malloc(dimensions * sizeof(double));
    particle->velocity = (double*)malloc(dimensions * sizeof(double));
    particle->best_position = (double*)malloc(dimensions * sizeof(double));
    particle->best_score = INFINITY;

    for (int i = 0; i < dimensions; i++) {
        particle->position[i] = random_double(-10, 10);
        particle->velocity[i] = random_double(-1, 1);
        particle->best_position[i] = particle->position[i];
    }
}

void particle_update_velocity(Particle* particle, double* global_best_position, double w, double c1, double c2, int dimensions) {
    for (int i = 0; i < dimensions; i++) {
        double r1 = (double)rand() / RAND_MAX;
        double r2 = (double)rand() / RAND_MAX;
        double cognitive = c1 * r1 * (particle->best_position[i] - particle->position[i]);
        double social = c2 * r2 * (global_best_position[i] - particle->position[i]);
        particle->velocity[i] = w * particle->velocity[i] + cognitive + social;
    }
}

void particle_update_position(Particle* particle, int dimensions) {
    for (int i = 0; i < dimensions; i++) {
        particle->position[i] += particle->velocity[i];
        if (particle->position[i] < -10) {
            particle->position[i] = -10;
        } else if (particle->position[i] > 10) {
            particle->position[i] = 10;
        }
    }
}

double particle_evaluate(Particle* particle, double (*objective_function)(double*)) {
    double score = objective_function(particle->position);
    if (score < particle->best_score) {
        particle->best_score = score;
        for (int i = 0; i < particle->dimensions; i++) {
            particle->best_position[i] = particle->position[i];
        }
    }
    return score;
}

void swarm_init(Swarm* swarm, int num_particles, int dimensions) {
    swarm->particles = (Particle*)malloc(num_particles * sizeof(Particle));
    swarm->global_best_position = (double*)malloc(dimensions * sizeof(double));
    swarm->global_best_score = INFINITY;
    swarm->num_particles = num_particles;
    swarm->dimensions = dimensions;

    for (int i = 0; i < num_particles; i++) {
        particle_init(&swarm->particles[i], dimensions);
    }

    for (int i = 0; i < dimensions; i++) {
        swarm->global_best_position[i] = random_double(-10, 10);
    }
}

void swarm_update_global_best(Swarm* swarm) {
    for (int i = 0; i < swarm->num_particles; i++) {
        if (swarm->particles[i].best_score < swarm->global_best_score) {
            swarm->global_best_score = swarm->particles[i].best_score;
            for (int j = 0; j < swarm->dimensions; j++) {
                swarm->global_best_position[j] = swarm->particles[i].best_position[j];
            }
        }
    }
}

void swarm_optimize(Swarm* swarm, double (*objective_function)(double*), double w, double c1, double c2, int iterations) {
    for (int i = 0; i < iterations; i++) {
        for (int j = 0; j < swarm->num_particles; j++) {
            particle_update_velocity(&swarm->particles[j], swarm->global_best_position, w, c1, c2, swarm->dimensions);
            particle_update_position(&swarm->particles[j], swarm->dimensions);
            particle_evaluate(&swarm->particles[j], objective_function);
        }
        swarm_update_global_best(swarm);
    }
}

double objective_function(double* x) {
    double sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += x[i] * x[i];
    }
    return sum;
}

int main() {
    srand(time(NULL));
    int dimensions = 3;
    int num_particles = 10;
    double w = 0.7;
    double c1 = 1.5;
    double c2 = 1.5;
    int iterations = 50;

    Swarm swarm;
    swarm_init(&swarm, num_particles, dimensions);
    swarm_optimize(&swarm, objective_function, w, c1, c2, iterations);

    printf("Best position: ");
    for (int i = 0; i < dimensions; i++) {
        printf("%f ", swarm.global_best_position[i]);
    }
    printf("\nBest score: %f\n", swarm.global_best_score);

    for (int i = 0; i < num_particles; i++) {
        free(swarm.particles[i].position);
        free(swarm.particles[i].velocity);
        free(swarm.particles[i].best_position);
    }
    free(swarm.particles);
    free(swarm.global_best_position);

    return 0;
}