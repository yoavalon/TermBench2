#include <iostream>
#include <vector>
#include <random>
#include <cmath>

class Particle {
public:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_position;
    double best_value;

    Particle(int dimensions) {
        position.resize(dimensions);
        velocity.resize(dimensions);
        best_position.resize(dimensions);
        best_value = std::numeric_limits<double>::infinity();

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-1.0, 1.0);

        for (int i = 0; i < dimensions; ++i) {
            position[i] = dis(gen);
            velocity[i] = dis(gen);
            best_position[i] = position[i];
        }
    }

    void update_velocity(const std::vector<double>& global_best, double w = 0.7, double c1 = 1.5, double c2 = 1.5) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);

        for (int i = 0; i < position.size(); ++i) {
            double r1 = dis(gen);
            double r2 = dis(gen);
            double cognitive = c1 * r1 * (best_position[i] - position[i]);
            double social = c2 * r2 * (global_best[i] - position[i]);
            velocity[i] = w * velocity[i] + cognitive + social;
        }
    }

    void update_position() {
        for (int i = 0; i < position.size(); ++i) {
            position[i] += velocity[i];
        }
    }

    void evaluate(double (*objective_function)(const std::vector<double>&)) {
        best_value = objective_function(position);
        if (best_value < best_value) {
            best_position = position;
        }
    }
};

class Swarm {
public:
    std::vector<Particle> particles;
    std::vector<double> global_best;
    double global_best_value;

    Swarm(int dimensions, int num_particles) {
        particles.resize(num_particles);
        global_best.resize(dimensions, std::numeric_limits<double>::infinity());
        global_best_value = std::numeric_limits<double>::infinity();

        for (int i = 0; i < num_particles; ++i) {
            particles[i] = Particle(dimensions);
        }
    }

    void update_global_best() {
        for (const auto& particle : particles) {
            if (particle.best_value < global_best_value) {
                global_best_value = particle.best_value;
                global_best = particle.best_position;
            }
        }
    }

    void iterate(double (*objective_function)(const std::vector<double>&)) {
        for (auto& particle : particles) {
            particle.update_velocity(global_best);
            particle.update_position();
            particle.evaluate(objective_function);
        }
        update_global_best();
    }
};

double objective_function(const std::vector<double>& x) {
    double sum = 0.0;
    for (double xi : x) {
        sum += xi * xi;
    }
    return sum;
}

std::vector<double> optimize(int dimensions, int num_particles, int max_iterations) {
    Swarm swarm(dimensions, num_particles);
    for (int i = 0; i < max_iterations; ++i) {
        swarm.iterate(objective_function);
    }
    return swarm.global_best;
}

int main() {
    int dimensions = 10;
    int num_particles = 20;
    int max_iterations = 100;
    std::vector<double> best_solution = optimize(dimensions, num_particles, max_iterations);
    std::cout << "Best solution: ";
    for (double val : best_solution) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}