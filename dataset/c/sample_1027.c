#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double update_velocity(double pos, double vel, double best_pos, double global_best) {
    double w = 0.7;
    double c1 = 1.5;
    double c2 = 1.5;
    double r1 = 0.5;
    double r2 = 0.5;
    double new_vel = w * vel + c1 * r1 * (best_pos - pos) + c2 * r2 * (global_best - pos);
    return new_vel;
}

double update_position(double pos, double vel) {
    return pos + vel;
}

void optimize(double (*func)(double), double bounds[2], int n_particles, int max_iter) {
    double particles[n_particles];
    double velocities[n_particles];
    double personal_best[n_particles];
    double global_best;

    for (int i = 0; i < n_particles; i++) {
        particles[i] = bounds[0] + (bounds[1] - bounds[0]) * i / n_particles;
        velocities[i] = 0;
        personal_best[i] = particles[i];
    }

    global_best = personal_best[0];
    for (int i = 1; i < n_particles; i++) {
        if (func(personal_best[i]) < func(global_best)) {
            global_best = personal_best[i];
        }
    }

    void iterate(int i) {
        for (int j = 0; j < n_particles; j++) {
            velocities[j] = update_velocity(particles[j], velocities[j], personal_best[j], global_best);
            particles[j] = update_position(particles[j], velocities[j]);
            if (func(particles[j]) < func(personal_best[j])) {
                personal_best[j] = particles[j];
            }
        }
        global_best = personal_best[0];
        for (int i = 1; i < n_particles; i++) {
            if (func(personal_best[i]) < func(global_best)) {
                global_best = personal_best[i];
            }
        }
        iterate(i + 1);
    }

    iterate(0);
}

double test_func(double x) {
    return x * x;
}

int main() {
    double bounds[] = {-100, 100};
    optimize(test_func, bounds, 30, 1000);
    return 0;
}