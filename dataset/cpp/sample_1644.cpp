#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

double random_double() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}

void update_position(std::vector<double>& position, std::vector<double>& velocity, const std::vector<double>& best_position, const std::vector<double>& global_best) {
    for (size_t i = 0; i < position.size(); ++i) {
        double r1 = random_double();
        double r2 = random_double();
        double cognitive = r1 * (best_position[i] - position[i]);
        double social = r2 * (global_best[i] - position[i]);
        velocity[i] = 0.7 * velocity[i] + cognitive + social;
        position[i] = position[i] + velocity[i];
    }
}

void optimize() {
    size_t dimensions = 30;
    size_t swarm_size = 50;
    std::vector<std::vector<double>> positions(swarm_size, std::vector<double>(dimensions));
    std::vector<std::vector<double>> velocities(swarm_size, std::vector<double>(dimensions));
    std::vector<std::vector<double>> best_positions = positions;
    std::vector<double> global_best(dimensions);

    for (size_t i = 0; i < swarm_size; ++i) {
        for (size_t j = 0; j < dimensions; ++j) {
            positions[i][j] = random_double();
            velocities[i][j] = random_double();
            best_positions[i][j] = positions[i][j];
        }
    }

    global_best = *std::min_element(best_positions.begin(), best_positions.end(), [](const std::vector<double>& a, const std::vector<double>& b) {
        return std::accumulate(a.begin(), a.end(), 0.0) < std::accumulate(b.begin(), b.end(), 0.0);
    });

    while (true) {
        for (size_t i = 0; i < swarm_size; ++i) {
            update_position(positions[i], velocities[i], best_positions[i], global_best);
            double fitness = std::accumulate(positions[i].begin(), positions[i].end(), 0.0);
            if (fitness < std::accumulate(best_positions[i].begin(), best_positions[i].end(), 0.0)) {
                best_positions[i] = positions[i];
                if (fitness < std::accumulate(global_best.begin(), global_best.end(), 0.0)) {
                    global_best = positions[i];
                }
            }
        }
    }
}

int main() {
    optimize();
    return 0;
}