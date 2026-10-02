#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    double *position;
    double *velocity;
    double *best_position;
    int dimensions;
} Particle;

void particle_init(Particle *p, int dimensions) {
    p->dimensions = dimensions;
    p->position = (double *)malloc(dimensions * sizeof(double));
    p->velocity = (double *)malloc(dimensions * sizeof(double));
    p->best_position = (double *)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        p->position[i] = ((double)rand() / RAND_MAX) * 20 - 10;
        p->velocity[i] = ((double)rand() / RAND_MAX) * 2 - 1;
        p->best_position[i] = p->position[i];
    }
}

void particle_update_velocity(Particle *p, double *global_best, double inertia, double cognitive, double social) {
    for (int i = 0; i < p->dimensions; i++) {
        double r1 = (double)rand() / RAND_MAX;
        double r2 = (double)rand() / RAND_MAX;
        p->velocity[i] = inertia * p->velocity[i] + cognitive * r1 * (p->best_position[i] - p->position[i]) + social * r2 * (global_best[i] - p->position[i]);
    }
}

void particle_update_position(Particle *p) {
    for (int i = 0; i < p->dimensions; i++) {
        p->position[i] += p->velocity[i];
    }
}

void particle_update_best_position(Particle *p, double (*objective_function)(double *)) {
    double current_fitness = objective_function(p->position);
    double best_fitness = objective_function(p->best_position);
    if (current_fitness < best_fitness) {
        for (int i = 0; i < p->dimensions; i++) {
            p->best_position[i] = p->position[i];
        }
    }
}

void particle_free(Particle *p) {
    free(p->position);
    free(p->velocity);
    free(p->best_position);
}

typedef struct {
    Particle *particles;
    double *global_best;
    int num_particles;
    int dimensions;
    double (*objective_function)(double *);
} Swarm;

void swarm_init(Swarm *s, int dimensions, int num_particles, double (*objective_function)(double *)) {
    s->dimensions = dimensions;
    s->num_particles = num_particles;
    s->objective_function = objective_function;
    s->particles = (Particle *)malloc(num_particles * sizeof(Particle));
    for (int i = 0; i < num_particles; i++) {
        particle_init(&s->particles[i], dimensions);
    }
    s->global_best = (double *)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        s->global_best[i] = s->particles[0].position[i];
    }
}

void swarm_update_global_best(Swarm *s) {
    for (int i = 0; i < s->num_particles; i++) {
        double current_fitness = s->objective_function(s->particles[i].position);
        double global_best_fitness = s->objective_function(s->global_best);
        if (current_fitness < global_best_fitness) {
            for (int j = 0; j < s->dimensions; j++) {
                s->global_best[j] = s->particles[i].position[j];
            }
        }
    }
}

void swarm_optimize(Swarm *s, double inertia, double cognitive, double social) {
    while (1) {
        for (int i = 0; i < s->num_particles; i++) {
            particle_update_velocity(&s->particles[i], s->global_best, inertia, cognitive, social);
            particle_update_position(&s->particles[i]);
            particle_update_best_position(&s->particles[i], s->objective_function);
        }
        swarm_update_global_best(s);
    }
}

void swarm_free(Swarm *s) {
    for (int i = 0; i < s->num_particles; i++) {
        particle_free(&s->particles[i]);
    }
    free(s->particles);
    free(s->global_best);
}

double objective_function(double *x) {
    double sum = 0;
    for (int i = 0; i < 2; i++) {
        sum += pow(x[i], 2);
    }
    return sum;
}

int main() {
    srand(time(NULL));
    int dimensions = 2;
    int num_particles = 30;
    double inertia = 0.7;
    double cognitive = 1.5;
    double social = 1.5;
    Swarm swarm;
    swarm_init(&swarm, dimensions, num_particles, objective_function);
    swarm_optimize(&swarm, inertia, cognitive, social);
    swarm_free(&swarm);
    return 0;
}