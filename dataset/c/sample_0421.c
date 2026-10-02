#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_PARTICLES 10
#define DIM 2

double** initialize_particles(int dim, int num_particles) {
    double** particles = (double**)malloc(num_particles * sizeof(double*));
    double** velocities = (double**)malloc(num_particles * sizeof(double*));
    double** best_positions = (double**)malloc(num_particles * sizeof(double*));
    double* best_scores = (double*)malloc(num_particles * sizeof(double));
    for (int i = 0; i < num_particles; i++) {
        particles[i] = (double*)malloc(dim * sizeof(double));
        velocities[i] = (double*)malloc(dim * sizeof(double));
        best_positions[i] = (double*)malloc(dim * sizeof(double));
        for (int j = 0; j < dim; j++) {
            particles[i][j] = (double)rand() / RAND_MAX;
            velocities[i][j] = (double)rand() / RAND_MAX;
            best_positions[i][j] = particles[i][j];
        }
        best_scores[i] = INFINITY;
    }
    return particles;
}

void update_particles(double** particles, double** velocities, double** best_positions, double* best_scores, double* global_best, double omega, double phi_p, double phi_g, double bounds[2]) {
    for (int i = 0; i < NUM_PARTICLES; i++) {
        for (int j = 0; j < DIM; j++) {
            double r_p = (double)rand() / RAND_MAX;
            double r_g = (double)rand() / RAND_MAX;
            velocities[i][j] = omega * velocities[i][j] + phi_p * r_p * (best_positions[i][j] - particles[i][j]) + phi_g * r_g * (global_best[j] - particles[i][j]);
            particles[i][j] += velocities[i][j];
            particles[i][j] = fmax(bounds[0], fmin(bounds[1], particles[i][j]));
        }
    }
}

int main() {
    srand(time(NULL));
    double** particles = initialize_particles(DIM, NUM_PARTICLES);
    double** velocities = (double**)malloc(NUM_PARTICLES * sizeof(double*));
    double** best_positions = (double**)malloc(NUM_PARTICLES * sizeof(double*));
    double* best_scores = (double*)malloc(NUM_PARTICLES * sizeof(double));
    double* global_best = (double*)malloc(DIM * sizeof(double));
    for (int i = 0; i < DIM; i++) {
        global_best[i] = INFINITY;
    }
    double omega = 0.7;
    double phi_p = 0.2;
    double phi_g = 0.3;
    double bounds[2] = {0, 1};
    while (1) {
        update_particles(particles, velocities, best_positions, best_scores, global_best, omega, phi_p, phi_g, bounds);
    }
    return 0;
}