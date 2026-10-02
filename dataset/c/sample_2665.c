#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double *position;
    double *velocity;
    double *best_position;
    double best_fitness;
} Particle;

void init_particle(Particle *particle, int dimensions, double (*bounds)[2]) {
    particle->position = (double *)malloc(dimensions * sizeof(double));
    particle->velocity = (double *)malloc(dimensions * sizeof(double));
    particle->best_position = (double *)malloc(dimensions * sizeof(double));
    particle->best_fitness = INFINITY;

    for (int i = 0; i < dimensions; i++) {
        particle->position[i] = ((double)rand() / RAND_MAX) * (bounds[i][1] - bounds[i][0]) + bounds[i][0];
        particle->velocity[i] = ((double)rand() / RAND_MAX) * 2 - 1;
        particle->best_position[i] = particle->position[i];
    }
}

void update_velocity(Particle *particle, double *global_best, int dimensions, double w, double c1, double c2) {
    for (int i = 0; i < dimensions; i++) {
        double r1 = (double)rand() / RAND_MAX;
        double r2 = (double)rand() / RAND_MAX;
        double cognitive = c1 * r1 * (particle->best_position[i] - particle->position[i]);
        double social = c2 * r2 * (global_best[i] - particle->position[i]);
        particle->velocity[i] = w * particle->velocity[i] + cognitive + social;
    }
}

void update_position(Particle *particle, int dimensions, double (*bounds)[2]) {
    for (int i = 0; i < dimensions; i++) {
        particle->position[i] += particle->velocity[i];
        particle->position[i] = fmax(bounds[i][0], fmin(particle->position[i], bounds[i][1]));
    }
}

double evaluate(Particle *particle, double (*fitness_function)(double *)) {
    double fitness = fitness_function(particle->position);
    if (fitness < particle->best_fitness) {
        particle->best_fitness = fitness;
        for (int i = 0; i < dimensions; i++) {
            particle->best_position[i] = particle->position[i];
        }
    }
    return particle->best_fitness;
}

double sphere_function(double *x) {
    double sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += x[i] * x[i];
    }
    return sum;
}

void optimize(double (*fitness_function)(double *), int dimensions, double (*bounds)[2], int num_particles, double w, double c1, double c2, int max_iterations, double *global_best, double *global_best_fitness) {
    Particle *particles = (Particle *)malloc(num_particles * sizeof(Particle));
    for (int i = 0; i < num_particles; i++) {
        init_particle(&particles[i], dimensions, bounds);
    }

    *global_best_fitness = INFINITY;
    for (int i = 0; i < dimensions; i++) {
        global_best[i] = INFINITY;
    }

    for (int iteration = 0; iteration < max_iterations; iteration++) {
        for (int i = 0; i < num_particles; i++) {
            double fitness = evaluate(&particles[i], fitness_function);
            if (fitness < *global_best_fitness) {
                *global_best_fitness = fitness;
                for (int j = 0; j < dimensions; j++) {
                    global_best[j] = particles[i].best_position[j];
                }
            }
        }
        for (int i = 0; i < num_particles; i++) {
            update_velocity(&particles[i], global_best, dimensions, w, c1, c2);
            update_position(&particles[i], dimensions, bounds);
        }
    }

    for (int i = 0; i < num_particles; i++) {
        free(particles[i].position);
        free(particles[i].velocity);
        free(particles[i].best_position);
    }
    free(particles);
}

int main() {
    srand(time(NULL));
    int dimensions = 3;
    double bounds[3][2] = { {-5.12, 5.12}, {-5.12, 5.12}, {-5.12, 5.12} };
    int num_particles = 30;
    double w = 0.729;
    double c1 = 1.494;
    double c2 = 1.494;
    int max_iterations = 100;
    double global_best[3];
    double global_best_fitness;

    optimize(sphere_function, dimensions, bounds, num_particles, w, c1, c2, max_iterations, global_best, &global_best_fitness);

    printf("Best position: (%.6f, %.6f, %.6f)\n", global_best[0], global_best[1], global_best[2]);
    printf("Best fitness: %.6f\n", global_best_fitness);

    return 0;
}