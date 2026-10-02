#include <vector>
#include <iostream>

std::vector<double> optimize(int iterations, int particles, int dimensions) {
    std::vector<std::vector<double>> velocity(particles, std::vector<double>(dimensions, 0));
    std::vector<std::vector<double>> position(particles, std::vector<double>(dimensions, 0));
    std::vector<std::vector<double>> best_position(particles, std::vector<double>(dimensions, 0));
    std::vector<double> global_best(dimensions, 0);

    for (int _ = 0; _ < iterations; ++_) {
        for (int i = 0; i < particles; ++i) {
            for (int j = 0; j < dimensions; ++j) {
                velocity[i][j] = 0.5 * velocity[i][j] + 0.3 * (best_position[i][j] - position[i][j]) + 0.2 * (global_best[j] - position[i][j]);
                position[i][j] += velocity[i][j];
            }
        }
    }
    return global_best;
}

int main() {
    optimize(100, 20, 3);
    return 0;
}