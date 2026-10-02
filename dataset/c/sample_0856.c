#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double *position;
    double *velocity;
    double *best_position;
    double best_score;
} Particle;

typedef struct {
    Particle *particles;
    double *best_position;
    double best_score;
} Swarm;

double random_uniform(double min, double max) {
    return min + (double)rand() / RAND_MAX * (max - min);
}

Particle* Particle_init(int dimensions, double (*bounds)[2]) {
    Particle *p = (Particle*)malloc(sizeof(Particle));
    p->position = (double*)malloc(dimensions * sizeof(double));
    p->velocity = (double*)malloc(dimensions * sizeof(double));
    p->best_position = (double*)malloc(dimensions * sizeof(double));
    p->best_score = INFINITY;

    for (int i = 0; i < dimensions; i++) {
        p->position[i] = random_uniform(bounds[i][0], bounds[i][1]);
        p->velocity[i] = random_uniform(-1, 1);
        p->best_position[i] = p->position[i];
    }

    return p;
}

void Particle_update_velocity(Particle *p, double *global_best, int dimensions, double w, double c1, double c2) {
    for (int i = 0; i < dimensions; i++) {
        double r1 = (double)rand() / RAND_MAX;
        double r2 = (double)rand() / RAND_MAX;
        double cognitive = c1 * r1 * (p->best_position[i] - p->position[i]);
        double social = c2 * r2 * (global_best[i] - p->position[i]);
        p->velocity[i] = w * p->velocity[i] + cognitive + social;
    }
}

void Particle_update_position(Particle *p, double (*bounds)[2], int dimensions) {
    for (int i = 0; i < dimensions; i++) {
        p->position[i] += p->velocity[i];
        p->position[i] = fmax(bounds[i][0], fmin(bounds[i][1], p->position[i]));
    }
}

Swarm* Swarm_init(int num_particles, int dimensions, double (*bounds)[2]) {
    Swarm *s = (Swarm*)malloc(sizeof(Swarm));
    s->particles = (Particle*)malloc(num_particles * sizeof(Particle));
    s->best_position = (double*)malloc(dimensions * sizeof(double));
    s->best_score = INFINITY;

    for (int i = 0; i < num_particles; i++) {
        s->particles[i] = *Particle_init(dimensions, bounds);
    }

    return s;
}

void Swarm_optimize(Swarm *s, int max_iterations, double w, double c1, double c2, double (*function)(double *)) {
    for (int iteration = 0; iteration < max_iterations; iteration++) {
        for (int i = 0; i < num_particles; i++) {
            double score = function(s->particles[i].position);
            if (score < s->particles[i].best_score) {
                s->particles[i].best_score = score;
                for (int j = 0; j < dimensions; j++) {
                    s->particles[i].best_position[j] = s->particles[i].position[j];
                }
            }
            if (score < s->best_score) {
                s->best_score = score;
                for (int j = 0; j < dimensions; j++) {
                    s->best_position[j] = s->particles[i].position[j];
                }
            }
        }
        for (int i = 0; i < num_particles; i++) {
            Particle_update_velocity(&s->particles[i], s->best_position, dimensions, w, c1, c2);
            Particle_update_position(&s->particles[i], bounds, dimensions);
        }
    }
}

double objective_function(double *x) {
    double sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += pow(x[i] - 2, 2);
    }
    return sum;
}

void main() {
    int dimensions = 3;
    double bounds[3][2] = {{-10, 10}, {-10, 10}, {-10, 10}};
    int num_particles = 20;
    int max_iterations = 100;
    double w = 0.7;
    double c1 = 1.5;
    double c2 = 1.5;

    Swarm *swarm = Swarm_init(num_particles, dimensions, bounds);
    Swarm_optimize(swarm, max_iterations, w, c1, c2, objective_function);

    printf("Best position: ");
    for (int i = 0; i < dimensions; i++) {
        printf("%f ", swarm->best_position[i]);
    }
    printf("Best score: %f\n", swarm->best_score);

    for (int i = 0; i < num_particles; i++) {
        free(swarm->particles[i].position);
        free(swarm->particles[i].velocity);
        free(swarm->particles[i].best_position);
    }
    free(swarm->particles);
    free(swarm->best_position);
    free(swarm);
}