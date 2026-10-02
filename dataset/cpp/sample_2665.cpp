#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <limits>

class Particle {
public:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_position;
    double best_fitness;

    Particle(int dimensions, const std::vector<std::pair<double, double>>& bounds) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);

        for (const auto& b : bounds) {
            position.push_back(dis(gen) * (b.second - b.first) + b.first);
            velocity.push_back(dis(gen) * 2.0 - 1.0);
        }
        best_position = position;
        best_fitness = std::numeric_limits<double>::infinity();
    }

    void update_velocity(const std::vector<double>& global_best, double w, double c1, double c2) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);

        for (size_t i = 0; i < position.size(); ++i) {
            double r1 = dis(gen);
            double r2 = dis(gen);
            double cognitive = c1 * r1 * (best_position[i] - position[i]);
            double social = c2 * r2 * (global_best[i] - position[i]);
            velocity[i] = w * velocity[i] + cognitive + social;
        }
    }

    void update_position(const std::vector<std::pair<double, double>>& bounds) {
        for (size_t i = 0; i < position.size(); ++i) {
            position[i] += velocity[i];
            position[i] = std::max(bounds[i].first, std::min(position[i], bounds[i].second));
        }
    }

    void evaluate(double (*fitness_function)(const std::vector<double>&)) {
        best_fitness = std::min(best_fitness, fitness_function(position));
    }
};

std::pair<std::vector<double>, double> optimize(double (*fitness_function)(const std::vector<double>&),
                                               int dimensions,
                                               const std::vector<std::pair<double, double>>& bounds,
                                               int num_particles,
                                               double w,
                                               double c1,
                                               double c2,
                                               int max_iterations) {
    std::vector<Particle> particles;
    for (int i = 0; i < num_particles; ++i) {
        particles.emplace_back(dimensions, bounds);
    }

    std::vector<double> global_best(dimensions, std::numeric_limits<double>::infinity());
    double global_best_fitness = std::numeric_limits<double>::infinity();

    for (int iter = 0; iter < max_iterations; ++iter) {
        for (auto& particle : particles) {
            particle.evaluate(fitness_function);
            if (particle.best_fitness < global_best_fitness) {
                global_best_fitness = particle.best_fitness;
                global_best = particle.best_position;
            }
        }
        for (auto& particle : particles) {
            particle.update_velocity(global_best, w, c1, c2);
            particle.update_position(bounds);
        }
    }
    return {global_best, global_best_fitness};
}

double sphere_function(const std::vector<double>& x) {
    double sum = 0.0;
    for (double xi : x) {
        sum += xi * xi;
    }
    return sum;
}

int main() {
    int dimensions = 3;
    std::vector<std::pair<double, double>> bounds(3, {-5.12, 5.12});
    int num_particles = 30;
    double w = 0.729;
    double c1 = 1.494;
    double c2 = 1.494;
    int max_iterations = 100;

    auto [best_position, best_fitness] = optimize(sphere_function, dimensions, bounds, num_particles, w, c1, c2, max_iterations);
    std::cout << "Best position: ";
    for (double pos : best_position) {
        std::cout << pos << " ";
    }
    std::cout << "\nBest fitness: " << best_fitness << std::endl;

    return 0;
}