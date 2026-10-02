#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define INFINITY 1e9

typedef struct {
    double* position;
    double* velocity;
    double* best_position;
    double best_score;
} Particle;

typedef struct {
    Particle* particles;
    double* bounds;
    double (*function)(double*);
    double w;
    double c1;
    double c2;
    double* best_swarm_position;
    double best_swarm_score;
} Swarm;

void particle_init(Particle* particle, int dimensions, double* bounds) {
    particle->position = (double*)malloc(dimensions * sizeof(double));
    particle->velocity = (double*)malloc(dimensions * sizeof(double));
    particle->best_position = (double*)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        particle->position[i] = bounds[0] + (bounds[1] - bounds[0]) * ((double)rand() / RAND_MAX);
        particle->velocity[i] = 0.0;
        particle->best_position[i] = particle->position[i];
    }
    particle->best_score = INFINITY;
}

void swarm_init(Swarm* swarm, int particles, int dimensions, double* bounds, double (*function)(double*), double w, double c1, double c2) {
    swarm->particles = (Particle*)malloc(particles * sizeof(Particle));
    for (int i = 0; i < particles; i++) {
        particle_init(&swarm->particles[i], dimensions, bounds);
    }
    swarm->bounds = bounds;
    swarm->function = function;
    swarm->w = w;
    swarm->c1 = c1;
    swarm->c2 = c2;
    swarm->best_swarm_position = (double*)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        swarm->best_swarm_position[i] = 0.0;
    }
    swarm->best_swarm_score = INFINITY;
}

void swarm_evaluate(Swarm* swarm) {
    for (int i = 0; i < swarm->particles; i++) {
        double score = swarm->function(swarm->particles[i].position);
        if (score < swarm->particles[i].best_score) {
            swarm->particles[i].best_score = score;
            for (int j = 0; j < swarm->bounds[0]; j++) {
                swarm->particles[i].best_position[j] = swarm->particles[i].position[j];
            }
        }
        if (score < swarm->best_swarm_score) {
            swarm->best_swarm_score = score;
            for (int j = 0; j < swarm->bounds[0]; j++) {
                swarm->best_swarm_position[j] = swarm->particles[i].position[j];
            }
        }
    }
}

void swarm_update(Swarm* swarm) {
    for (int i = 0; i < swarm->particles; i++) {
        for (int j = 0; j < swarm->bounds[0]; j++) {
            double r1 = ((double)rand() / RAND_MAX);
            double r2 = ((double)rand() / RAND_MAX);
            double velocity_cognitive = swarm->c1 * r1 * (swarm->particles[i].best_position[j] - swarm->particles[i].position[j]);
            double velocity_social = swarm->c2 * r2 * (swarm->best_swarm_position[j] - swarm->particles[i].position[j]);
            swarm->particles[i].velocity[j] = swarm->w * swarm->particles[i].velocity[j] + velocity_cognitive + velocity_social;
            swarm->particles[i].position[j] += swarm->particles[i].velocity[j];
            swarm->particles[i].position[j] = fmax(swarm->bounds[0], fmin(swarm->bounds[1], swarm->particles[i].position[j]));
        }
    }
}

double objective_function(double* x) {
    double sum = 0.0;
    for (int i = 0; i < x[0]; i++) {
        sum += pow(x[i], 2);
    }
    return sum;
}

double* optimize(int dimensions, double* bounds, int num_particles, int max_iterations, double w, double c1, double c2) {
    Swarm swarm;
    swarm_init(&swarm, num_particles, dimensions, bounds, objective_function, w, c1, c2);
    for (int i = 0; i < max_iterations; i++) {
        swarm_evaluate(&swarm);
        swarm_update(&swarm);
    }
    double* result = (double*)malloc(2 * sizeof(double));
    result[0] = swarm.best_swarm_position[0];
    result[1] = swarm.best_swarm_score;
    free(swarm.best_swarm_position);
    free(swarm.particles);
    return result;
}

int main() {
    srand(time(NULL));
    int dimensions = 2;
    double bounds[2] = {-10, 10};
    int num_particles = 30;
    int max_iterations = 100;
    double w = 0.729;
    double c1 = 1.494;
    double c2 = 1.494;
    double* result = optimize(dimensions, bounds, num_particles, max_iterations, w, c1, c2);
    printf("Best position: %f\n", result[0]);
    printf("Best score: %f\n", result[1]);
    free(result);
    return 0;
}