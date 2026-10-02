#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define INF (1.0 / 0.0)

typedef struct {
    double *position;
    double *velocity;
    double *best_position;
    double best_fitness;
} Particle;

typedef struct {
    Particle *population;
    double *gbest_position;
    double gbest_fitness;
    int dimensions;
    int population_size;
    double omega;
    double phi_p;
    double phi_g;
} PSO;

double random_uniform(double min, double max) {
    return min + (max - min) * ((double)rand() / RAND_MAX);
}

void particle_init(Particle *particle, int dimensions) {
    particle->position = (double *)malloc(dimensions * sizeof(double));
    particle->velocity = (double *)malloc(dimensions * sizeof(double));
    particle->best_position = (double *)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        particle->position[i] = random_uniform(-1, 1);
        particle->velocity[i] = random_uniform(-1, 1);
        particle->best_position[i] = particle->position[i];
    }
    particle->best_fitness = INF;
}

void pso_init(PSO *pso, int dimensions, int population_size, double omega, double phi_p, double phi_g) {
    pso->dimensions = dimensions;
    pso->population_size = population_size;
    pso->population = (Particle *)malloc(population_size * sizeof(Particle));
    for (int i = 0; i < population_size; i++) {
        particle_init(&pso->population[i], dimensions);
    }
    pso->gbest_position = (double *)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        pso->gbest_position[i] = 0;
    }
    pso->gbest_fitness = INF;
    pso->omega = omega;
    pso->phi_p = phi_p;
    pso->phi_g = phi_g;
}

void update_global_best(PSO *pso) {
    for (int i = 0; i < pso->population_size; i++) {
        Particle *particle = &pso->population[i];
        double fitness = 0;
        for (int j = 0; j < pso->dimensions; j++) {
            fitness += particle->position[j] * particle->position[j];
        }
        if (fitness < particle->best_fitness) {
            particle->best_fitness = fitness;
            for (int j = 0; j < pso->dimensions; j++) {
                particle->best_position[j] = particle->position[j];
            }
        }
        if (fitness < pso->gbest_fitness) {
            pso->gbest_fitness = fitness;
            for (int j = 0; j < pso->dimensions; j++) {
                pso->gbest_position[j] = particle->position[j];
            }
        }
    }
}

void update_velocity(PSO *pso, Particle *particle) {
    for (int i = 0; i < pso->dimensions; i++) {
        double r_p = random_uniform(0, 1);
        double r_g = random_uniform(0, 1);
        double cognitive = pso->phi_p * r_p * (particle->best_position[i] - particle->position[i]);
        double social = pso->phi_g * r_g * (pso->gbest_position[i] - particle->position[i]);
        particle->velocity[i] = pso->omega * particle->velocity[i] + cognitive + social;
    }
}

void update_position(PSO *pso, Particle *particle) {
    for (int i = 0; i < pso->dimensions; i++) {
        particle->position[i] += particle->velocity[i];
    }
}

void pso_run(PSO *pso) {
    while (1) {
        update_global_best(pso);
        for (int i = 0; i < pso->population_size; i++) {
            update_velocity(pso, &pso->population[i]);
            update_position(pso, &pso->population[i]);
        }
    }
}

void main() {
    int dimensions = 2;
    int population_size = 10;
    double omega = 0.7;
    double phi_p = 1.5;
    double phi_g = 1.5;
    PSO pso;
    srand(time(NULL));
    pso_init(&pso, dimensions, population_size, omega, phi_p, phi_g);
    pso_run(&pso);
}