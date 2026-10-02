#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Particle {
    double *position;
    double *velocity;
    double *best;
    int dimensions;
} Particle;

typedef struct Swarm {
    Particle *particles;
    Particle best;
    int size;
    int dimensions;
} Swarm;

Particle create_particle(int dimensions) {
    Particle particle;
    particle.position = (double *)malloc(dimensions * sizeof(double));
    particle.velocity = (double *)malloc(dimensions * sizeof(double));
    particle.best = (double *)malloc(dimensions * sizeof(double));
    particle.dimensions = dimensions;
    for (int i = 0; i < dimensions; i++) {
        particle.position[i] = 0.0;
        particle.velocity[i] = 0.0;
        particle.best[i] = particle.position[i];
    }
    return particle;
}

Swarm create_swarm(int size, int dimensions) {
    Swarm swarm;
    swarm.particles = (Particle *)malloc(size * sizeof(Particle));
    swarm.size = size;
    swarm.dimensions = dimensions;
    for (int i = 0; i < size; i++) {
        swarm.particles[i] = create_particle(dimensions);
    }
    swarm.best = swarm.particles[0];
    return swarm;
}

void update_best(Swarm *swarm) {
    for (int i = 0; i < swarm->size; i++) {
        Particle *particle = &swarm->particles[i];
        int is_better = 1;
        for (int j = 0; j < swarm->dimensions; j++) {
            if (particle->position[j] < swarm->best.position[j]) {
                is_better = 0;
                break;
            }
        }
        if (is_better) {
            swarm->best = *particle;
        }
    }
}

void update_positions(Swarm *swarm) {
    for (int i = 0; i < swarm->size; i++) {
        Particle *particle = &swarm->particles[i];
        for (int j = 0; j < swarm->dimensions; j++) {
            double c1 = 1.5, c2 = 1.5, r1 = 0.5, r2 = 0.5;
            particle->velocity[j] = 0.7 * particle->velocity[j] + c1 * r1 * (swarm->best.position[j] - particle->position[j]) + c2 * r2 * (particle->best[j] - particle->position[j]);
            particle->position[j] += particle->velocity[j];
        }
        int is_better = 1;
        for (int j = 0; j < swarm->dimensions; j++) {
            if (particle->position[j] < particle->best[j]) {
                is_better = 0;
                break;
            }
        }
        if (is_better) {
            for (int j = 0; j < swarm->dimensions; j++) {
                particle->best[j] = particle->position[j];
            }
        }
    }
}

void optimize(Swarm *swarm) {
    update_positions(swarm);
    update_best(swarm);
    optimize(swarm);
}

void main() {
    Swarm swarm = create_swarm(10, 2);
    optimize(&swarm);
}