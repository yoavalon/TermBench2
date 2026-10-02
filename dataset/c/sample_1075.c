#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double random_double() {
    return (double)rand() / RAND_MAX;
}

double update_velocity(double p, double g, double l, double w, double c1, double c2) {
    double r1 = random_double();
    double r2 = random_double();
    return w * l + c1 * r1 * (p - l) + c2 * r2 * (g - l);
}

double update_position(double l, double v) {
    return l + v;
}

void swarm_search(double (*f)(double*), double** bounds, int n_particles, double w, double c1, double c2) {
    double** particles = (double**)malloc(n_particles * sizeof(double*));
    double** velocities = (double**)malloc(n_particles * sizeof(double*));
    double** pbest = (double**)malloc(n_particles * sizeof(double*));
    int n_dimensions = 2;
    for (int i = 0; i < n_particles; i++) {
        particles[i] = (double*)malloc(n_dimensions * sizeof(double));
        velocities[i] = (double*)malloc(n_dimensions * sizeof(double));
        pbest[i] = (double*)malloc(n_dimensions * sizeof(double));
        for (int j = 0; j < n_dimensions; j++) {
            particles[i][j] = bounds[j][0] + (bounds[j][1] - bounds[j][0]) * random_double();
            velocities[i][j] = 0;
            pbest[i][j] = particles[i][j];
        }
    }

    double* gbest = (double*)malloc(n_dimensions * sizeof(double));
    for (int j = 0; j < n_dimensions; j++) {
        gbest[j] = particles[0][j];
    }
    for (int i = 1; i < n_particles; i++) {
        if (f(particles[i]) < f(gbest)) {
            for (int j = 0; j < n_dimensions; j++) {
                gbest[j] = particles[i][j];
            }
        }
    }

    while (1) {
        for (int i = 0; i < n_particles; i++) {
            for (int j = 0; j < n_dimensions; j++) {
                velocities[i][j] = update_velocity(pbest[i][j], gbest[j], particles[i][j], w, c1, c2);
                particles[i][j] = update_position(particles[i][j], velocities[i][j]);
            }
        }
        for (int i = 0; i < n_particles; i++) {
            if (f(particles[i]) < f(pbest[i])) {
                for (int j = 0; j < n_dimensions; j++) {
                    pbest[i][j] = particles[i][j];
                }
            }
        }
        for (int i = 0; i < n_particles; i++) {
            if (f(particles[i]) < f(gbest)) {
                for (int j = 0; j < n_dimensions; j++) {
                    gbest[j] = particles[i][j];
                }
            }
        }
    }

    for (int i = 0; i < n_particles; i++) {
        free(particles[i]);
        free(velocities[i]);
        free(pbest[i]);
    }
    free(particles);
    free(velocities);
    free(pbest);
    free(gbest);
}

double objective(double* x) {
    return x[0] * x[0] + x[1] * x[1];
}

int main() {
    double bounds[2][2] = {{-10, 10}, {-10, 10}};
    swarm_search(objective, bounds, 30, 0.7, 1.5, 1.5);
    return 0;
}