#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define INF 1e9

typedef struct {
    double* position;
    double* velocity;
    double* best_position;
    double best_value;
} Particle;

typedef struct {
    Particle* particles;
    double* global_best;
    double global_best_value;
} Swarm;

double objective_function(double* x, int dimensions) {
    double sum = 0.0;
    for (int i = 0; i < dimensions; i++) {
        sum += x[i] * x[i];
    }
    return sum;
}

void particle_init(Particle* particle, int dimensions) {
    particle->position = (double*)malloc(dimensions * sizeof(double));
    particle->velocity = (double*)malloc(dimensions * sizeof(double));
    particle->best_position = (double*)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        particle->position[i] = ((double)rand() / RAND_MAX) * 2 - 1;
        particle->velocity[i] = ((double)rand() / RAND_MAX) * 2 - 1;
        particle->best_position[i] = particle->position[i];
    }
    particle->best_value = INF;
}

void update_velocity(Particle* particle, double* global_best, int dimensions, double w, double c1, double c2) {
    for (int i = 0; i < dimensions; i++) {
        double r1 = (double)rand() / RAND_MAX;
        double r2 = (double)rand() / RAND_MAX;
        double cognitive = c1 * r1 * (particle->best_position[i] - particle->position[i]);
        double social = c2 * r2 * (global_best[i] - particle->position[i]);
        particle->velocity[i] = w * particle->velocity[i] + cognitive + social;
    }
}

void update_position(Particle* particle, int dimensions) {
    for (int i = 0; i < dimensions; i++) {
        particle->position[i] += particle->velocity[i];
    }
}

void evaluate(Particle* particle, double (*objective_function)(double*, int), int dimensions) {
    particle->best_value = objective_function(particle->position, dimensions);
    if (particle->best_value < particle->best_value) {
        for (int i = 0; i < dimensions; i++) {
            particle->best_position[i] = particle->position[i];
        }
    }
}

void swarm_init(Swarm* swarm, int dimensions, int num_particles) {
    swarm->particles = (Particle*)malloc(num_particles * sizeof(Particle));
    swarm->global_best = (double*)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        swarm->global_best[i] = INF;
    }
    swarm->global_best_value = INF;
    for (int i = 0; i < num_particles; i++) {
        particle_init(&swarm->particles[i], dimensions);
    }
}

void update_global_best(Swarm* swarm, int dimensions) {
    for (int i = 0; i < swarm->num_particles; i++) {
        if (swarm->particles[i].best_value < swarm->global_best_value) {
            swarm->global_best_value = swarm->particles[i].best_value;
            for (int j = 0; j < dimensions; j++) {
                swarm->global_best[j] = swarm->particles[i].best_position[j];
            }
        }
    }
}

void iterate(Swarm* swarm, double (*objective_function)(double*, int), int dimensions) {
    for (int i = 0; i < swarm->num_particles; i++) {
        update_velocity(&swarm->particles[i], swarm->global_best, dimensions, 0.7, 1.5, 1.5);
        update_position(&swarm->particles[i], dimensions);
        evaluate(&swarm->particles[i], objective_function, dimensions);
    }
    update_global_best(swarm, dimensions);
}

double* optimize(int dimensions, int num_particles, int max_iterations) {
    Swarm swarm;
    swarm.num_particles = num_particles;
    swarm_init(&swarm, dimensions, num_particles);
    for (int i = 0; i < max_iterations; i++) {
        iterate(&swarm, objective_function, dimensions);
    }
    return swarm.global_best;
}

void main() {
    srand(time(0));
    int dimensions = 10;
    int num_particles = 20;
    int max_iterations = 100;
    double* best_solution = optimize(dimensions, num_particles, max_iterations);
    printf("Best solution: ");
    for (int i = 0; i < dimensions; i++) {
        printf("%f ", best_solution[i]);
    }
    printf("\n");
}