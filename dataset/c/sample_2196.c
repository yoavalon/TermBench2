c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double position[2];
    double velocity[2];
} Particle;

typedef struct {
    double position[2];
    double fitness;
} BestGlobal;

void particle_swarm_optimization() {
    Particle particles[10];
    BestGlobal best_global = {{0.0, 0.0}, INFINITY};

    for (int i = 0; i < 10; i++) {
        particles[i].position[0] = 0.0;
        particles[i].position[1] = 0.0;
        particles[i].velocity[0] = 0.0;
        particles[i].velocity[1] = 0.0;
    }

    while (1) {
        for (int i = 0; i < 10; i++) {
            double fitness = particles[i].position[0] + particles[i].position[1];
            if (fitness < best_global.fitness) {
                best_global.position[0] = particles[i].position[0];
                best_global.position[1] = particles[i].position[1];
                best_global.fitness = fitness;
            }
            for (int j = 0; j < 2; j++) {
                double r1 = 0.5;
                double r2 = 0.5;
                particles[i].velocity[j] = 0.7 * particles[i].velocity[j] + 1.5 * r1 * (best_global.position[j] - particles[i].position[j]) + 1.5 * r2 * (best_global.position[j] - particles[i].position[j]);
                particles[i].position[j] += particles[i].velocity[j];
            }
        }
    }
}

int main() {
    particle_swarm_optimization();
    return 0;
}