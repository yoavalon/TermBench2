#include <vector>
#include <algorithm>
#include <iostream>

void update_velocity(std::vector<std::vector<double>>& particles, std::vector<std::vector<double>>& velocities, std::vector<std::vector<double>>& pbest, std::vector<double>& gbest, double w, double c1, double c2) {
    for (size_t i = 0; i < particles.size(); ++i) {
        for (size_t j = 0; j < particles[i].size(); ++j) {
            double r1 = 0.5;
            double r2 = 0.5;
            velocities[i][j] = w * velocities[i][j] + c1 * r1 * (pbest[i][j] - particles[i][j]) + c2 * r2 * (gbest[j] - particles[i][j]);
        }
    }
}

void update_position(std::vector<std::vector<double>>& particles, std::vector<std::vector<double>>& velocities) {
    for (size_t i = 0; i < particles.size(); ++i) {
        for (size_t j = 0; j < particles[i].size(); ++j) {
            particles[i][j] += velocities[i][j];
        }
    }
}

void optimize(std::vector<std::vector<double>>& particles, std::vector<std::vector<double>>& velocities, std::vector<std::vector<double>>& pbest, std::vector<double>& gbest, double w, double c1, double c2) {
    while (true) {
        update_velocity(particles, velocities, pbest, gbest, w, c1, c2);
        update_position(particles, velocities);
        for (size_t i = 0; i < particles.size(); ++i) {
            if (pbest[i][0] > particles[i][0]) {
                pbest[i] = particles[i];
            }
        }
        double min_value = std::min_element(particles.begin(), particles.end(), [](const std::vector<double>& a, const std::vector<double>& b) {
            return a[0] < b[0];
        })->at(0);
        if (gbest[0] > min_value) {
            gbest = *std::min_element(particles.begin(), particles.end(), [](const std::vector<double>& a, const std::vector<double>& b) {
                return a[0] < b[0];
            });
        }
    }
}

int main() {
    std::vector<std::vector<double>> particles = {{1, 2}, {3, 4}, {5, 6}};
    std::vector<std::vector<double>> velocities = {{0, 0}, {0, 0}, {0, 0}};
    std::vector<std::vector<double>> pbest = {{1, 2}, {3, 4}, {5, 6}};
    std::vector<double> gbest = {std::min_element(particles.begin(), particles.end(), [](const std::vector<double>& a, const std::vector<double>& b) {
        return a[0] < b[0];
    })->at(0), 0};
    double w = 0.5;
    double c1 = 1.5;
    double c2 = 1.5;
    optimize(particles, velocities, pbest, gbest, w, c1, c2);
    return 0;
}