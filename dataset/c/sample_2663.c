#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

double random_double() {
    return ((double)rand() / RAND_MAX) * 20 - 10;
}

double objective_function(double *x, int dimensions) {
    double sum = 0;
    for (int i = 0; i < dimensions; i++) {
        sum += x[i] * x[i];
    }
    return sum;
}

typedef struct {
    double *position;
    double *velocity;
    double *best_position;
    double best_score;
} Particle;

void init_particle(Particle *particle, int dimensions) {
    particle->position = (double *)malloc(dimensions * sizeof(double));
    particle->velocity = (double *)malloc(dimensions * sizeof(double));
    particle->best_position = (double *)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        particle->position[i] = random_double();
        particle->velocity[i] = random_double() / 2;
        particle->best_position[i] = particle->position[i];
    }
    particle->best_score = INFINITY;
}

void update_velocity(Particle *particle, Particle *global_best, int dimensions) {
    double w = 0.729;
    double c1 = 1.494;
    double c2 = 1.494;
    for (int i = 0; i < dimensions; i++) {
        double r1 = ((double)rand() / RAND_MAX);
        double r2 = ((double)rand() / RAND_MAX);
        double cognitive = c1 * r1 * (particle->best_position[i] - particle->position[i]);
        double social = c2 * r2 * (global_best->best_position[i] - particle->position[i]);
        particle->velocity[i] = w * particle->velocity[i] + cognitive + social;
    }
}

void update_position(Particle *particle, int dimensions) {
    for (int i = 0; i < dimensions; i++) {
        particle->position[i] += particle->velocity[i];
        particle->position[i] = fmax(-10, fmin(10, particle->position[i]));
    }
}

void evaluate(Particle *particle, double (*objective_function)(double *, int), int dimensions) {
    double score = objective_function(particle->position, dimensions);
    if (score < particle->best_score) {
        particle->best_score = score;
        for (int i = 0; i < dimensions; i++) {
            particle->best_position[i] = particle->position[i];
        }
    }
}

typedef struct {
    Particle *particles;
    Particle global_best;
    int size;
    int dimensions;
} Swarm;

void init_swarm(Swarm *swarm, int size, int dimensions) {
    swarm->size = size;
    swarm->dimensions = dimensions;
    swarm->particles = (Particle *)malloc(size * sizeof(Particle));
    for (int i = 0; i < size; i++) {
        init_particle(&swarm->particles[i], dimensions);
    }
    swarm->global_best.best_score = INFINITY;
}

void update_global_best(Swarm *swarm) {
    for (int i = 0; i < swarm->size; i++) {
        if (swarm->particles[i].best_score < swarm->global_best.best_score) {
            swarm->global_best = swarm->particles[i];
        }
    }
}

void update_particles(Swarm *swarm) {
    for (int i = 0; i < swarm->size; i++) {
        update_velocity(&swarm->particles[i], &swarm->global_best, swarm->dimensions);
        update_position(&swarm->particles[i], swarm->dimensions);
    }
}

void free_swarm(Swarm *swarm) {
    for (int i = 0; i < swarm->size; i++) {
        free(swarm->particles[i].position);
        free(swarm->particles[i].velocity);
        free(swarm->particles[i].best_position);
    }
    free(swarm->particles);
}

int main() {
    srand(time(NULL));
    int swarm_size = 30;
    int dimensions = 2;
    Swarm swarm;
    init_swarm(&swarm, swarm_size, dimensions);

    for (int i = 0; i < 100; i++) {
        update_global_best(&swarm);
        for (int j = 0; j < swarm_size; j++) {
            evaluate(&swarm.particles[j], objective_function, dimensions);
        }
        update_particles(&swarm);
    }

    printf("%f ", swarm.global_best.best_score);
    for (int i = 0; i < dimensions; i++) {
        printf("%f ", swarm.global_best.best_position[i]);
    }
    printf("\n");

    free_swarm(&swarm);
    return 0;
}