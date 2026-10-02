#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double* position;
    double* velocity;
    double* best_pos;
    double best_score;
} Particle;

typedef struct {
    Particle* particles;
    double* global_best;
    double global_best_score;
    int dim;
    int num_particles;
    double** bounds;
} Swarm;

double random_double(double min, double max) {
    return min + (max - min) * ((double)rand() / RAND_MAX);
}

Particle* create_particle(int dim, double** bounds) {
    Particle* particle = (Particle*)malloc(sizeof(Particle));
    particle->position = (double*)malloc(dim * sizeof(double));
    particle->velocity = (double*)malloc(dim * sizeof(double));
    particle->best_pos = (double*)malloc(dim * sizeof(double));
    particle->best_score = INFINITY;

    for (int i = 0; i < dim; i++) {
        particle->position[i] = random_double(bounds[i][0], bounds[i][1]);
        particle->velocity[i] = random_double(-1.0, 1.0);
        particle->best_pos[i] = particle->position[i];
    }

    return particle;
}

void update_velocity(Particle* particle, double* global_best, int dim, double w, double c1, double c2) {
    for (int i = 0; i < dim; i++) {
        double r1 = (double)rand() / RAND_MAX;
        double r2 = (double)rand() / RAND_MAX;
        double cognitive = c1 * r1 * (particle->best_pos[i] - particle->position[i]);
        double social = c2 * r2 * (global_best[i] - particle->position[i]);
        particle->velocity[i] = w * particle->velocity[i] + cognitive + social;
    }
}

void update_position(Particle* particle, int dim, double** bounds) {
    for (int i = 0; i < dim; i++) {
        particle->position[i] += particle->velocity[i];
        particle->position[i] = fmax(bounds[i][0], fmin(particle->position[i], bounds[i][1]));
    }
}

Swarm* create_swarm(int dim, int num_particles, double** bounds) {
    Swarm* swarm = (Swarm*)malloc(sizeof(Swarm));
    swarm->particles = (Particle*)malloc(num_particles * sizeof(Particle));
    swarm->global_best = (double*)malloc(dim * sizeof(double));
    swarm->global_best_score = INFINITY;
    swarm->dim = dim;
    swarm->num_particles = num_particles;
    swarm->bounds = bounds;

    for (int i = 0; i < num_particles; i++) {
        swarm->particles[i] = *create_particle(dim, bounds);
    }

    for (int i = 0; i < dim; i++) {
        swarm->global_best[i] = INFINITY;
    }

    return swarm;
}

void update_global_best(Swarm* swarm) {
    for (int i = 0; i < swarm->num_particles; i++) {
        double score = 0.0;
        for (int j = 0; j < swarm->dim; j++) {
            score += swarm->particles[i].position[j] * swarm->particles[i].position[j];
        }
        if (score < swarm->global_best_score) {
            for (int j = 0; j < swarm->dim; j++) {
                swarm->global_best[j] = swarm->particles[i].position[j];
            }
            swarm->global_best_score = score;
            swarm->particles[i].best_score = score;
            for (int j = 0; j < swarm->dim; j++) {
                swarm->particles[i].best_pos[j] = swarm->particles[i].position[j];
            }
        }
    }
}

void run(Swarm* swarm, int iterations) {
    for (int i = 0; i < iterations; i++) {
        for (int j = 0; j < swarm->num_particles; j++) {
            update_velocity(&swarm->particles[j], swarm->global_best, swarm->dim, 0.7, 1.5, 1.5);
            update_position(&swarm->particles[j], swarm->dim, swarm->bounds);
        }
        update_global_best(swarm);
    }
}

void main() {
    int dim = 3;
    int num_particles = 20;
    double** bounds = (double**)malloc(dim * sizeof(double*));
    for (int i = 0; i < dim; i++) {
        bounds[i] = (double*)malloc(2 * sizeof(double));
        bounds[i][0] = -10.0;
        bounds[i][1] = 10.0;
    }

    Swarm* swarm = create_swarm(dim, num_particles, bounds);
    run(swarm, 100);

    printf("Global Best Position: ");
    for (int i = 0; i < dim; i++) {
        printf("%f ", swarm->global_best[i]);
    }
    printf("\nGlobal Best Score: %f\n", swarm->global_best_score);

    for (int i = 0; i < dim; i++) {
        free(bounds[i]);
    }
    free(bounds);
    for (int i = 0; i < swarm->num_particles; i++) {
        free(swarm->particles[i].position);
        free(swarm->particles[i].velocity);
        free(swarm->particles[i].best_pos);
    }
    free(swarm->particles);
    free(swarm->global_best);
    free(swarm);
}