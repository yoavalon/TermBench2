#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

class Particle {
public:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> pbest;
    double pbest_value;

    Particle(int dim) : position(dim, 0.0), velocity(dim, 0.0), pbest(dim, 0.0), pbest_value(std::numeric_limits<double>::infinity()) {}

    void update_velocity(const std::vector<double>& gbest, double w = 0.7, double c1 = 1.5, double c2 = 1.5) {
        for (int i = 0; i < position.size(); ++i) {
            double r1 = 0.5, r2 = 0.5;
            velocity[i] = w * velocity[i] + c1 * r1 * (pbest[i] - position[i]) + c2 * r2 * (gbest[i] - position[i]);
        }
    }

    void update_position(const std::vector<std::pair<double, double>>& bounds) {
        for (int i = 0; i < position.size(); ++i) {
            position[i] += velocity[i];
            position[i] = std::max(bounds[i].first, std::min(bounds[i].second, position[i]));
        }
    }

    void update_pbest(double value) {
        if (value < pbest_value) {
            pbest = position;
            pbest_value = value;
        }
    }
};

class Swarm {
public:
    std::vector<Particle> particles;
    std::vector<double> gbest;
    double gbest_value;
    std::vector<std::pair<double, double>> bounds;

    Swarm(int num_particles, int dim, const std::vector<std::pair<double, double>>& bounds) 
        : particles(num_particles, Particle(dim)), gbest(dim, 0.0), gbest_value(std::numeric_limits<double>::infinity()), bounds(bounds) {}

    void update_gbest() {
        for (const auto& particle : particles) {
            if (particle.pbest_value < gbest_value) {
                gbest = particle.pbest;
                gbest_value = particle.pbest_value;
            }
        }
    }

    void iterate() {
        for (auto& particle : particles) {
            particle.update_velocity(gbest);
            particle.update_position(bounds);
            particle.update_pbest(objective_function(particle.position));
        }
    }
};

double objective_function(const std::vector<double>& x) {
    double sum = 0.0;
    for (double xi : x) {
        sum += xi * xi;
    }
    return sum;
}

std::pair<std::vector<double>, double> optimize(int num_particles, int dim, int max_iterations, const std::vector<std::pair<double, double>>& bounds) {
    Swarm swarm(num_particles, dim, bounds);
    for (int i = 0; i < max_iterations; ++i) {
        swarm.iterate();
        swarm.update_gbest();
    }
    return {swarm.gbest, swarm.gbest_value};
}

void main() {
    int num_particles = 30;
    int dim = 2;
    int max_iterations = 100;
    std::vector<std::pair<double, double>> bounds(dim, {-10, 10});
    auto [best_position, best_value] = optimize(num_particles, dim, max_iterations, bounds);
    std::cout << "Best position: ";
    for (double pos : best_position) {
        std::cout << pos << " ";
    }
    std::cout << std::endl;
    std::cout << "Best value: " << best_value << std::endl;
}

int main() {
    main();
    return 0;
}