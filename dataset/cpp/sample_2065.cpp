#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class Particle {
public:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_position;
    double best_score;

    Particle(int dimensions) {
        position.resize(dimensions);
        velocity.resize(dimensions);
        best_position.resize(dimensions);
        best_score = std::numeric_limits<double>::infinity();
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-10.0, 10.0);
        for (int i = 0; i < dimensions; ++i) {
            position[i] = dis(gen);
            velocity[i] = dis(gen) / 10.0;
            best_position[i] = position[i];
        }
    }

    void update_velocity(const std::vector<double>& global_best_position, double w, double c1, double c2) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);
        for (int i = 0; i < velocity.size(); ++i) {
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
            if (position[i] < -10.0) {
                position[i] = -10.0;
            } else if (position[i] > 10.0) {
                position[i] = 10.0;
            }
        }
    }

    void evaluate(double (*objective_function)(const std::vector<double>&)) {
        double score = objective_function(position);
        if (score < best_score) {
            best_score = score;
            best_position = position;
        }
    }
};

class Swarm {
public:
    std::vector<Particle> particles;
    std::vector<double> global_best_position;
    double global_best_score;

    Swarm(int num_particles, int dimensions) {
        particles.resize(num_particles);
        global_best_position.resize(dimensions);
        global_best_score = std::numeric_limits<double>::infinity();
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-10.0, 10.0);
        for (int i = 0; i < dimensions; ++i) {
            global_best_position[i] = dis(gen);
        }
        for (int i = 0; i < num_particles; ++i) {
            particles[i] = Particle(dimensions);
        }
    }

    void update_global_best() {
        for (const auto& particle : particles) {
            if (particle.best_score < global_best_score) {
                global_best_score = particle.best_score;
                global_best_position = particle.best_position;
            }
        }
    }

    void optimize(double (*objective_function)(const std::vector<double>&), double w, double c1, double c2, int iterations) {
        for (int iter = 0; iter < iterations; ++iter) {
            for (auto& particle : particles) {
                particle.update_velocity(global_best_position, w, c1, c2);
                particle.update_position();
                particle.evaluate(objective_function);
            }
            update_global_best();
        }
    }
};

double objective_function(const std::vector<double>& x) {
    double score = 0.0;
    for (double xi : x) {
        score += xi * xi;
    }
    return score;
}

int main() {
    int dimensions = 3;
    int num_particles = 10;
    double w = 0.7;
    double c1 = 1.5;
    double c2 = 1.5;
    int iterations = 50;
    Swarm swarm(num_particles, dimensions);
    swarm.optimize(objective_function, w, c1, c2, iterations);
    std::cout << "Best position: ";
    for (double pos : swarm.global_best_position) {
        std::cout << pos << " ";
    }
    std::cout << std::endl;
    std::cout << "Best score: " << swarm.global_best_score << std::endl;
    return 0;
}