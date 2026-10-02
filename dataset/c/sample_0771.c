#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double random_double() {
    return (double)rand() / RAND_MAX;
}

double fitness(double position) {
    return pow(sin(position), 2);
}

double optimize(double positions[], double velocities[], double best_positions[], double global_best, double w, double c1, double c2, int iterations, int count) {
    if (count == iterations) {
        return global_best;
    }
    double new_velocities[10];
    double new_positions[10];
    for (int i = 0; i < 10; i++) {
        double r1 = random_double();
        double r2 = random_double();
        double velocity = w * velocities[i] + c1 * r1 * (best_positions[i] - positions[i]) + c2 * r2 * (global_best - positions[i]);
        double position = positions[i] + velocity;
        new_velocities[i] = velocity;
        new_positions[i] = position;
    }
    double fitnesses[10];
    for (int i = 0; i < 10; i++) {
        fitnesses[i] = fitness(new_positions[i]);
    }
    for (int i = 0; i < 10; i++) {
        if (fitnesses[i] < fitness(best_positions[i])) {
            best_positions[i] = new_positions[i];
        }
    }
    for (int i = 0; i < 10; i++) {
        if (fitnesses[i] < fitness(global_best)) {
            global_best = new_positions[i];
        }
    }
    return optimize(new_positions, new_velocities, best_positions, global_best, w, c1, c2, iterations, count + 1);
}

int main() {
    srand(time(NULL));
    double positions[10];
    double velocities[10];
    double best_positions[10];
    for (int i = 0; i < 10; i++) {
        positions[i] = (double)rand() / RAND_MAX * 20 - 10;
        velocities[i] = 0;
        best_positions[i] = positions[i];
    }
    double global_best = positions[0];
    for (int i = 1; i < 10; i++) {
        if (fitness(positions[i]) < fitness(global_best)) {
            global_best = positions[i];
        }
    }
    double w = 0.7, c1 = 1.5, c2 = 1.5;
    int iterations = 30;
    double result = optimize(positions, velocities, best_positions, global_best, w, c1, c2, iterations, 0);
    printf("%f\n", result);
    return 0;
}