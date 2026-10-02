#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double *position;
    double *velocity;
    double *best_position;
    double best_fitness;
} Particle;

double random_uniform(double lb, double ub) {
    return lb + (ub - lb) * ((double)rand() / RAND_MAX);
}

void particle_init(Particle *particle, int dim, double lb, double ub) {
    particle->position = (double *)malloc(dim * sizeof(double));
    particle->velocity = (double *)malloc(dim * sizeof(double));
    particle->best_position = (double *)malloc(dim * sizeof(double));
    for (int i = 0; i < dim; i++) {
        particle->position[i] = random_uniform(lb, ub);
        particle->velocity[i] = random_uniform(-1, 1);
        particle->best_position[i] = particle->position[i];
    }
    particle->best_fitness = INFINITY;
}

void particle_update_velocity(Particle *particle, double *global_best, int dim, double w, double c1, double c2) {
    for (int i = 0; i < dim; i++) {
        double r1 = (double)rand() / RAND_MAX;
        double r2 = (double)rand() / RAND_MAX;
        double cognitive = c1 * r1 * (particle->best_position[i] - particle->position[i]);
        double social = c2 * r2 * (global_best[i] - particle->position[i]);
        particle->velocity[i] = w * particle->velocity[i] + cognitive + social;
    }
}

void particle_update_position(Particle *particle, int dim, double lb, double ub) {
    for (int i = 0; i < dim; i++) {
        particle->position[i] += particle->velocity[i];
        if (particle->position[i] < lb) {
            particle->position[i] = lb;
        }
        if (particle->position[i] > ub) {
            particle->position[i] = ub;
        }
    }
}

double fitness_function(double *x, int dim) {
    double sum = 0.0;
    for (int i = 0; i < dim; i++) {
        sum += x[i] * x[i];
    }
    return sum;
}

void optimize(int dim, double lb, double ub, int num_particles, double w, double c1, double c2, int max_iter) {
    Particle *particles = (Particle *)malloc(num_particles * sizeof(Particle));
    for (int i = 0; i < num_particles; i++) {
        particle_init(&particles[i], dim, lb, ub);
    }
    double *global_best = (double *)malloc(dim * sizeof(double));
    double global_best_fitness = INFINITY;
    for (int iter = 0; iter < max_iter; iter++) {
        for (int i = 0; i < num_particles; i++) {
            double current_fitness = fitness_function(particles[i].position, dim);
            if (current_fitness < particles[i].best_fitness) {
                particles[i].best_fitness = current_fitness;
                for (int j = 0; j < dim; j++) {
                    particles[i].best_position[j] = particles[i].position[j];
                }
            }
            if (current_fitness < global_best_fitness) {
                global_best_fitness = current_fitness;
                for (int j = 0; j < dim; j++) {
                    global_best[j] = particles[i].position[j];
                }
            }
        }
        for (int i = 0; i < num_particles; i++) {
            particle_update_velocity(&particles[i], global_best, dim, w, c1, c2);
            particle_update_position(&particles[i], dim, lb, ub);
        }
    }
    printf("Best position: ");
    for (int i = 0; i < dim; i++) {
        printf("%f ", global_best[i]);
    }
    printf("\nBest fitness: %f\n", global_best_fitness);
    for (int i = 0; i < num_particles; i++) {
        free(particles[i].position);
        free(particles[i].velocity);
        free(particles[i].best_position);
    }
    free(particles);
    free(global_best);
}

int main() {
    int dim = 30;
    double lb = -100, ub = 100;
    int num_particles = 50;
    double w = 0.7, c1 = 1.5, c2 = 1.5;
    int max_iter = 10000;
    srand(time(NULL));
    optimize(dim, lb, ub, num_particles, w, c1, c2, max_iter);
    return 0;
}