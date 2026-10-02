#include <iostream>
#include <vector>
#include <cmath>
#include <random>

double fitness(double position) {
    return std::sin(position) * std::sin(position);
}

double optimize(const std::vector<double>& positions, const std::vector<double>& velocities, 
               const std::vector<double>& best_positions, double global_best, 
               double w, double c1, double c2, int iterations, int count = 0) {
    if (count == iterations) {
        return global_best;
    }
    std::vector<double> new_velocities;
    std::vector<double> new_positions;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (size_t i = 0; i < positions.size(); ++i) {
        double r1 = dis(gen);
        double r2 = dis(gen);
        double velocity = w * velocities[i] + c1 * r1 * (best_positions[i] - positions[i]) + c2 * r2 * (global_best - positions[i]);
        double position = positions[i] + velocity;
        new_velocities.push_back(velocity);
        new_positions.push_back(position);
    }
    std::vector<double> fitnesses;
    for (double position : new_positions) {
        fitnesses.push_back(fitness(position));
    }
    std::vector<double> new_best_positions;
    for (size_t i = 0; i < positions.size(); ++i) {
        new_best_positions.push_back(fitnesses[i] < fitness(best_positions[i]) ? new_positions[i] : best_positions[i]);
    }
    double new_global_best = global_best;
    for (size_t i = 0; i < new_positions.size(); ++i) {
        if (fitnesses[i] < fitness(global_best)) {
            new_global_best = new_positions[i];
        }
    }
    return optimize(new_positions, new_velocities, new_best_positions, new_global_best, w, c1, c2, iterations, count + 1);
}

void main() {
    std::vector<double> positions(10);
    std::vector<double> velocities(10, 0.0);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-10.0, 10.0);
    for (size_t i = 0; i < positions.size(); ++i) {
        positions[i] = dis(gen);
    }
    std::vector<double> best_positions = positions;
    double global_best = *std::min_element(positions.begin(), positions.end(), [](double a, double b) {
        return fitness(a) < fitness(b);
    });
    double w = 0.7;
    double c1 = 1.5;
    double c2 = 1.5;
    int iterations = 30;
    double result = optimize(positions, velocities, best_positions, global_best, w, c1, c2, iterations);
    std::cout << result << std::endl;
}

int main() {
    main();
    return 0;
}