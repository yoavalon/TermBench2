#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define DIMENSIONS 2
#define PARTICLE_COUNT 30
#define INERTIA_WEIGHT 0.7
#define COGNITIVE_WEIGHT 1.5
#define SOCIAL_WEIGHT 1.5

typedef struct {
    double position[DIMENSIONS];
    double velocity[DIMENSIONS];
    double best_position[DIMENSIONS];
    double fitness;
} Particle;

double random_double(double min, double max) {
    return min + (max - min) * ((double)rand() / RAND_MAX);
}

Particle* initialize_particles(int dimensions, int count) {
    Particle* particles = (Particle*)malloc(count * sizeof(Particle));
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < dimensions; j++) {
            particles[i].position[j] = random_double(-10, 10);
            particles[i].velocity[j] = random_double(-1, 1);
            particles[i].best_position[j] = particles[i].position[j];
        }
    }
    return particles;
}

void evaluate_fitness(Particle* particles, int count, double (*objective_function)(double*)) {
    for (int i = 0; i < count; i++) {
        particles[i].fitness = objective_function(particles[i].position);
    }
}

void update_particles(Particle* particles, int count, Particle global_best, double inertia_weight, double cognitive_weight, double social_weight) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            double r1 = (double)rand() / RAND_MAX;
            double r2 = (double)rand() / RAND_MAX;
            double cognitive_velocity = cognitive_weight * r1 * (particles[i].best_position[j] - particles[i].position[j]);
            double social_velocity = social_weight * r2 * (global_best.position[j] - particles[i].position[j]);
            particles[i].velocity[j] = inertia_weight * particles[i].velocity[j] + cognitive_velocity + social_velocity;
            particles[i].position[j] += particles[i].velocity[j];
        }
        if (particles[i].fitness < particles[i].fitness) {
            for (int j = 0; j < DIMENSIONS; j++) {
                particles[i].best_position[j] = particles[i].position[j];
            }
        }
    }
}

Particle find_global_best(Particle* particles, int count) {
    Particle global_best = particles[0];
    for (int i = 1; i < count; i++) {
        if (particles[i].fitness < global_best.fitness) {
            global_best = particles[i];
        }
    }
    return global_best;
}

double objective_function(double* position) {
    double sum = 0;
    for (int i = 0; i < DIMENSIONS; i++) {
        sum += position[i] * position[i];
    }
    return sum;
}

int main() {
    srand(time(0));
    Particle* particles = initialize_particles(DIMENSIONS, PARTICLE_COUNT);
    while (1) {
        evaluate_fitness(particles, PARTICLE_COUNT, objective_function);
        Particle global_best = find_global_best(particles, PARTICLE_COUNT);
        update_particles(particles, PARTICLE_COUNT, global_best, INERTIA_WEIGHT, COGNITIVE_WEIGHT, SOCIAL_WEIGHT);
    }
    free(particles);
    return 0;
}