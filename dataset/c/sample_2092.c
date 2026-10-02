#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    double *position;
    double *velocity;
    double *best_position;
    double best_score;
} Particle;

typedef struct {
    Particle *particles;
    double *gbest_position;
    double gbest_score;
} Swarm;

double random_double(double min, double max) {
    return min + (max - min) * ((double)rand() / RAND_MAX);
}

Particle create_particle(int dimensions) {
    Particle particle;
    particle.position = (double *)malloc(dimensions * sizeof(double));
    particle.velocity = (double *)malloc(dimensions * sizeof(double));
    particle.best_position = (double *)malloc(dimensions * sizeof(double));
    particle.best_score = INFINITY;
    for (int i = 0; i < dimensions; i++) {
        particle.position[i] = random_double(-10, 10);
        particle.velocity[i] = random_double(-1, 1);
        particle.best_position[i] = particle.position[i];
    }
    return particle;
}

Swarm create_swarm(int num_particles, int dimensions) {
    Swarm swarm;
    swarm.particles = (Particle *)malloc(num_particles * sizeof(Particle));
    swarm.gbest_position = (double *)malloc(dimensions * sizeof(double));
    swarm.gbest_score = INFINITY;
    for (int i = 0; i < num_particles; i++) {
        swarm.particles[i] = create_particle(dimensions);
    }
    return swarm;
}

void update_gbest(Swarm *swarm, int dimensions) {
    for (int i = 0; i < dimensions; i++) {
        swarm->gbest_position[i] = swarm->particles[0].best_position[i];
    }
    swarm->gbest_score = swarm->particles[0].best_score;
    for (int i = 1; i < swarm->particles[0].best_score; i++) {
        if (swarm->particles[i].best_score < swarm->gbest_score) {
            swarm->gbest_score = swarm->particles[i].best_score;
            for (int j = 0; j < dimensions; j++) {
                swarm->gbest_position[j] = swarm->particles[i].best_position[j];
            }
        }
    }
}

void update_particles(Swarm *swarm, int dimensions, double w, double c1, double c2) {
    for (int i = 0; i < dimensions; i++) {
        double r1 = (double)rand() / RAND_MAX;
        double r2 = (double)rand() / RAND_MAX;
        for (int j = 0; j < dimensions; j++) {
            swarm->particles[i].velocity[j] = w * swarm->particles[i].velocity[j] + c1 * r1 * (swarm->particles[i].best_position[j] - swarm->particles[i].position[j]) + c2 * r2 * (swarm->gbest_position[j] - swarm->particles[i].position[j]);
            swarm->particles[i].position[j] += swarm->particles[i].velocity[j];
        }
    }
}

double objective_function(double *x, int dimensions) {
    double sum = 0.0;
    for (int i = 0; i < dimensions; i++) {
        sum += x[i] * x[i];
    }
    return sum;
}

void evaluate(Swarm *swarm, int dimensions) {
    for (int i = 0; i < dimensions; i++) {
        double score = objective_function(swarm->particles[i].position, dimensions);
        if (score < swarm->particles[i].best_score) {
            swarm->particles[i].best_score = score;
            for (int j = 0; j < dimensions; j++) {
                swarm->particles[i].best_position[j] = swarm->particles[i].position[j];
            }
        }
    }
}

void main() {
    srand(time(NULL));
    int dimensions = 3;
    int num_particles = 20;
    double w = 0.7;
    double c1 = 1.5;
    double c2 = 1.5;
    int iterations = 100;
    Swarm swarm = create_swarm(num_particles, dimensions);
    for (int i = 0; i < iterations; i++) {
        update_gbest(&swarm, dimensions);
        update_particles(&swarm, dimensions, w, c1, c2);
        evaluate(&swarm, dimensions);
    }
    printf("Best score: %f\n", swarm.gbest_score);
    printf("Best position: ");
    for (int i = 0; i < dimensions; i++) {
        printf("%f ", swarm.gbest_position[i]);
    }
    printf("\n");
}