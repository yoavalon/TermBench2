#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

std::vector<std::vector<double>> initialize_particles(int num_particles, int dimensions) {
    std::vector<std::vector<double>> particles(num_particles, std::vector<double>(dimensions));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1.0, 1.0);
    for (int i = 0; i < num_particles; ++i) {
        for (int j = 0; j < dimensions; ++j) {
            particles[i][j] = dis(gen);
        }
    }
    return particles;
}

double evaluate_fitness(const std::vector<double>& position, const std::vector<double>& target) {
    double sum = 0.0;
    for (size_t i = 0; i < position.size(); ++i) {
        sum += std::pow(position[i] - target[i], 2);
    }
    return sum;
}

std::vector<double> update_velocity(const std::vector<double>& velocity, const std::vector<double>& position, 
                                     const std::vector<double>& p_best, const std::vector<double>& g_best, 
                                     double w, double c1, double c2) {
    std::vector<double> new_velocity(position.size());
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    double r1 = dis(gen);
    double r2 = dis(gen);
    for (size_t i = 0; i < velocity.size(); ++i) {
        new_velocity[i] = w * velocity[i] + c1 * r1 * (p_best[i] - position[i]) + c2 * r2 * (g_best[i] - position[i]);
    }
    return new_velocity;
}

std::vector<double> update_position(const std::vector<double>& position, const std::vector<double>& velocity) {
    std::vector<double> new_position(position.size());
    for (size_t i = 0; i < position.size(); ++i) {
        new_position[i] = position[i] + velocity[i];
    }
    return new_position;
}

std::vector<double> particle_swarm(int num_particles, int dimensions, const std::vector<double>& target, int max_iterations) {
    std::vector<std::vector<double>> particles = initialize_particles(num_particles, dimensions);
    std::vector<std::vector<double>> velocities(num_particles, std::vector<double>(dimensions, 0.0));
    std::vector<std::vector<double>> p_best = particles;
    auto comp = [&target](const std::vector<double>& a, const std::vector<double>& b) {
        return evaluate_fitness(a, target) < evaluate_fitness(b, target);
    };
    std::vector<double> g_best = *std::min_element(particles.begin(), particles.end(), comp);
    for (int iter = 0; iter < max_iterations; ++iter) {
        for (int i = 0; i < num_particles; ++i) {
            if (evaluate_fitness(particles[i], target) < evaluate_fitness(p_best[i], target)) {
                p_best[i] = particles[i];
            }
        }
        g_best = *std::min_element(p_best.begin(), p_best.end(), comp);
        for (int i = 0; i < num_particles; ++i) {
            velocities[i] = update_velocity(velocities[i], particles[i], p_best[i], g_best, 0.7, 1.5, 1.5);
            particles[i] = update_position(particles[i], velocities[i]);
        }
    }
    return g_best;
}

int main() {
    std::vector<double> target = {0, 0};
    std::vector<double> result = particle_swarm(30, 2, target, 100);
    for (double val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}