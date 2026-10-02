#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

class Particle {
public:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_position;
    double best_score;

    Particle(int dimensions, const std::vector<std::pair<double, double>>& bounds) {
        position.resize(dimensions);
        velocity.resize(dimensions);
        best_position.resize(dimensions);
        best_score = std::numeric_limits<double>::infinity();

        for (int i = 0; i < dimensions; ++i) {
            position[i] = bounds[i].first + static_cast<double>(rand()) / RAND_MAX * (bounds[i].second - bounds[i].first);
            velocity[i] = -1 + static_cast<double>(rand()) / RAND_MAX * 2;
            best_position[i] = position[i];
        }
    }

    void update_velocity(const std::vector<double>& global_best, double w, double c1, double c2) {
        for (int i = 0; i < velocity.size(); ++i) {
            double r1 = static_cast<double>(rand()) / RAND_MAX;
            double r2 = static_cast<double>(rand()) / RAND_MAX;
            double cognitive = c1 * r1 * (best_position[i] - position[i]);
            double social = c2 * r2 * (global_best[i] - position[i]);
            velocity[i] = w * velocity[i] + cognitive + social;
        }
    }

    void update_position(const std::vector<std::pair<double, double>>& bounds) {
        for (int i = 0; i < position.size(); ++i) {
            position[i] += velocity[i];
            position[i] = std::max(bounds[i].first, std::min(bounds[i].second, position[i]));
        }
    }
};

class Swarm {
public:
    std::vector<Particle> particles;
    std::vector<double> best_position;
    double best_score;
    std::function<double(const std::vector<double>&)> function;

    Swarm(int num_particles, int dimensions, const std::vector<std::pair<double, double>>& bounds, std::function<double(const std::vector<double>&)> function)
        : function(function) {
        particles.resize(num_particles);
        best_score = std::numeric_limits<double>::infinity();

        for (int i = 0; i < num_particles; ++i) {
            particles[i] = Particle(dimensions, bounds);
        }
    }

    void optimize(int max_iterations, double w, double c1, double c2) {
        for (int iteration = 0; iteration < max_iterations; ++iteration) {
            for (auto& particle : particles) {
                double score = function(particle.position);
                if (score < particle.best_score) {
                    particle.best_score = score;
                    particle.best_position = particle.position;
                }
                if (score < best_score) {
                    best_score = score;
                    best_position = particle.position;
                }
            }
            for (auto& particle : particles) {
                particle.update_velocity(best_position, w, c1, c2);
                particle.update_position(particles[0].position);
            }
        }
    }
};

double objective_function(const std::vector<double>& x) {
    double sum = 0;
    for (double xi : x) {
        sum += std::pow(xi - 2, 2);
    }
    return sum;
}

int main() {
    int dimensions = 3;
    std::vector<std::pair<double, double>> bounds(dimensions, std::make_pair(-10.0, 10.0));
    int num_particles = 20;
    int max_iterations = 100;
    double w = 0.7;
    double c1 = 1.5;
    double c2 = 1.5;

    srand(time(0));
    Swarm swarm(num_particles, dimensions, bounds, objective_function);
    swarm.optimize(max_iterations, w, c1, c2);

    for (double val : swarm.best_position) {
        std::cout << val << " ";
    }
    std::cout << swarm.best_score << std::endl;

    return 0;
}