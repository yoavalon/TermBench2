#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>

class Particle {
public:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_position;
    double best_fitness = std::numeric_limits<double>::max();
    double max_velocity;

    Particle(int dimensions, double max_velocity) : max_velocity(max_velocity) {
        position.resize(dimensions, 0.0);
        velocity.resize(dimensions, 0.0);
        best_position.resize(dimensions, 0.0);
    }

    void update_velocity(const std::vector<double>& global_best, double w, double c1, double c2) {
        for (size_t i = 0; i < position.size(); ++i) {
            double r1 = static_cast<double>(rand()) / RAND_MAX;
            double r2 = static_cast<double>(rand()) / RAND_MAX;
            double cognitive = c1 * r1 * (best_position[i] - position[i]);
            double social = c2 * r2 * (global_best[i] - position[i]);
            velocity[i] = w * velocity[i] + cognitive + social;
            velocity[i] = std::max(-max_velocity, std::min(velocity[i], max_velocity));
        }
    }

    void update_position() {
        for (size_t i = 0; i < position.size(); ++i) {
            position[i] += velocity[i];
        }
    }

    void evaluate(double (*objective_function)(const std::vector<double>&)) {
        fitness = objective_function(position);
        if (fitness < best_fitness) {
            best_fitness = fitness;
            best_position = position;
        }
    }
};

class Swarm {
public:
    std::vector<Particle> particles;
    std::vector<double> global_best;
    double global_best_fitness = std::numeric_limits<double>::max();

    Swarm(int dimensions, int population_size, double max_velocity) {
        particles.resize(population_size);
        for (auto& particle : particles) {
            particle = Particle(dimensions, max_velocity);
        }
        global_best.resize(dimensions, 0.0);
    }

    void initialize_global_best(double (*objective_function)(const std::vector<double>&)) {
        for (auto& particle : particles) {
            particle.evaluate(objective_function);
            if (particle.best_fitness < global_best_fitness) {
                global_best_fitness = particle.best_fitness;
                global_best = particle.best_position;
            }
        }
    }

    void update_swarm(double w, double c1, double c2, double (*objective_function)(const std::vector<double>&)) {
        for (auto& particle : particles) {
            particle.update_velocity(global_best, w, c1, c2);
            particle.update_position();
            particle.evaluate(objective_function);
            if (particle.best_fitness < global_best_fitness) {
                global_best_fitness = particle.best_fitness;
                global_best = particle.best_position;
            }
        }
    }
};

double objective_function(const std::vector<double>& position) {
    double sum = 0.0;
    for (double x : position) {
        sum += x * x;
    }
    return sum;
}

double optimize(int dimensions, int population_size, double max_velocity, double w, double c1, double c2, int max_iterations) {
    Swarm swarm(dimensions, population_size, max_velocity);
    swarm.initialize_global_best(objective_function);
    for (int i = 0; i < max_iterations; ++i) {
        swarm.update_swarm(w, c1, c2, objective_function);
    }
    return swarm.global_best_fitness;
}

int main() {
    int dimensions = 2;
    int population_size = 30;
    double max_velocity = 0.1;
    double w = 0.729;
    double c1 = 1.494;
    double c2 = 1.494;
    int max_iterations = 100;
    double best_fitness = optimize(dimensions, population_size, max_velocity, w, c1, c2, max_iterations);
    std::cout << 'Best Fitness: ' << best_fitness << std::endl;
    return 0;
}