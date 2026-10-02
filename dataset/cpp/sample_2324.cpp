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
    double best_fitness;

    Particle(int dim, double lb, double ub) {
        position.resize(dim);
        velocity.resize(dim);
        best_position.resize(dim);
        best_fitness = std::numeric_limits<double>::infinity();
        for (int i = 0; i < dim; ++i) {
            position[i] = lb + static_cast<double>(rand()) / RAND_MAX * (ub - lb);
            velocity[i] = -1.0 + static_cast<double>(rand()) / RAND_MAX * 2.0;
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

    void update_position(double lb, double ub) {
        for (int i = 0; i < position.size(); ++i) {
            position[i] += velocity[i];
            if (position[i] < lb) {
                position[i] = lb;
            }
            if (position[i] > ub) {
                position[i] = ub;
            }
        }
    }
};

double fitness_function(const std::vector<double>& x) {
    double sum = 0.0;
    for (double xi : x) {
        sum += xi * xi;
    }
    return sum;
}

std::pair<std::vector<double>, double> optimize(int dim, double lb, double ub, int num_particles, double w, double c1, double c2, int max_iter) {
    std::vector<Particle> particles(num_particles);
    std::vector<double> global_best(dim, std::numeric_limits<double>::infinity());
    double global_best_fitness = std::numeric_limits<double>::infinity();

    for (int iter = 0; iter < max_iter; ++iter) {
        for (auto& particle : particles) {
            double current_fitness = fitness_function(particle.position);
            if (current_fitness < particle.best_fitness) {
                particle.best_fitness = current_fitness;
                particle.best_position = particle.position;
            }
            if (current_fitness < global_best_fitness) {
                global_best_fitness = current_fitness;
                global_best = particle.position;
            }
        }
        for (auto& particle : particles) {
            particle.update_velocity(global_best, w, c1, c2);
            particle.update_position(lb, ub);
        }
    }
    return {global_best, global_best_fitness};
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int dim = 30;
    double lb = -100, ub = 100;
    int num_particles = 50;
    double w = 0.7, c1 = 1.5, c2 = 1.5;
    int max_iter = 10000;

    auto [best_position, best_fitness] = optimize(dim, lb, ub, num_particles, w, c1, c2, max_iter);
    std::cout << "Best position: ";
    for (double pos : best_position) {
        std::cout << pos << " ";
    }
    std::cout << std::endl;
    std::cout << "Best fitness: " << best_fitness << std::endl;

    return 0;
}