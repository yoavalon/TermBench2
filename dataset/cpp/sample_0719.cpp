#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>

std::vector<double> optimize(const std::vector<double>& positions, const std::vector<double>& velocities, const std::vector<double>& personal_best, double global_best, int iteration, int max_iterations) {
    if (iteration >= max_iterations) {
        return {global_best};
    }
    std::vector<double> new_positions;
    std::vector<double> new_velocities;
    for (size_t i = 0; i < positions.size(); ++i) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);
        double r1 = dis(gen);
        double r2 = dis(gen);
        double new_velocity = velocities[i] + 2 * r1 * (personal_best[i] - positions[i]) + 2 * r2 * (global_best - positions[i]);
        double new_position = positions[i] + new_velocity;
        new_positions.push_back(new_position);
        new_velocities.push_back(new_velocity);
    }
    double new_global_best = *std::min_element(new_positions.begin(), new_positions.end(), [](double x, double y) { return fitness(x) < fitness(y); });
    return optimize(new_positions, new_velocities, personal_best, new_global_best, iteration + 1, max_iterations);
}

double fitness(double x) {
    return x * x;
}

void main() {
    std::vector<double> positions;
    std::vector<double> velocities;
    std::vector<double> personal_best;
    double global_best;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-10.0, 10.0);

    for (int i = 0; i < 10; ++i) {
        double pos = dis(gen);
        positions.push_back(pos);
        velocities.push_back(0.0);
        personal_best.push_back(pos);
    }

    global_best = *std::min_element(positions.begin(), positions.end(), [](double x, double y) { return fitness(x) < fitness(y); });

    std::vector<double> result = optimize(positions, velocities, personal_best, global_best, 0, 100);
    std::cout << "Global Best: " << result[0] << std::endl;
}

int main() {
    main();
    return 0;
}