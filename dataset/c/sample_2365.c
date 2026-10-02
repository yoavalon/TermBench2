#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define INFINITY 1e9

double random_double(double min, double max) {
    return min + (max - min) * ((double)rand() / RAND_MAX);
}

void initialize_particles(int dim, int num_particles, double particles[][2], double velocities[][2], double pbest_positions[][2], double *pbest_values, double *gbest_position, double *gbest_value) {
    for (int i = 0; i < num_particles; i++) {
        for (int j = 0; j < dim; j++) {
            particles[i][j] = random_double(-10, 10);
            velocities[i][j] = random_double(-1, 1);
            pbest_positions[i][j] = particles[i][j];
        }
        pbest_values[i] = INFINITY;
    }
    *gbest_value = INFINITY;
}

void update_pbest(double *gbest_value, double *gbest_position, double *pbest_values, double pbest_positions[][2], double particles[][2], int num_particles, double (*fitness_func)(double *)) {
    for (int i = 0; i < num_particles; i++) {
        double current_value = fitness_func(particles[i]);
        if (current_value < pbest_values[i]) {
            pbest_values[i] = current_value;
            for (int j = 0; j < 2; j++) {
                pbest_positions[i][j] = particles[i][j];
            }
        }
        if (current_value < *gbest_value) {
            *gbest_value = current_value;
            for (int j = 0; j < 2; j++) {
                gbest_position[j] = particles[i][j];
            }
        }
    }
}

void update_particles(double particles[][2], double velocities[][2], double pbest_positions[][2], double gbest_position[2], double w, double c1, double c2, int num_particles) {
    for (int i = 0; i < num_particles; i++) {
        for (int j = 0; j < 2; j++) {
            double r1 = (double)rand() / RAND_MAX;
            double r2 = (double)rand() / RAND_MAX;
            velocities[i][j] = w * velocities[i][j] + c1 * r1 * (pbest_positions[i][j] - particles[i][j]) + c2 * r2 * (gbest_position[j] - particles[i][j]);
            particles[i][j] += velocities[i][j];
        }
    }
}

double fitness_func(double *position) {
    double sum = 0;
    for (int i = 0; i < 2; i++) {
        sum += position[i] * position[i];
    }
    return sum;
}

int main() {
    srand(time(NULL));
    int dim = 2;
    int num_particles = 10;
    double w = 0.729;
    double c1 = 1.494;
    double c2 = 1.494;
    double particles[num_particles][2];
    double velocities[num_particles][2];
    double pbest_positions[num_particles][2];
    double pbest_values[num_particles];
    double gbest_position[2];
    double gbest_value;

    initialize_particles(dim, num_particles, particles, velocities, pbest_positions, pbest_values, gbest_position, &gbest_value);
    while (1) {
        update_pbest(&gbest_value, gbest_position, pbest_values, pbest_positions, particles, num_particles, fitness_func);
        update_particles(particles, velocities, pbest_positions, gbest_position, w, c1, c2, num_particles);
    }
    return 0;
}