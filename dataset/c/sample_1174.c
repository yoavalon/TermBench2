#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    double **bounds;
    double w, c1, c2;
} Swarm;

void Particle_init(Particle *self, int dimensions) {
    self->position = (double *)malloc(dimensions * sizeof(double));
    self->velocity = (double *)malloc(dimensions * sizeof(double));
    self->best_position = (double *)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        self->position[i] = 0.0;
        self->velocity[i] = 0.0;
        self->best_position[i] = 0.0;
    }
    self->best_score = INFINITY;
}

void Particle_update_velocity(Particle *self, double *global_best, int dimensions, double w, double c1, double c2) {
    for (int i = 0; i < dimensions; i++) {
        double r1 = 0.5, r2 = 0.5;
        double cognitive = c1 * r1 * (self->best_position[i] - self->position[i]);
        double social = c2 * r2 * (global_best[i] - self->position[i]);
        self->velocity[i] = w * self->velocity[i] + cognitive + social;
    }
}

void Particle_update_position(Particle *self, int dimensions, double **bounds) {
    for (int i = 0; i < dimensions; i++) {
        self->position[i] += self->velocity[i];
        self->position[i] = fmax(bounds[i][0], fmin(self->position[i], bounds[i][1]));
    }
}

void Particle_evaluate(Particle *self, double (*score_function)(double *), int dimensions) {
    self->best_score = score_function(self->position);
    if (self->best_score < score_function(self->best_position)) {
        for (int i = 0; i < dimensions; i++) {
            self->best_position[i] = self->position[i];
        }
    }
}

void Swarm_init(Swarm *self, int dimensions, int num_particles, double **bounds, double w, double c1, double c2) {
    self->particles = (Particle *)malloc(num_particles * sizeof(Particle));
    for (int i = 0; i < num_particles; i++) {
        Particle_init(&self->particles[i], dimensions);
    }
    self->global_best = (double *)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        self->global_best[i] = 0.0;
    }
    self->global_best_score = INFINITY;
    self->bounds = bounds;
    self->w = w;
    self->c1 = c1;
    self->c2 = c2;
}

void Swarm_update_global_best(Swarm *self, int dimensions) {
    for (int i = 0; i < dimensions; i++) {
        if (self->particles[i].best_score < self->global_best_score) {
            self->global_best_score = self->particles[i].best_score;
            for (int j = 0; j < dimensions; j++) {
                self->global_best[j] = self->particles[i].best_position[j];
            }
        }
    }
}

void Swarm_iterate(Swarm *self, int dimensions, double (*score_function)(double *)) {
    for (int i = 0; i < dimensions; i++) {
        Particle_update_velocity(&self->particles[i], self->global_best, dimensions, self->w, self->c1, self->c2);
        Particle_update_position(&self->particles[i], dimensions, self->bounds);
        Particle_evaluate(&self->particles[i], score_function, dimensions);
    }
    Swarm_update_global_best(self, dimensions);
}

double score_function(double *position, int dimensions) {
    double sum = 0.0;
    for (int i = 0; i < dimensions; i++) {
        sum += position[i] * position[i];
    }
    return sum;
}

int main() {
    int dimensions = 2;
    int num_particles = 10;
    double bounds[2][2] = {{-10, 10}, {-10, 10}};
    double w = 0.7;
    double c1 = 2.0;
    double c2 = 2.0;

    Swarm swarm;
    Swarm_init(&swarm, dimensions, num_particles, bounds, w, c1, c2);
    while (1) {
        Swarm_iterate(&swarm, dimensions, score_function);
    }
    return 0;
}