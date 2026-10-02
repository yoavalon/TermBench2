#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

class Swarm {
public:
    Swarm(int size, int dimensions) : size(size), dimensions(dimensions) {
        positions.resize(size, std::vector<double>(dimensions, 0.0));
        velocities.resize(size, std::vector<double>(dimensions, 0.0));
        best_positions.resize(size, std::vector<double>(dimensions, 0.0));
        best_scores.resize(size, std::numeric_limits<double>::infinity());
    }

    void update_best_positions(const std::vector<double>& scores) {
        for (int i = 0; i < size; ++i) {
            if (scores[i] < best_scores[i]) {
                best_scores[i] = scores[i];
                best_positions[i] = positions[i];
            }
        }
    }

    void update_velocities(const std::vector<double>& global_best_position, double w = 0.7, double c1 = 1.5, double c2 = 1.5) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < dimensions; ++j) {
                double r1 = 0.5, r2 = 0.5;
                velocities[i][j] = w * velocities[i][j] + c1 * r1 * (best_positions[i][j] - positions[i][j]) + c2 * r2 * (global_best_position[j] - positions[i][j]);
            }
        }
    }

    void update_positions() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < dimensions; ++j) {
                positions[i][j] += velocities[i][j];
            }
        }
    }

private:
    int size;
    int dimensions;
    std::vector<std::vector<double>> positions;
    std::vector<std::vector<double>> velocities;
    std::vector<std::vector<double>> best_positions;
    std::vector<double> best_scores;
};

double fitness_function(const std::vector<double>& position) {
    double sum = 0.0;
    for (double x : position) {
        sum += x * x;
    }
    return sum;
}

void main() {
    int swarm_size = 30;
    int dimensions = 2;
    int max_iterations = 100;
    Swarm swarm(swarm_size, dimensions);
    for (int iteration = 0; iteration < max_iterations; ++iteration) {
        std::vector<double> scores;
        for (const auto& position : swarm.positions) {
            scores.push_back(fitness_function(position));
        }
        int global_best_index = std::distance(scores.begin(), std::min_element(scores.begin(), scores.end()));
        const std::vector<double>& global_best_position = swarm.positions[global_best_index];
        swarm.update_best_positions(scores);
        swarm.update_velocities(global_best_position);
        swarm.update_positions();
    }
    double best_score = *std::min_element(swarm.best_scores.begin(), swarm.best_scores.end());
    int best_index = std::distance(swarm.best_scores.begin(), std::min_element(swarm.best_scores.begin(), swarm.best_scores.end()));
    const std::vector<double>& best_position = swarm.best_positions[best_index];
    std::cout << "Best score: " << best_score << std::endl;
    std::cout << "Best position: ";
    for (double x : best_position) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    main();
    return 0;
}