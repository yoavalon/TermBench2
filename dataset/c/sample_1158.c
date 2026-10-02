#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double position;
    double velocity;
    double best_position;
} Particle;

void Particle_init(Particle *self, double position, double velocity, double best_position) {
    self->position = position;
    self->velocity = velocity;
    self->best_position = best_position;
}

void Particle_update_velocity(Particle *self, double global_best, double w, double c1, double c2) {
    double r1 = 0.5;
    double r2 = 0.3;
    double new_velocity = w * self->velocity + c1 * r1 * (self->best_position - self->position) + c2 * r2 * (global_best - self->position);
    self->velocity = new_velocity;
}

void Particle_update_position(Particle *self) {
    self->position += self->velocity;
    if (self->position < self->best_position) {
        self->best_position = self->position;
    }
}

double update_global_best(Particle particles[], int num_particles) {
    double best = particles[0].best_position;
    for (int i = 0; i < num_particles; i++) {
        if (particles[i].best_position < best) {
            best = particles[i].best_position;
        }
    }
    return best;
}

double optimize(Particle particles[], double global_best, double w, double c1, double c2, int iterations) {
    if (iterations == 0) {
        return global_best;
    }
    for (int i = 0; i < num_particles; i++) {
        Particle_update_velocity(&particles[i], global_best, w, c1, c2);
        Particle_update_position(&particles[i]);
    }
    double new_global_best = update_global_best(particles, num_particles);
    return optimize(particles, new_global_best, w, c1, c2, iterations - 1);
}

int main() {
    int num_particles = 10;
    double initial_positions[num_particles];
    double initial_velocities[num_particles];
    double best_positions[num_particles];
    Particle particles[num_particles];

    for (int i = 0; i < num_particles; i++) {
        initial_positions[i] = 0.0;
        initial_velocities[i] = 0.1;
        best_positions[i] = 0.0;
        Particle_init(&particles[i], initial_positions[i], initial_velocities[i], best_positions[i]);
    }

    double global_best = update_global_best(particles, num_particles);
    double w = 0.7;
    double c1 = 1.5;
    double c2 = 1.5;
    int iterations = 1000000; // Set to a large number to simulate infinite loop
    optimize(particles, global_best, w, c1, c2, iterations);
    return 0;
}