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

double random_double(double min, double max) {
    return min + (max - min) * ((double)rand() / RAND_MAX);
}

double evaluate(double *position, int dimensions) {
    double sum = 0.0;
    for (int i = 0; i < dimensions; i++) {
        sum += position[i] * position[i];
    }
    return sum;
}

void particle_init(Particle *particle, int dimensions) {
    particle->position = (double *)malloc(dimensions * sizeof(double));
    particle->velocity = (double *)malloc(dimensions * sizeof(double));
    particle->best_position = (double *)malloc(dimensions * sizeof(double));
    particle->best_score = INF;

    for (int i = 0; i < dimensions; i++) {
        particle->position[i] = random_double(-10, 10);
        particle->velocity[i] = random_double(-1, 1);
        particle->best_position[i] = particle->position[i];
    }
}

void swarm_init(Swarm *swarm, int num_particles, int dimensions) {
    swarm->particles = (Particle *)malloc(num_particles * sizeof(Particle));
    swarm->global_best_position = (double *)malloc(dimensions * sizeof(double));
    swarm->global_best_score = INF;

    for (int i = 0; i < dimensions; i++) {
        swarm->global_best_position[i] = 0.0;
    }

    for (int i = 0; i < num_particles; i++) {
        particle_init(&swarm->particles[i], dimensions);
    }
}

void update_global_best(Swarm *swarm, int dimensions) {
    for (int i = 0; i < dimensions; i++) {
        swarm->global_best_position[i] = 0.0;
    }
    swarm->global_best_score = INF;

    for (int i = 0; i < dimensions; i++) {
        for (int j = 0; j < num_particles; j++) {
            double score = evaluate(swarm->particles[j].position, dimensions);
            if (score < swarm->global_best_score) {
                swarm->global_best_score = score;
                for (int k = 0; k < dimensions; k++) {
                    swarm->global_best_position[k] = swarm->particles[j].position[k];
                }
            }
        }
    }
}

void update_particles(Swarm *swarm, int dimensions, double w, double c1, double c2) {
    for (int i = 0; i < dimensions; i++) {
        for (int j = 0; j < num_particles; j++) {
            double r1 = (double)rand() / RAND_MAX;
            double r2 = (double)rand() / RAND_MAX;
            for (int k = 0; k < dimensions; k++) {
                swarm->particles[j].velocity[k] = w * swarm->particles[j].velocity[k] +
                                                   c1 * r1 * (swarm->particles[j].best_position[k] - swarm->particles[j].position[k]) +
                                                   c2 * r2 * (swarm->global_best_position[k] - swarm->particles[j].position[k]);
                swarm->particles[j].position[k] += swarm->particles[j].velocity[k];
            }
            double score = evaluate(swarm->particles[j].position, dimensions);
            if (score < swarm->particles[j].best_score) {
                swarm->particles[j].best_score = score;
                for (int k = 0; k < dimensions; k++) {
                    swarm->particles[j].best_position[k] = swarm->particles[j].position[k];
                }
            }
        }
    }
}

void swarm_free(Swarm *swarm, int num_particles) {
    for (int i = 0; i < num_particles; i++) {
        free(swarm->particles[i].position);
        free(swarm->particles[i].velocity);
        free(swarm->particles[i].best_position);
    }
    free(swarm->particles);
    free(swarm->global_best_position);
}

int main() {
    srand(time(NULL));
    int dimensions = 30;
    int num_particles = 30;
    double w = 0.7;
    double c1 = 1.5;
    double c2 = 1.5;
    int iterations = 100;

    Swarm swarm;
    swarm_init(&swarm, num_particles, dimensions);

    for (int i = 0; i < iterations; i++) {
        update_global_best(&swarm, dimensions);
        update_particles(&swarm, dimensions, w, c1, c2);
    }

    printf("Best score: %f\n", swarm.global_best_score);

    swarm_free(&swarm, num_particles);
    return 0;
}