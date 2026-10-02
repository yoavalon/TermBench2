#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    int dimensions;
    int population_size;
    int max_iterations;
    double c1;
    double c2;
    double w;
} PSOSettings;

typedef struct {
    double* position;
    double* velocity;
    double* best_position;
    double best_fitness;
} Particle;

void fitness(double* position, int dimensions, double* result) {
    *result = 0.0;
    for (int i = 0; i < dimensions; i++) {
        *result += position[i] * position[i];
    }
}

void update_velocity(Particle* particle, double* global_best, PSOSettings* settings) {
    for (int i = 0; i < settings->dimensions; i++) {
        double r1 = ((double)rand() / RAND_MAX);
        double r2 = ((double)rand() / RAND_MAX);
        double cognitive = settings->c1 * r1 * (particle->best_position[i] - particle->position[i]);
        double social = settings->c2 * r2 * (global_best[i] - particle->position[i]);
        particle->velocity[i] = settings->w * particle->velocity[i] + cognitive + social;
    }
}

void update_position(Particle* particle, PSOSettings* settings) {
    for (int i = 0; i < settings->dimensions; i++) {
        particle->position[i] += particle->velocity[i];
        if (particle->position[i] < -10) {
            particle->position[i] = -10;
        } else if (particle->position[i] > 10) {
            particle->position[i] = 10;
        }
    }
}

void optimize(PSOSettings* settings, double* best_position, double* best_fitness) {
    Particle* population = (Particle*)malloc(settings->population_size * sizeof(Particle));
    for (int i = 0; i < settings->population_size; i++) {
        population[i].position = (double*)malloc(settings->dimensions * sizeof(double));
        population[i].velocity = (double*)malloc(settings->dimensions * sizeof(double));
        population[i].best_position = (double*)malloc(settings->dimensions * sizeof(double));
        for (int j = 0; j < settings->dimensions; j++) {
            population[i].position[j] = ((double)rand() / RAND_MAX) * 20 - 10;
            population[i].velocity[j] = ((double)rand() / RAND_MAX) * 2 - 1;
            population[i].best_position[j] = population[i].position[j];
        }
        population[i].best_fitness = INFINITY;
    }

    *best_fitness = INFINITY;
    for (int iteration = 0; iteration < settings->max_iterations; iteration++) {
        for (int i = 0; i < settings->population_size; i++) {
            double current_fitness;
            fitness(population[i].position, settings->dimensions, &current_fitness);
            if (current_fitness < population[i].best_fitness) {
                population[i].best_fitness = current_fitness;
                for (int j = 0; j < settings->dimensions; j++) {
                    population[i].best_position[j] = population[i].position[j];
                }
            }
            if (current_fitness < *best_fitness) {
                *best_fitness = current_fitness;
                for (int j = 0; j < settings->dimensions; j++) {
                    best_position[j] = population[i].position[j];
                }
            }
        }
        for (int i = 0; i < settings->population_size; i++) {
            update_velocity(&population[i], best_position, settings);
            update_position(&population[i], settings);
        }
    }

    for (int i = 0; i < settings->population_size; i++) {
        free(population[i].position);
        free(population[i].velocity);
        free(population[i].best_position);
    }
    free(population);
}

int main() {
    srand(time(NULL));
    PSOSettings settings = {2, 30, 100, 2.0, 2.0, 0.7};
    double best_position[2];
    double best_fitness;
    optimize(&settings, best_position, &best_fitness);
    printf("Best position: (%f, %f)\n", best_position[0], best_position[1]);
    printf("Best fitness: %f\n", best_fitness);
    return 0;
}