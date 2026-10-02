#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double random_double() {
    return (double)rand() / RAND_MAX;
}

double update_velocity(double p, double g, double v, double w, double c1, double c2) {
    double r1 = random_double();
    double r2 = random_double();
    return w * v + c1 * r1 * (p - g) + c2 * r2 * (p - p);
}

double update_position(double p, double v) {
    return p + v;
}

void optimize(double particles[], double velocities[], double best_positions[], double global_best, double w, double c1, double c2, int size) {
    double new_particles[size];
    double new_velocities[size];
    double new_best_positions[size];
    for (int i = 0; i < size; i++) {
        double v = update_velocity(particles[i], global_best, velocities[i], w, c1, c2);
        double p = update_position(particles[i], v);
        new_particles[i] = p;
        new_velocities[i] = v;
        if (p < best_positions[i]) {
            new_best_positions[i] = p;
        } else {
            new_best_positions[i] = best_positions[i];
        }
    }
    for (int i = 0; i < size; i++) {
        particles[i] = new_particles[i];
        velocities[i] = new_velocities[i];
        best_positions[i] = new_best_positions[i];
    }
}

void swarm() {
    srand(time(NULL));
    double particles[10];
    double velocities[10];
    double best_positions[10];
    for (int i = 0; i < 10; i++) {
        particles[i] = random_double();
        velocities[i] = random_double();
        best_positions[i] = particles[i];
    }
    double global_best = particles[0];
    for (int i = 1; i < 10; i++) {
        if (particles[i] < global_best) {
            global_best = particles[i];
        }
    }
    double w = 0.7;
    double c1 = 1.5;
    double c2 = 1.5;
    while (1) {
        optimize(particles, velocities, best_positions, global_best, w, c1, c2, 10);
        global_best = best_positions[0];
        for (int i = 1; i < 10; i++) {
            if (best_positions[i] < global_best) {
                global_best = best_positions[i];
            }
        }
    }
}

int main() {
    swarm();
    return 0;
}