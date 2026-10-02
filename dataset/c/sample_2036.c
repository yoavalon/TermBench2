#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define INF 1e9

typedef struct {
    double *position;
    double *velocity;
    double *best_position;
    double best_score;
} Particle;

typedef struct {
    Particle *particles;
    double *global_best_position;
    double global_best_score;
} Swarm;

void Particle_init(Particle *particle, int dimensions, double lower_bound, double upper_bound) {
    particle->position = (double *)malloc(dimensions * sizeof(double));
    particle->velocity = (double *)malloc(dimensions * sizeof(double));
    particle->best_position = (double *)malloc(dimensions * sizeof(double));
    particle->best_score = INF;

    for (int i = 0; i < dimensions; i++) {
        particle->position[i] = ((double)rand() / RAND_MAX) * (upper_bound - lower_bound) + lower_bound;
        particle->velocity[i] = ((double)rand() / RAND_MAX) * 2 - 1;
        particle->best_position[i] = particle->position[i];
    }
}

void Particle_update_velocity(Particle *particle, double *global_best_position, int dimensions, double w, double c1, double c2) {
    for (int i = 0; i < dimensions; i++) {
        double r1 = (double)rand() / RAND_MAX;
        double r2 = (double)rand() / RAND_MAX;
        particle->velocity[i] = w * particle->velocity[i] + c1 * r1 * (particle->best_position[i] - particle->position[i]) + c2 * r2 * (global_best_position[i] - particle->position[i]);
    }
}

void Particle_update_position(Particle *particle, int dimensions) {
    for (int i = 0; i < dimensions; i++) {
        particle->position[i] += particle->velocity[i];
    }
}

void Particle_evaluate(Particle *particle, double (*fitness_function)(double *), int dimensions) {
    double score = fitness_function(particle->position);
    if (score < particle->best_score) {
        particle->best_score = score;
        for (int i = 0; i < dimensions; i++) {
            particle->best_position[i] = particle->position[i];
        }
    }
}

void Swarm_init(Swarm *swarm, int size, int dimensions, double lower_bound, double upper_bound) {
    swarm->particles = (Particle *)malloc(size * sizeof(Particle));
    swarm->global_best_position = (double *)malloc(dimensions * sizeof(double));
    swarm->global_best_score = INF;

    for (int i = 0; i < size; i++) {
        Particle_init(&swarm->particles[i], dimensions, lower_bound, upper_bound);
    }

    for (int i = 0; i < dimensions; i++) {
        swarm->global_best_position[i] = ((double)rand() / RAND_MAX) * (upper_bound - lower_bound) + lower_bound;
    }
}

void Swarm_update_global_best(Swarm *swarm, int size, int dimensions) {
    for (int i = 0; i < size; i++) {
        if (swarm->particles[i].best_score < swarm->global_best_score) {
            swarm->global_best_score = swarm->particles[i].best_score;
            for (int j = 0; j < dimensions; j++) {
                swarm->global_best_position[j] = swarm->particles[i].best_position[j];
            }
        }
    }
}

void Swarm_iterate(Swarm *swarm, int size, double (*fitness_function)(double *), int dimensions, double w, double c1, double c2) {
    for (int i = 0; i < size; i++) {
        Particle_update_velocity(&swarm->particles[i], swarm->global_best_position, dimensions, w, c1, c2);
        Particle_update_position(&swarm->particles[i], dimensions);
        Particle_evaluate(&swarm->particles[i], fitness_function, dimensions);
    }
    Swarm_update_global_best(swarm, size, dimensions);
}

double fitness_function(double *position) {
    double sum = 0;
    for (int i = 0; i < 2; i++) {
        sum += position[i] * position[i];
    }
    return sum;
}

void main() {
    int dimensions = 2;
    double lower_bound = -10;
    double upper_bound = 10;
    int swarm_size = 30;
    double w = 0.7;
    double c1 = 1.5;
    double c2 = 1.5;
    int iterations = 100;
    Swarm swarm;

    srand(time(0));
    Swarm_init(&swarm, swarm_size, dimensions, lower_bound, upper_bound);

    for (int i = 0; i < iterations; i++) {
        Swarm_iterate(&swarm, swarm_size, fitness_function, dimensions, w, c1, c2);
    }

    printf("Global best score: %f\n", swarm.global_best_score);
    printf("Global best position: %f, %f\n", swarm.global_best_position[0], swarm.global_best_position[1]);

    for (int i = 0; i < swarm_size; i++) {
        free(swarm.particles[i].position);
        free(swarm.particles[i].velocity);
        free(swarm.particles[i].best_position);
    }
    free(swarm.particles);
    free(swarm.global_best_position);
}