#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    double* position;
    double* velocity;
    double* best_pos;
    double best_score;
} Particle;

typedef struct {
    Particle* particles;
    double* best_global_pos;
    double best_global_score;
    int num_particles;
    int dim;
} Swarm;

void particle_init(Particle* particle, int dim) {
    particle->position = (double*)calloc(dim, sizeof(double));
    particle->velocity = (double*)calloc(dim, sizeof(double));
    particle->best_pos = (double*)calloc(dim, sizeof(double));
    particle->best_score = INFINITY;
}

void particle_update_velocity(Particle* particle, double* global_best, double w, double c1, double c2, int dim) {
    for (int i = 0; i < dim; i++) {
        double r1 = (double)rand() / RAND_MAX;
        double r2 = (double)rand() / RAND_MAX;
        particle->velocity[i] = w * particle->velocity[i] + c1 * r1 * (particle->best_pos[i] - particle->position[i]) + c2 * r2 * (global_best[i] - particle->position[i]);
    }
}

void particle_update_position(Particle* particle, double** bounds, int dim) {
    for (int i = 0; i < dim; i++) {
        particle->position[i] += particle->velocity[i];
        particle->position[i] = fmax(bounds[0][i], fmin(bounds[1][i], particle->position[i]));
    }
}

void swarm_init(Swarm* swarm, int num_particles, int dim, double** bounds) {
    swarm->particles = (Particle*)malloc(num_particles * sizeof(Particle));
    swarm->best_global_pos = (double*)calloc(dim, sizeof(double));
    swarm->best_global_score = INFINITY;
    swarm->num_particles = num_particles;
    swarm->dim = dim;
    for (int i = 0; i < num_particles; i++) {
        particle_init(&swarm->particles[i], dim);
    }
}

void swarm_update_global_best(Swarm* swarm) {
    for (int i = 0; i < swarm->num_particles; i++) {
        Particle* particle = &swarm->particles[i];
        if (particle->best_score < swarm->best_global_score) {
            swarm->best_global_score = particle->best_score;
            for (int j = 0; j < swarm->dim; j++) {
                swarm->best_global_pos[j] = particle->best_pos[j];
            }
        }
    }
}

double fitness_function(double* position, int dim) {
    double sum = 0.0;
    for (int i = 0; i < dim; i++) {
        sum += position[i] * position[i];
    }
    return sum;
}

void swarm_optimize(Swarm* swarm, double (*fitness_func)(double*, int), int max_iter, double w, double c1, double c2) {
    for (int iter = 0; iter < max_iter; iter++) {
        for (int i = 0; i < swarm->num_particles; i++) {
            Particle* particle = &swarm->particles[i];
            particle_update_velocity(particle, swarm->best_global_pos, w, c1, c2, swarm->dim);
            particle_update_position(particle, swarm->bounds, swarm->dim);
            double score = fitness_func(particle->position, swarm->dim);
            if (score < particle->best_score) {
                particle->best_score = score;
                for (int j = 0; j < swarm->dim; j++) {
                    particle->best_pos[j] = particle->position[j];
                }
            }
        }
        swarm_update_global_best(swarm);
    }
}

void main() {
    srand(time(NULL));
    int num_particles = 30;
    int dim = 2;
    double bounds[2][2] = {{0.0, 0.0}, {10.0, 10.0}};
    int max_iter = 100;
    double w = 0.7;
    double c1 = 2.0;
    double c2 = 2.0;

    Swarm swarm;
    swarm_init(&swarm, num_particles, dim, bounds);
    swarm_optimize(&swarm, fitness_function, max_iter, w, c1, c2);

    printf("Best Global Position: ");
    for (int i = 0; i < dim; i++) {
        printf("%f ", swarm.best_global_pos[i]);
    }
    printf("Best Global Score: %f\n", swarm.best_global_score);

    for (int i = 0; i < num_particles; i++) {
        free(swarm.particles[i].position);
        free(swarm.particles[i].velocity);
        free(swarm.particles[i].best_pos);
    }
    free(swarm.particles);
    free(swarm.best_global_pos);
}