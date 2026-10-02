#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

typedef struct Particle {
    double *position;
    double *velocity;
    double *best_position;
    double best_score;
} Particle;

typedef struct Swarm {
    Particle *particles;
    double *global_best;
    double global_best_score;
} Swarm;

double random_uniform(double min, double max) {
    return min + (max - min) * ((double)rand() / RAND_MAX);
}

Particle create_particle(int dimensions) {
    Particle p;
    p.position = (double *)malloc(dimensions * sizeof(double));
    p.velocity = (double *)malloc(dimensions * sizeof(double));
    p.best_position = (double *)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        p.position[i] = random_uniform(-10, 10);
        p.velocity[i] = random_uniform(-1, 1);
        p.best_position[i] = p.position[i];
    }
    p.best_score = INFINITY;
    return p;
}

void update_velocity(Particle *p, double *global_best, int dimensions, double w, double c1, double c2) {
    for (int i = 0; i < dimensions; i++) {
        double r1 = (double)rand() / RAND_MAX;
        double r2 = (double)rand() / RAND_MAX;
        double cognitive = c1 * r1 * (p->best_position[i] - p->position[i]);
        double social = c2 * r2 * (global_best[i] - p->position[i]);
        p->velocity[i] = w * p->velocity[i] + cognitive + social;
    }
}

void update_position(Particle *p, int dimensions) {
    for (int i = 0; i < dimensions; i++) {
        p->position[i] += p->velocity[i];
        if (p->position[i] < -10) {
            p->position[i] = -10;
        } else if (p->position[i] > 10) {
            p->position[i] = 10;
        }
    }
}

Swarm create_swarm(int num_particles, int dimensions) {
    Swarm s;
    s.particles = (Particle *)malloc(num_particles * sizeof(Particle));
    for (int i = 0; i < num_particles; i++) {
        s.particles[i] = create_particle(dimensions);
    }
    s.global_best = (double *)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        s.global_best[i] = INFINITY;
    }
    s.global_best_score = INFINITY;
    return s;
}

void update_global_best(Swarm *s, int dimensions) {
    for (int i = 0; i < dimensions; i++) {
        if (s->particles[i].best_score < s->global_best_score) {
            for (int j = 0; j < dimensions; j++) {
                s->global_best[j] = s->particles[i].best_position[j];
            }
            s->global_best_score = s->particles[i].best_score;
        }
    }
}

void optimize(Swarm *s, int iterations, int dimensions, double w, double c1, double c2) {
    for (int i = 0; i < iterations; i++) {
        update_global_best(s, dimensions);
        for (int j = 0; j < s->particles; j++) {
            update_velocity(&s->particles[j], s->global_best, dimensions, w, c1, c2);
            update_position(&s->particles[j], dimensions);
        }
    }
}

double objective_function(double *x, int dimensions) {
    double result = 0.0;
    for (int i = 0; i < dimensions; i++) {
        result += x[i] * x[i];
    }
    return result;
}

void main() {
    srand(time(NULL));
    int dimensions = 30;
    int num_particles = 30;
    int iterations = 100;
    double w = 0.7;
    double c1 = 2.0;
    double c2 = 2.0;
    Swarm swarm = create_swarm(num_particles, dimensions);
    for (int i = 0; i < num_particles; i++) {
        double score = objective_function(swarm.particles[i].position, dimensions);
        if (score < swarm.particles[i].best_score) {
            swarm.particles[i].best_score = score;
        }
    }
    optimize(&swarm, iterations, dimensions, w, c1, c2);
    double best_score = swarm.global_best_score;
    printf("Best Score: %f\n", best_score);
}