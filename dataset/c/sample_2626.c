#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    double *position;
    double *velocity;
    double *best_position;
    double best_score;
} Particle;

typedef struct {
    Particle *particles;
    double *global_best;
    double global_best_score;
    int dimensions;
    int num_particles;
    double *bounds;
} Swarm;

void particle_init(Particle *p, int dimensions, double *position) {
    p->position = (double *)malloc(dimensions * sizeof(double));
    p->velocity = (double *)malloc(dimensions * sizeof(double));
    p->best_position = (double *)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        if (position) {
            p->position[i] = position[i];
        } else {
            p->position[i] = ((double)rand() / RAND_MAX) * 2 - 1;
        }
        p->velocity[i] = ((double)rand() / RAND_MAX) * 2 - 1;
        p->best_position[i] = p->position[i];
    }
    p->best_score = INFINITY;
}

void particle_update_velocity(Particle *p, double *global_best, int dimensions, double w, double c1, double c2) {
    for (int i = 0; i < dimensions; i++) {
        double r1 = (double)rand() / RAND_MAX;
        double r2 = (double)rand() / RAND_MAX;
        double cognitive = c1 * r1 * (p->best_position[i] - p->position[i]);
        double social = c2 * r2 * (global_best[i] - p->position[i]);
        p->velocity[i] = w * p->velocity[i] + cognitive + social;
    }
}

void particle_update_position(Particle *p, int dimensions, double *bounds) {
    for (int i = 0; i < dimensions; i++) {
        p->position[i] += p->velocity[i];
        if (bounds) {
            p->position[i] = fmax(bounds[0], fmin(bounds[1], p->position[i]));
        }
    }
}

void particle_evaluate(Particle *p, double (*function)(double *)) {
    double current_score = function(p->position);
    if (current_score < p->best_score) {
        p->best_score = current_score;
        for (int i = 0; i < p->dimensions; i++) {
            p->best_position[i] = p->position[i];
        }
    }
}

void swarm_init(Swarm *s, int dimensions, int num_particles, double *bounds) {
    s->dimensions = dimensions;
    s->num_particles = num_particles;
    s->particles = (Particle *)malloc(num_particles * sizeof(Particle));
    for (int i = 0; i < num_particles; i++) {
        particle_init(&s->particles[i], dimensions, NULL);
    }
    s->global_best = (double *)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        s->global_best[i] = INFINITY;
    }
    s->global_best_score = INFINITY;
    s->bounds = bounds;
}

void swarm_update_global_best(Swarm *s) {
    for (int i = 0; i < s->num_particles; i++) {
        if (s->particles[i].best_score < s->global_best_score) {
            s->global_best_score = s->particles[i].best_score;
            for (int j = 0; j < s->dimensions; j++) {
                s->global_best[j] = s->particles[i].best_position[j];
            }
        }
    }
}

void swarm_optimize(Swarm *s, double (*function)(double *), int iterations) {
    for (int iter = 0; iter < iterations; iter++) {
        swarm_update_global_best(s);
        for (int i = 0; i < s->num_particles; i++) {
            particle_update_velocity(&s->particles[i], s->global_best, s->dimensions, 0.7, 1.5, 1.5);
            particle_update_position(&s->particles[i], s->dimensions, s->bounds);
            particle_evaluate(&s->particles[i], function);
        }
    }
}

double objective_function(double *x) {
    double sum = 0.0;
    for (int i = 0; i < 2; i++) {
        sum += x[i] * x[i];
    }
    return sum;
}

int main() {
    srand(time(NULL));
    int dimensions = 2;
    int num_particles = 30;
    double bounds[] = {-10, 10};
    int iterations = 100;
    Swarm swarm;
    swarm_init(&swarm, dimensions, num_particles, bounds);
    swarm_optimize(&swarm, objective_function, iterations);
    printf("Global Best Position: ");
    for (int i = 0; i < dimensions; i++) {
        printf("%f ", swarm.global_best[i]);
    }
    printf("\nGlobal Best Score: %f\n", swarm.global_best_score);
    return 0;
}