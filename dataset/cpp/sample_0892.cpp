#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

double sphere_function(const std::vector<double>& x) {
    double sum = 0.0;
    for (double xi : x) {
        sum += xi * xi;
    }
    return sum;
}

std::vector<std::vector<double>> initialize_particles(int size, int dimensions, double lower_bound, double upper_bound) {
    std::vector<std::vector<double>> particles(size, std::vector<double>(dimensions));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(lower_bound, upper_bound);
    for (int i = 0; i < size; ++i) {
        for (int d = 0; d < dimensions; ++d) {
            particles[i][d] = dis(gen);
        }
    }
    return particles;
}

std::vector<double> evaluate_fitness(const std::vector<std::vector<double>>& particles, double (*objective_function)(const std::vector<double>&)) {
    std::vector<double> fitness(particles.size());
    for (int i = 0; i < particles.size(); ++i) {
        fitness[i] = objective_function(particles[i]);
    }
    return fitness;
}

std::pair<std::vector<std::vector<double>>, std::vector<std::vector<double>>> update_particles(const std::vector<std::vector<double>>& particles, const std::vector<std::vector<double>>& velocities, const std::vector<std::vector<double>>& pbest, const std::vector<double>& gbest, double w, double c1, double c2) {
    std::vector<std::vector<double>> new_particles(particles.size(), std::vector<double>(particles[0].size()));
    std::vector<std::vector<double>> new_velocities(velocities.size(), std::vector<double>(velocities[0].size()));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < particles.size(); ++i) {
        double r1 = dis(gen);
        double r2 = dis(gen);
        for (int d = 0; d < particles[i].size(); ++d) {
            new_velocities[i][d] = w * velocities[i][d] + c1 * r1 * (pbest[i][d] - particles[i][d]) + c2 * r2 * (gbest[d] - particles[i][d]);
            new_particles[i][d] = particles[i][d] + new_velocities[i][d];
        }
    }
    return {new_particles, new_velocities};
}

std::pair<std::vector<double>, double> optimize(double (*objective_function)(const std::vector<double>&), int dimensions, std::pair<double, double> bounds, int size, int iterations, double w, double c1, double c2) {
    std::vector<std::vector<double>> particles = initialize_particles(size, dimensions, bounds.first, bounds.second);
    std::vector<std::vector<double>> velocities(size, std::vector<double>(dimensions, 0.0));
    std::vector<std::vector<double>> pbest = particles;
    std::vector<double> pbest_fitness = evaluate_fitness(pbest, objective_function);
    std::vector<double> gbest = pbest[std::distance(pbest_fitness.begin(), std::min_element(pbest_fitness.begin(), pbest_fitness.end()))];
    double gbest_fitness = *std::min_element(pbest_fitness.begin(), pbest_fitness.end());
    for (int iter = 0; iter < iterations; ++iter) {
        auto [new_particles, new_velocities] = update_particles(particles, velocities, pbest, gbest, w, c1, c2);
        particles = new_particles;
        velocities = new_velocities;
        std::vector<double> fitness = evaluate_fitness(particles, objective_function);
        for (int i = 0; i < size; ++i) {
            if (fitness[i] < pbest_fitness[i]) {
                pbest[i] = particles[i];
                pbest_fitness[i] = fitness[i];
            }
        }
        if (*std::min_element(fitness.begin(), fitness.end()) < gbest_fitness) {
            gbest = particles[std::distance(fitness.begin(), std::min_element(fitness.begin(), fitness.end()))];
            gbest_fitness = *std::min_element(fitness.begin(), fitness.end());
        }
    }
    return {gbest, gbest_fitness};
}

int main() {
    int dimensions = 2;
    std::pair<double, double> bounds = {-10.0, 10.0};
    int size = 30;
    int iterations = 100;
    double w = 0.7;
    double c1 = 1.5;
    double c2 = 1.5;
    auto [best_solution, best_fitness] = optimize(sphere_function, dimensions, bounds, size, iterations, w, c1, c2);
    std::cout << "Best solution: ";
    for (double x : best_solution) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << "Best fitness: " << best_fitness << std::endl;
    return 0;
}