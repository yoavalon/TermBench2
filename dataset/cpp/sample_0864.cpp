#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <random>

class Particle {
public:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_position;
    double best_score;

    Particle(int dimensions) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-10.0, 10.0);
        std::uniform_real_distribution<> vel_dis(-1.0, 1.0);

        position = std::vector<double>(dimensions);
        velocity = std::vector<double>(dimensions);
        best_position = std::vector<double>(dimensions);

        for (int i = 0; i < dimensions; ++i) {
            position[i] = dis(gen);
            velocity[i] = vel_dis(gen);
            best_position[i] = position[i];
        }
        best_score = std::numeric_limits<double>::infinity();
    }

    void update_velocity(const std::vector<double>& global_best_position, double w, double c1, double c2) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);

        for (int i = 0; i < position.size(); ++i) {
            double r1 = dis(gen);
            double r2 = dis(gen);
            double cognitive = c1 * r1 * (best_position[i] - position[i]);
            double social = c2 * r2 * (global_best_position[i] - position[i]);
            velocity[i] = w * velocity[i] + cognitive + social;
        }
    }

    void update_position() {
        for (int i = 0; i < position.size(); ++i) {
            position[i] += velocity[i];
        }
    }

    double evaluate(const std::function<double(const std::vector<double>&)>& fitness_function) {
        best_score = fitness_function(position);
        return best_score;
    }
};

class Swarm {
public:
    std::vector<Particle> particles;
    std::vector<double> global_best_position;
    double global_best_score;

    Swarm(int num_particles, int dimensions) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-10.0, 10.0);

        particles = std::vector<Particle>(num_particles);
        global_best_position = std::vector<double>(dimensions);

        for (int i = 0; i < dimensions; ++i) {
            global_best_position[i] = dis(gen);
        }
        global_best_score = std::numeric_limits<double>::infinity();
    }

    void update_global_best() {
        for (const auto& particle : particles) {
            if (particle.best_score < global_best_score) {
                global_best_score = particle.best_score;
                global_best_position = particle.best_position;
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

std::pair<std::vector<double>, double> optimize(Swarm& swarm, double w, double c1, double c2, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        for (auto& particle : swarm.particles) {
            particle.update_velocity(swarm.global_best_position, w, c1, c2);
            particle.update_position();
            particle.evaluate(fitness_function);
        }
        swarm.update_global_best();
    }
    return {swarm.global_best_position, swarm.global_best_score};
}

int main() {
    int dimensions = 10;
    int num_particles = 20;
    double w = 0.7;
    double c1 = 2.0;
    double c2 = 2.0;
    int iterations = 100;

    Swarm swarm(num_particles, dimensions);
    auto [best_position, best_score] = optimize(swarm, w, c1, c2, iterations);

    std::cout << "Best position: ";
    for (double pos : best_position) {
        std::cout << pos << " ";
    }
    std::cout << std::endl;

    std::cout << "Best score: " << best_score << std::endl;

    return 0;
}