#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double* position;
    double* velocity;
    double* best_position;
    double best_fitness;
    double max_velocity;
} Particle;

typedef struct {
    Particle* particles;
    double* global_best;
    double global_best_fitness;
    int dimensions;
    int population_size;
} Swarm;

double objective_function(double* position, int dimensions) {
    double sum = 0.0;
    for (int i = 0; i < dimensions; i++) {
        sum += position[i] * position[i];
    }
    return sum;
}

Particle* Particle_new(int dimensions, double max_velocity) {
    Particle* p = (Particle*)malloc(sizeof(Particle));
    p->position = (double*)calloc(dimensions, sizeof(double));
    p->velocity = (double*)calloc(dimensions, sizeof(double));
    p->best_position = (double*)calloc(dimensions, sizeof(double));
    p->best_fitness = INFINITY;
    p->max_velocity = max_velocity;
    return p;
}

void Particle_update_velocity(Particle* p, double* global_best, int dimensions, double w, double c1, double c2) {
    for (int i = 0; i < dimensions; i++) {
        double r1 = (double)rand() / RAND_MAX;
        double r2 = (double)rand() / RAND_MAX;
        double cognitive = c1 * r1 * (p->best_position[i] - p->position[i]);
        double social = c2 * r2 * (global_best[i] - p->position[i]);
        p->velocity[i] = w * p->velocity[i] + cognitive + social;
        p->velocity[i] = fmax(-p->max_velocity, fmin(p->velocity[i], p->max_velocity));
    }
}

void Particle_update_position(Particle* p, int dimensions) {
    for (int i = 0; i < dimensions; i++) {
        p->position[i] += p->velocity[i];
    }
}

void Particle_evaluate(Particle* p, int dimensions) {
    p->best_fitness = objective_function(p->position, dimensions);
    if (p->best_fitness < p->best_fitness) {
        p->best_fitness = p->best_fitness;
        for (int i = 0; i < dimensions; i++) {
            p->best_position[i] = p->position[i];
        }
    }
}

Swarm* Swarm_new(int dimensions, int population_size, double max_velocity) {
    Swarm* s = (Swarm*)malloc(sizeof(Swarm));
    s->particles = (Particle*)malloc(population_size * sizeof(Particle));
    s->global_best = (double*)calloc(dimensions, sizeof(double));
    s->global_best_fitness = INFINITY;
    s->dimensions = dimensions;
    s->population_size = population_size;
    for (int i = 0; i < population_size; i++) {
        s->particles[i] = *Particle_new(dimensions, max_velocity);
    }
    return s;
}

void Swarm_initialize_global_best(Swarm* s) {
    for (int i = 0; i < s->population_size; i++) {
        Particle_evaluate(&s->particles[i], s->dimensions);
        if (s->particles[i].best_fitness < s->global_best_fitness) {
            s->global_best_fitness = s->particles[i].best_fitness;
            for (int j = 0; j < s->dimensions; j++) {
                s->global_best[j] = s->particles[i].best_position[j];
            }
        }
    }
}

void Swarm_update_swarm(Swarm* s, double w, double c1, double c2) {
    for (int i = 0; i < s->population_size; i++) {
        Particle_update_velocity(&s->particles[i], s->global_best, s->dimensions, w, c1, c2);
        Particle_update_position(&s->particles[i], s->dimensions);
        Particle_evaluate(&s->particles[i], s->dimensions);
        if (s->particles[i].best_fitness < s->global_best_fitness) {
            s->global_best_fitness = s->particles[i].best_fitness;
            for (int j = 0; j < s->dimensions; j++) {
                s->global_best[j] = s->particles[i].best_position[j];
            }
        }
    }
}

double optimize(int dimensions, int population_size, double max_velocity, double w, double c1, double c2, int max_iterations) {
    Swarm* swarm = Swarm_new(dimensions, population_size, max_velocity);
    Swarm_initialize_global_best(swarm);
    for (int i = 0; i < max_iterations; i++) {
        Swarm_update_swarm(swarm, w, c1, c2);
    }
    double best_fitness = swarm->global_best_fitness;
    for (int i = 0; i < population_size; i++) {
        free(swarm->particles[i].position);
        free(swarm->particles[i].velocity);
        free(swarm->particles[i].best_position);
    }
    free(swarm->particles);
    free(swarm->global_best);
    free(swarm);
    return best_fitness;
}

int main() {
    int dimensions = 2;
    int population_size = 30;
    double max_velocity = 0.1;
    double w = 0.729;
    double c1 = 1.494;
    double c2 = 1.494;
    int max_iterations = 100;
    double best_fitness = optimize(dimensions, population_size, max_velocity, w, c1, c2, max_iterations);
    printf("Best Fitness: %f\n", best_fitness);
    return 0;
}