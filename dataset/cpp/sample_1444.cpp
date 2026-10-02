#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <ctime>

class Particle {
public:
    Particle(int dimensions, const std::vector<double>& bounds) {
        position.resize(dimensions);
        velocity.resize(dimensions);
        best_position.resize(dimensions);
        for (int i = 0; i < dimensions; ++i) {
            position[i] = bounds[0] + (bounds[1] - bounds[0]) * static_cast<double>(rand()) / RAND_MAX;
            velocity[i] = -1.0 + 2.0 * static_cast<double>(rand()) / RAND_MAX;
        }
        best_position = position;
        best_score = std::numeric_limits<double>::infinity();
    }

    void update_velocity(const std::vector<double>& global_best, double w = 0.7, double c1 = 1.5, double c2 = 1.5) {
        for (int i = 0; i < velocity.size(); ++i) {
            double r1 = static_cast<double>(rand()) / RAND_MAX;
            double r2 = static_cast<double>(rand()) / RAND_MAX;
            velocity[i] = w * velocity[i] + c1 * r1 * (best_position[i] - position[i]) + c2 * r2 * (global_best[i] - position[i]);
        }
    }

    void update_position(const std::vector<double>& bounds) {
        for (int i = 0; i < position.size(); ++i) {
            position[i] += velocity[i];
            position[i] = std::max(bounds[0], std::min(bounds[1], position[i]));
        }
    }

    double evaluate(const std::function<double(const std::vector<double>&)>& objective_function) {
        double score = objective_function(position);
        if (score < best_score) {
            best_score = score;
            best_position = position;
        }
        return score;
    }

private:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_position;
    double best_score;
};

class Swarm {
public:
    Swarm(int num_particles, int dimensions, const std::vector<double>& bounds) {
        for (int i = 0; i < num_particles; ++i) {
            particles.emplace_back(dimensions, bounds);
        }
        global_best_position = particles[0].best_position;
        global_best_score = particles[0].best_score;
    }

    void update_global_best() {
        for (const auto& particle : particles) {
            if (particle.best_score < global_best_score) {
                global_best_score = particle.best_score;
                global_best_position = particle.best_position;
            }
        }
    }

    void iterate(const std::function<double(const std::vector<double>&)>& objective_function) {
        for (auto& particle : particles) {
            particle.update_velocity(global_best_position);
            particle.update_position(objective_function.bounds);
            particle.evaluate(objective_function);
        }
        update_global_best();
    }

private:
    std::vector<Particle> particles;
    std::vector<double> global_best_position;
    double global_best_score;
};

class ObjectiveFunction {
public:
    ObjectiveFunction(const std::vector<double>& bounds) : bounds(bounds) {}

    double operator()(const std::vector<double>& position) const {
        double x = position[0];
        double y = position[1];
        return std::pow(x * x + y - 11, 2) + std::pow(x + y * y - 7, 2);
    }

    std::vector<double> bounds;
};

void main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int dimensions = 2;
    int num_particles = 30;
    std::vector<double> bounds = {-5, 5};
    ObjectiveFunction objective_function(bounds);
    Swarm swarm(num_particles, dimensions, bounds);
    for (int i = 0; i < 100; ++i) {
        swarm.iterate(objective_function);
        if (swarm.global_best_score < 1e-06) {
            break;
        }
    }
    std::cout << "Best position: ";
    for (double pos : swarm.global_best_position) {
        std::cout << pos << " ";
    }
    std::cout << std::endl;
    std::cout << "Best score: " << swarm.global_best_score << std::endl;
}