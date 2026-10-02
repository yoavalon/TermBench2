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
    double *global_best_position;
    double global_best_score;
    int num_particles;
    int dimensions;
    double *bounds;
} Swarm;

typedef struct {
    double *bounds;
} ObjectiveFunction;

double random_double(double min, double max) {
    return min + (max - min) * ((double)rand() / RAND_MAX);
}

Particle* create_particle(int dimensions, double *bounds) {
    Particle *particle = (Particle*)malloc(sizeof(Particle));
    particle->position = (double*)malloc(dimensions * sizeof(double));
    particle->velocity = (double*)malloc(dimensions * sizeof(double));
    particle->best_position = (double*)malloc(dimensions * sizeof(double));
    for (int i = 0; i < dimensions; i++) {
        particle->position[i] = random_double(bounds[0], bounds[1]);
        particle->velocity[i] = random_double(-1, 1);
        particle->best_position[i] = particle->position[i];
    }
    particle->best_score = INFINITY;
    return particle;
}

void update_velocity(Particle *particle, double *global_best, int dimensions, double w, double c1, double c2) {
    for (int i = 0; i < dimensions; i++) {
        double r1 = (double)rand() / RAND_MAX;
        double r2 = (double)rand() / RAND_MAX;
        particle->velocity[i] = w * particle->velocity[i] + c1 * r1 * (particle->best_position[i] - particle->position[i]) + c2 * r2 * (global_best[i] - particle->position[i]);
    }
}

void update_position(Particle *particle, int dimensions, double *bounds) {
    for (int i = 0; i < dimensions; i++) {
        particle->position[i] += particle->velocity[i];
        particle->position[i] = fmax(bounds[0], fmin(bounds[1], particle->position[i]));
    }
}

double evaluate(ObjectiveFunction *objective_function, double *position) {
    double x = position[0];
    double y = position[1];
    return (x * x + y - 11) * (x * x + y - 11) + (x + y * y - 7) * (x + y * y - 7);
}

void update_best_score(Particle *particle, ObjectiveFunction *objective_function) {
    double score = evaluate(objective_function, particle->position);
    if (score < particle->best_score) {
        particle->best_score = score;
        for (int i = 0; i < objective_function->bounds[1] - objective_function->bounds[0] + 1; i++) {
            particle->best_position[i] = particle->position[i];
        }
    }
}

Swarm* create_swarm(int num_particles, int dimensions, double *bounds) {
    Swarm *swarm = (Swarm*)malloc(sizeof(Swarm));
    swarm->particles = (Particle*)malloc(num_particles * sizeof(Particle));
    swarm->global_best_position = (double*)malloc(dimensions * sizeof(double));
    swarm->num_particles = num_particles;
    swarm->dimensions = dimensions;
    swarm->bounds = bounds;
    for (int i = 0; i < num_particles; i++) {
        swarm->particles[i] = *create_particle(dimensions, bounds);
    }
    for (int i = 0; i < dimensions; i++) {
        swarm->global_best_position[i] = swarm->particles[0].position[i];
    }
    swarm->global_best_score = swarm->particles[0].best_score;
    return swarm;
}

void update_global_best(Swarm *swarm) {
    for (int i = 0; i < swarm->num_particles; i++) {
        if (swarm->particles[i].best_score < swarm->global_best_score) {
            swarm->global_best_score = swarm->particles[i].best_score;
            for (int j = 0; j < swarm->dimensions; j++) {
                swarm->global_best_position[j] = swarm->particles[i].best_position[j];
            }
        }
    }
}

void iterate(Swarm *swarm, ObjectiveFunction *objective_function) {
    for (int i = 0; i < swarm->num_particles; i++) {
        update_velocity(&swarm->particles[i], swarm->global_best_position, swarm->dimensions, 0.7, 1.5, 1.5);
        update_position(&swarm->particles[i], swarm->dimensions, swarm->bounds);
        update_best_score(&swarm->particles[i], objective_function);
    }
    update_global_best(swarm);
}

ObjectiveFunction* create_objective_function(double *bounds) {
    ObjectiveFunction *objective_function = (ObjectiveFunction*)malloc(sizeof(ObjectiveFunction));
    objective_function->bounds = bounds;
    return objective_function;
}

int main() {
    int dimensions = 2;
    int num_particles = 30;
    double bounds[] = {-5, 5};
    srand(time(0));
    ObjectiveFunction *objective_function = create_objective_function(bounds);
    Swarm *swarm = create_swarm(num_particles, dimensions, bounds);
    for (int i = 0; i < 100; i++) {
        iterate(swarm, objective_function);
        if (swarm->global_best_score < 1e-06) {
            break;
        }
    }
    printf("Best position: (%f, %f)\n", swarm->global_best_position[0], swarm->global_best_position[1]);
    printf("Best score: %f\n", swarm->global_best_score);
    return 0;
}