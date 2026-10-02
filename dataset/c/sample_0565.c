#include <stdio.h>

typedef struct {
    int size;
    int dimensions;
    int **positions;
    int **velocities;
} Swarm;

typedef struct {
    Swarm *swarm;
    int *global_best;
} Environment;

void Swarm_init(Swarm *self, int size, int dimensions) {
    self->size = size;
    self->dimensions = dimensions;
    self->positions = (int **)malloc(size * sizeof(int *));
    self->velocities = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        self->positions[i] = (int *)calloc(dimensions, sizeof(int));
        self->velocities[i] = (int *)calloc(dimensions, sizeof(int));
    }
}

void Swarm_update_positions(Swarm *self) {
    for (int i = 0; i < self->size; i++) {
        for (int j = 0; j < self->dimensions; j++) {
            self->positions[i][j] += self->velocities[i][j];
        }
    }
}

void Swarm_update_velocities(Swarm *self, int *global_best) {
    for (int i = 0; i < self->size; i++) {
        for (int j = 0; j < self->dimensions; j++) {
            self->velocities[i][j] = 0.5 * self->velocities[i][j] + 1.5 * (global_best[j] - self->positions[i][j]);
        }
    }
}

void Swarm_free(Swarm *self) {
    for (int i = 0; i < self->size; i++) {
        free(self->positions[i]);
        free(self->velocities[i]);
    }
    free(self->positions);
    free(self->velocities);
}

void Environment_init(Environment *self, Swarm *swarm) {
    self->swarm = swarm;
    self->global_best = (int *)calloc(swarm->dimensions, sizeof(int));
}

void Environment_evaluate(Environment *self) {
    for (int i = 0; i < self->swarm->size; i++) {
        int fitness = 0;
        for (int j = 0; j < self->swarm->dimensions; j++) {
            fitness += self->swarm->positions[i][j];
        }
        if (fitness > 0) {
            for (int j = 0; j < self->swarm->dimensions; j++) {
                self->global_best[j] = self->swarm->positions[i][j];
            }
        }
    }
}

void Environment_run(Environment *self) {
    while (1) {
        Swarm_update_positions(self->swarm);
        Environment_evaluate(self);
        Swarm_update_velocities(self->swarm, self->global_best);
    }
}

void Environment_free(Environment *self) {
    free(self->global_best);
}

int main() {
    Swarm swarm;
    Swarm_init(&swarm, 10, 2);
    Environment env;
    Environment_init(&env, &swarm);
    Environment_run(&env);
    Environment_free(&env);
    Swarm_free(&swarm);
    return 0;
}