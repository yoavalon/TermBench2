#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PARTICLES 20
#define NUM_DIMENSIONS 2
#define W 0.7
#define C1 1.5
#define C2 1.5
#define MAX_ITERATIONS 100

typedef struct {
    double position[NUM_DIMENSIONS];
    double velocity[NUM_DIMENSIONS];
    double best_position[NUM_DIMENSIONS];
} Particle;

void initialize_particles(Particle particles[NUM_PARTICLES], int num_dimensions) {
    for (int i = 0; i < NUM_PARTICLES; i++) {
        for (int j = 0; j < num_dimensions; j++) {
            particles[i].position[j] = ((double)rand() / RAND_MAX) * 20 - 10;
            particles[i].velocity[j] = ((double)rand() / RAND_MAX) * 2 - 1;
            particles[i].best_position[j] = particles[i].position[j];
        }
    }
}

void update_velocity(Particle particles[NUM_PARTICLES], Particle global_best, double w, double c1, double c2) {
    for (int i = 0; i < NUM_PARTICLES; i++) {
        double r1 = ((double)rand() / RAND_MAX);
        double r2 = ((double)rand() / RAND_MAX);
        for (int j = 0; j < NUM_DIMENSIONS; j++) {
            double cognitive_velocity = c1 * r1 * (particles[i].best_position[j] - particles[i].position[j]);
            double social_velocity = c2 * r2 * (global_best.best_position[j] - particles[i].position[j]);
            particles[i].velocity[j] = w * particles[i].velocity[j] + cognitive_velocity + social_velocity;
        }
    }
}

void update_position(Particle particles[NUM_PARTICLES]) {
    for (int i = 0; i < NUM_PARTICLES; i++) {
        for (int j = 0; j < NUM_DIMENSIONS; j++) {
            particles[i].position[j] += particles[i].velocity[j];
        }
    }
}

Particle evaluate_fitness(Particle particles[NUM_PARTICLES], double (*fitness_function)(double*)) {
    double min_fitness = fitness_function(particles[0].best_position);
    Particle global_best = particles[0];
    for (int i = 1; i < NUM_PARTICLES; i++) {
        double fitness = fitness_function(particles[i].position);
        if (fitness < fitness_function(particles[i].best_position)) {
            for (int j = 0; j < NUM_DIMENSIONS; j++) {
                particles[i].best_position[j] = particles[i].position[j];
            }
        }
        if (fitness < min_fitness) {
            min_fitness = fitness;
            global_best = particles[i];
        }
    }
    return global_best;
}

double fitness_function(double position[NUM_DIMENSIONS]) {
    double sum = 0;
    for (int i = 0; i < NUM_DIMENSIONS; i++) {
        sum += position[i] * position[i];
    }
    return sum;
}

int main() {
    srand(time(NULL));
    Particle particles[NUM_PARTICLES];
    initialize_particles(particles, NUM_DIMENSIONS);
    Particle global_best = evaluate_fitness(particles, fitness_function);
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        update_velocity(particles, global_best, W, C1, C2);
        update_position(particles);
        global_best = evaluate_fitness(particles, fitness_function);
    }
    printf("Best position found: [%f, %f]\n", global_best.best_position[0], global_best.best_position[1]);
    printf("Fitness value: %f\n", fitness_function(global_best.best_position));
    return 0;
}