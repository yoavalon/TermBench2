#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double *position;
    double *velocity;
    double *pbest;
    double pbest_value;
    int dim;
} Particle;

typedef struct {
    Particle *particles;
    double *gbest;
    double gbest_value;
    int num_particles;
    int dim;
    double **bounds;
} Swarm;

void Particle_init(Particle *particle, int dim) {
    particle->position = (double *)malloc(dim * sizeof(double));
    particle->velocity = (double *)malloc(dim * sizeof(double));
    particle->pbest = (double *)malloc(dim * sizeof(double));
    particle->pbest_value = INFINITY;
    particle->dim = dim;
    for (int i = 0; i < dim; i++) {
        particle->position[i] = 0.0;
        particle->velocity[i] = 0.0;
        particle->pbest[i] = 0.0;
    }
}

void Particle_update_velocity(Particle *particle, double *gbest, double w, double c1, double c2) {
    double r1 = 0.5, r2 = 0.5;
    for (int i = 0; i < particle->dim; i++) {
        particle->velocity[i] = w * particle->velocity[i] + c1 * r1 * (particle->pbest[i] - particle->position[i]) + c2 * r2 * (gbest[i] - particle->position[i]);
    }
}

void Particle_update_position(Particle *particle, double **bounds) {
    for (int i = 0; i < particle->dim; i++) {
        particle->position[i] += particle->velocity[i];
        particle->position[i] = fmax(bounds[i][0], fmin(bounds[i][1], particle->position[i]));
    }
}

void Particle_update_pbest(Particle *particle, double value) {
    if (value < particle->pbest_value) {
        for (int i = 0; i < particle->dim; i++) {
            particle->pbest[i] = particle->position[i];
        }
        particle->pbest_value = value;
    }
}

void Particle_free(Particle *particle) {
    free(particle->position);
    free(particle->velocity);
    free(particle->pbest);
}

void Swarm_init(Swarm *swarm, int num_particles, int dim, double **bounds) {
    swarm->particles = (Particle *)malloc(num_particles * sizeof(Particle));
    swarm->gbest = (double *)malloc(dim * sizeof(double));
    swarm->gbest_value = INFINITY;
    swarm->num_particles = num_particles;
    swarm->dim = dim;
    swarm->bounds = bounds;
    for (int i = 0; i < num_particles; i++) {
        Particle_init(&swarm->particles[i], dim);
    }
    for (int i = 0; i < dim; i++) {
        swarm->gbest[i] = 0.0;
    }
}

void Swarm_update_gbest(Swarm *swarm) {
    for (int i = 0; i < swarm->num_particles; i++) {
        if (swarm->particles[i].pbest_value < swarm->gbest_value) {
            for (int j = 0; j < swarm->dim; j++) {
                swarm->gbest[j] = swarm->particles[i].pbest[j];
            }
            swarm->gbest_value = swarm->particles[i].pbest_value;
        }
    }
}

void Swarm_iterate(Swarm *swarm) {
    for (int i = 0; i < swarm->num_particles; i++) {
        Particle_update_velocity(&swarm->particles[i], swarm->gbest, 0.7, 1.5, 1.5);
        Particle_update_position(&swarm->particles[i], swarm->bounds);
        double value = 0.0;
        for (int j = 0; j < swarm->dim; j++) {
            value += swarm->particles[i].position[j] * swarm->particles[i].position[j];
        }
        Particle_update_pbest(&swarm->particles[i], value);
    }
}

void Swarm_free(Swarm *swarm) {
    for (int i = 0; i < swarm->num_particles; i++) {
        Particle_free(&swarm->particles[i]);
    }
    free(swarm->particles);
    free(swarm->gbest);
}

double *optimize(int num_particles, int dim, int max_iterations, double **bounds) {
    Swarm swarm;
    Swarm_init(&swarm, num_particles, dim, bounds);
    for (int i = 0; i < max_iterations; i++) {
        Swarm_iterate(&swarm);
        Swarm_update_gbest(&swarm);
    }
    Swarm_free(&swarm);
    double *result = (double *)malloc(2 * sizeof(double));
    result[0] = swarm.gbest_value;
    return result;
}

int main() {
    int num_particles = 30;
    int dim = 2;
    int max_iterations = 100;
    double bounds[2][2] = {{-10, 10}, {-10, 10}};
    double **bounds_ptr = (double **)bounds;
    double *result = optimize(num_particles, dim, max_iterations, bounds_ptr);
    printf("Best value: %f\n", result[0]);
    free(result);
    return 0;
}