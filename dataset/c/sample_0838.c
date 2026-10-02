#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    int size;
    int dimensions;
    double **bounds;
    double **positions;
    double **velocities;
    double **pbest_positions;
    double *pbest_scores;
    double *gbest_position;
    double gbest_score;
} Swarm;

void Swarm_init(Swarm *self, int size, int dimensions, double **bounds) {
    self->size = size;
    self->dimensions = dimensions;
    self->bounds = bounds;
    self->positions = (double **)malloc(size * sizeof(double *));
    self->velocities = (double **)malloc(size * sizeof(double *));
    self->pbest_positions = (double **)malloc(size * sizeof(double *));
    self->pbest_scores = (double *)malloc(size * sizeof(double));
    self->gbest_position = (double *)malloc(dimensions * sizeof(double));
    self->gbest_score = INFINITY;

    for (int i = 0; i < size; i++) {
        self->positions[i] = (double *)malloc(dimensions * sizeof(double));
        self->velocities[i] = (double *)malloc(dimensions * sizeof(double));
        self->pbest_positions[i] = (double *)malloc(dimensions * sizeof(double));
        for (int j = 0; j < dimensions; j++) {
            self->positions[i][j] = 0.0;
            self->velocities[i][j] = 0.0;
            self->pbest_positions[i][j] = 0.0;
        }
        self->pbest_scores[i] = INFINITY;
    }
    for (int j = 0; j < dimensions; j++) {
        self->gbest_position[j] = 0.0;
    }
}

void Swarm_initialize(Swarm *self) {
    for (int i = 0; i < self->size; i++) {
        for (int j = 0; j < self->dimensions; j++) {
            self->positions[i][j] = (self->bounds[j][1] - self->bounds[j][0]) * ((double)rand() / RAND_MAX) + self->bounds[j][0];
            self->velocities[i][j] = (self->bounds[j][1] - self->bounds[j][0]) * ((double)rand() / RAND_MAX) - (self->bounds[j][1] - self->bounds[j][0]) / 2;
        }
    }
}

double objective(double *x, int dimensions) {
    double sum = 0.0;
    for (int i = 0; i < dimensions; i++) {
        sum += pow(x[i] - 0.5, 2);
    }
    return sum;
}

void Swarm_evaluate(Swarm *self, double (*function)(double *, int)) {
    for (int i = 0; i < self->size; i++) {
        double score = function(self->positions[i], self->dimensions);
        if (score < self->pbest_scores[i]) {
            self->pbest_scores[i] = score;
            for (int j = 0; j < self->dimensions; j++) {
                self->pbest_positions[i][j] = self->positions[i][j];
            }
        }
        if (score < self->gbest_score) {
            self->gbest_score = score;
            for (int j = 0; j < self->dimensions; j++) {
                self->gbest_position[j] = self->positions[i][j];
            }
        }
    }
}

void Swarm_update_velocities(Swarm *self, double w, double c1, double c2) {
    for (int i = 0; i < self->size; i++) {
        for (int j = 0; j < self->dimensions; j++) {
            self->velocities[i][j] = w * self->velocities[i][j] + c1 * ((double)rand() / RAND_MAX) * (self->pbest_positions[i][j] - self->positions[i][j]) + c2 * ((double)rand() / RAND_MAX) * (self->gbest_position[j] - self->positions[i][j]);
        }
    }
}

void Swarm_update_positions(Swarm *self) {
    for (int i = 0; i < self->size; i++) {
        for (int j = 0; j < self->dimensions; j++) {
            self->positions[i][j] += self->velocities[i][j];
            self->positions[i][j] = fmax(self->bounds[j][0], fmin(self->bounds[j][1], self->positions[i][j]));
        }
    }
}

double Swarm_optimize(Swarm *self, double (*function)(double *, int), int iterations) {
    Swarm_initialize(self);
    for (int _ = 0; _ < iterations; _++) {
        Swarm_evaluate(self, function);
        Swarm_update_velocities(self, 0.7, 1.5, 1.5);
        Swarm_update_positions(self);
    }
    return self->gbest_score;
}

void Swarm_free(Swarm *self) {
    for (int i = 0; i < self->size; i++) {
        free(self->positions[i]);
        free(self->velocities[i]);
        free(self->pbest_positions[i]);
    }
    free(self->positions);
    free(self->velocities);
    free(self->pbest_positions);
    free(self->pbest_scores);
    free(self->gbest_position);
}

int main() {
    int dimensions = 3;
    double bounds[3][2] = {{-10, 10}, {-10, 10}, {-10, 10}};
    int swarm_size = 30;
    int iterations = 100;

    Swarm swarm;
    Swarm_init(&swarm, swarm_size, dimensions, (double **)bounds);
    double best_score = Swarm_optimize(&swarm, objective, iterations);
    printf("%f\n", best_score);

    Swarm_free(&swarm);
    return 0;
}