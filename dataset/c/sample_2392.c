#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    double* position;
    double* velocity;
    double* best_position;
    double fitness;
} Particle;

Particle* initialize_particles(int num_particles, int dimensions) {
    Particle* particles = (Particle*)malloc(num_particles * sizeof(Particle));
    for (int i = 0; i < num_particles; i++) {
        particles[i].position = (double*)malloc(dimensions * sizeof(double));
        particles[i].velocity = (double*)malloc(dimensions * sizeof(double));
        particles[i].best_position = (double*)malloc(dimensions * sizeof(double));
        for (int j = 0; j < dimensions; j++) {
            particles[i].position[j] = (double)rand() / RAND_MAX * 20 - 10;
            particles[i].velocity[j] = (double)rand() / RAND_MAX * 2 - 1;
            particles[i].best_position[j] = particles[i].position[j];
        }
        particles[i].fitness = 0.0;
    }
    return particles;
}

void evaluate_fitness(Particle* particles, int num_particles, double (*fitness_function)(double*)) {
    for (int i = 0; i < num_particles; i++) {
        particles[i].fitness = fitness_function(particles[i].position);
    }
}

void update_particles(Particle* particles, int num_particles, double* global_best_position, int dimensions, double inertia_weight, double cognitive_weight, double social_weight) {
    for (int i = 0; i < num_particles; i++) {
        for (int j = 0; j < dimensions; j++) {
            double r1 = (double)rand() / RAND_MAX;
            double r2 = (double)rand() / RAND_MAX;
            double cognitive_velocity = cognitive_weight * r1 * (particles[i].best_position[j] - particles[i].position[j]);
            double social_velocity = social_weight * r2 * (global_best_position[j] - particles[i].position[j]);
            particles[i].velocity[j] = inertia_weight * particles[i].velocity[j] + cognitive_velocity + social_velocity;
            particles[i].position[j] += particles[i].velocity[j];
        }
        double current_fitness = fitness_function(particles[i].position);
        double best_fitness = fitness_function(particles[i].best_position);
        if (current_fitness < best_fitness) {
            for (int j = 0; j < dimensions; j++) {
                particles[i].best_position[j] = particles[i].position[j];
            }
        }
    }
}

double* find_global_best(Particle* particles, int num_particles, int dimensions) {
    int best_index = 0;
    double best_fitness = particles[0].fitness;
    for (int i = 1; i < num_particles; i++) {
        if (particles[i].fitness < best_fitness) {
            best_index = i;
            best_fitness = particles[i].fitness;
        }
    }
    return particles[best_index].position;
}

double fitness_function(double* position, int dimensions) {
    double sum = 0.0;
    for (int i = 0; i < dimensions; i++) {
        sum += position[i] * position[i];
    }
    return sum;
}

int main() {
    srand(time(NULL));
    int num_particles = 30;
    int dimensions = 2;
    double inertia_weight = 0.7;
    double cognitive_weight = 1.5;
    double social_weight = 1.5;
    Particle* particles = initialize_particles(num_particles, dimensions);

    while (1) {
        evaluate_fitness(particles, num_particles, fitness_function);
        double* global_best_position = find_global_best(particles, num_particles, dimensions);
        update_particles(particles, num_particles, global_best_position, dimensions, inertia_weight, cognitive_weight, social_weight);
    }

    // Free allocated memory (not reached due to infinite loop)
    for (int i = 0; i < num_particles; i++) {
        free(particles[i].position);
        free(particles[i].velocity);
        free(particles[i].best_position);
    }
    free(particles);

    return 0;
}