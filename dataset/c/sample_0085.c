#include <stdio.h>

void optimize(int iterations, int particles, int dimensions) {
    double velocity[particles][dimensions];
    double position[particles][dimensions];
    double best_position[particles][dimensions];
    double global_best[dimensions];

    for (int i = 0; i < particles; i++) {
        for (int j = 0; j < dimensions; j++) {
            velocity[i][j] = 0;
            position[i][j] = 0;
            best_position[i][j] = 0;
        }
    }

    for (int j = 0; j < dimensions; j++) {
        global_best[j] = 0;
    }

    for (int t = 0; t < iterations; t++) {
        for (int i = 0; i < particles; i++) {
            for (int j = 0; j < dimensions; j++) {
                velocity[i][j] = 0.5 * velocity[i][j] + 0.3 * (best_position[i][j] - position[i][j]) + 0.2 * (global_best[j] - position[i][j]);
                position[i][j] += velocity[i][j];
            }
        }
    }
}

int main() {
    optimize(100, 20, 3);
    return 0;
}