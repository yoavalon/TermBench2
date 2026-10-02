#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

double fitness(const std::vector<double>& position) {
    double sum = 0.0;
    for (double x : position) {
        sum += x * x;
    }
    return sum;
}

void update_velocity(std::vector<std::vector<double>>& particles, std::vector<std::vector<double>>& velocities, 
                    const std::vector<std::vector<double>>& pbest, const std::vector<double>& gbest, 
                    double w, double c1, double c2) {
    for (size_t i = 0; i < particles.size(); ++i) {
        for (size_t j = 0; j < particles[i].size(); ++j) {
            double r1 = ((double)rand() / RAND_MAX);
            double r2 = ((double)rand() / RAND_MAX);
            velocities[i][j] = w * velocities[i][j] + c1 * r1 * (pbest[i][j] - particles[i][j]) + c2 * r2 * (gbest[j] - particles[i][j]);
        }
    }
}

void update_position(std::vector<std::vector<double>>& particles, const std::vector<std::vector<double>>& velocities) {
    for (size_t i = 0; i < particles.size(); ++i) {
        for (size_t j = 0; j < particles[i].size(); ++j) {
            particles[i][j] += velocities[i][j];
        }
    }
}

void optimize(std::vector<std::vector<double>>& particles, std::vector<std::vector<double>>& velocities, 
              const std::vector<std::vector<double>>& pbest, const std::vector<double>& gbest, 
              double w, double c1, double c2) {
    update_velocity(particles, velocities, pbest, gbest, w, c1, c2);
    update_position(particles, velocities);
    optimize(particles, velocities, pbest, gbest, w, c1, c2);
}

int main() {
    std::srand(std::time(0));
    int num_particles = 10;
    int dimensions = 2;
    std::vector<std::vector<double>> particles(num_particles, std::vector<double>(dimensions));
    std::vector<std::vector<double>> velocities(num_particles, std::vector<double>(dimensions));
    std::vector<std::vector<double>> pbest(num_particles, std::vector<double>(dimensions));
    std::vector<double> gbest(dimensions);

    for (int i = 0; i < num_particles; ++i) {
        for (int j = 0; j < dimensions; ++j) {
            particles[i][j] = (double)(rand() % 201 - 100) / 10.0;
            velocities[i][j] = (double)(rand() % 201 - 100) / 100.0;
            pbest[i][j] = particles[i][j];
        }
    }

    gbest = *std::min_element(particles.begin(), particles.end(), [](const std::vector<double>& a, const std::vector<double>& b) {
        return fitness(a) < fitness(b);
    });

    double w = 0.7, c1 = 1.5, c2 = 1.5;
    optimize(particles, velocities, pbest, gbest, w, c1, c2);

    return 0;
}