#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    double *position;
    double *velocity;
    double *best_position;
    double best_fitness;
} Particle;

typedef struct {
    Particle *particles;
    double *global_best_position;
    double global_best_fitness;
} Swarm;

void particle_init(Particle *particle, int dimensions, double lower_bound, double upper_bound) {
    particle->position = (double *)malloc(dimensions * sizeof(double));
    particle->velocity = (double *)malloc(dimensions * sizeof(double));
    particle->best_position = (double *)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        particle->position[i] = lower_bound + ((double)rand() / RAND_MAX) * (upper_bound - lower_bound);
        particle->velocity[i] = -1 + ((double)rand() / RAND_MAX) * 2;
        particle->best_position[i] = particle->position[i];
    }
    particle->best_fitness = INFINITY;
}

void particle_update_velocity(Particle *particle, double *global_best_position, int dimensions, double w, double c1, double c2) {
    for (int i = 0; i < dimensions; i++) {
        double r1 = (double)rand() / RAND_MAX;
        double r2 = (double)rand() / RAND_MAX;
        double cognitive_velocity = c1 * r1 * (particle->best_position[i] - particle->position[i]);
        double social_velocity = c2 * r2 * (global_best_position[i] - particle->position[i]);
        particle->velocity[i] = w * particle->velocity[i] + cognitive_velocity + social_velocity;
    }
}

void particle_update_position(Particle *particle, int dimensions, double lower_bound, double upper_bound) {
    for (int i = 0; i < dimensions; i++) {
        particle->position[i] += particle->velocity[i];
        particle->position[i] = fmax(lower_bound, fmin(upper_bound, particle->position[i]));
    }
}

void swarm_init(Swarm *swarm, int num_particles, int dimensions, double lower_bound, double upper_bound) {
    swarm->particles = (Particle *)malloc(num_particles * sizeof(Particle));
    for (int i = 0; i < num_particles; i++) {
        particle_init(&swarm->particles[i], dimensions, lower_bound, upper_bound);
    }
    swarm->global_best_position = (double *)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        swarm->global_best_position[i] = lower_bound + ((double)rand() / RAND_MAX) * (upper_bound - lower_bound);
    }
    swarm->global_best_fitness = INFINITY;
}

void swarm_evaluate_fitness(Swarm *swarm, int dimensions, double (*objective_function)(double *)) {
    for (int i = 0; i < num_particles; i++) {
        double fitness = objective_function(swarm->particles[i].position);
        if (fitness < swarm->particles[i].best_fitness) {
            swarm->particles[i].best_fitness = fitness;
            for (int j = 0; j < dimensions; j++) {
                swarm->particles[i].best_position[j] = swarm->particles[i].position[j];
            }
        }
        if (fitness < swarm->global_best_fitness) {
            swarm->global_best_fitness = fitness;
            for (int j = 0; j < dimensions; j++) {
                swarm->global_best_position[j] = swarm->particles[i].position[j];
            }
        }
    }
}

void swarm_update_particles(Swarm *swarm, int dimensions, double w, double c1, double c2) {
    for (int i = 0; i < num_particles; i++) {
        particle_update_velocity(&swarm->particles[i], swarm->global_best_position, dimensions, w, c1, c2);
        particle_update_position(&swarm->particles[i], dimensions, -10, 10);
    }
}

double objective_function(double *x, int dimensions) {
    double result = 0.0;
    for (int i = 0; i < dimensions; i++) {
        result += sin(x[i]) * sin(x[i] + (i + 1) * M_PI / dimensions);
    }
    return result;
}

int main() {
    srand(time(NULL));
    int num_particles = 30;
    int dimensions = 30;
    double lower_bound = -10;
    double upper_bound = 10;
    double w = 0.729;
    double c1 = 1.494;
    double c2 = 1.494;
    Swarm swarm;
    swarm_init(&swarm, num_particles, dimensions, lower_bound, upper_bound);
    while (1) {
        swarm_evaluate_fitness(&swarm, dimensions, objective_function);
        swarm_update_particles(&swarm, dimensions, w, c1, c2);
    }
    return 0;
}