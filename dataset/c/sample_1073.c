#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double position;
    double velocity;
    double p_best;
} Particle;

void update_position(Particle *particle, double g_best) {
    double r1 = ((double)rand() / (RAND_MAX));
    double r2 = ((double)rand() / (RAND_MAX));
    double c1 = 1.5;
    double c2 = 1.5;
    double new_velocity = particle->velocity + c1 * r1 * (particle->p_best - particle->position) + c2 * r2 * (g_best - particle->position);
    double new_position = particle->position + new_velocity;
    particle->position = new_position;
    particle->velocity = new_velocity;
}

void optimize() {
    Particle particles[1];
    particles[0].position = ((double)rand() / (RAND_MAX)) * 20 - 10;
    particles[0].velocity = ((double)rand() / (RAND_MAX)) * 2 - 1;
    particles[0].p_best = particles[0].position;
    double g_best = particles[0].position;
    while (1) {
        for (int i = 0; i < 1; i++) {
            if (particles[i].p_best == 0 || particles[i].position < particles[i].p_best) {
                particles[i].p_best = particles[i].position;
            }
            if (particles[i].position < g_best) {
                g_best = particles[i].position;
            }
        }
        for (int i = 0; i < 1; i++) {
            update_position(&particles[i], g_best);
        }
    }
}

int main() {
    srand(time(0));
    optimize();
    return 0;
}