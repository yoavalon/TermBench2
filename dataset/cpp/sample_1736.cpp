#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

class Particle {
public:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_position;

    Particle(int dimensions) {
        position.resize(dimensions);
        velocity.resize(dimensions);
        best_position.resize(dimensions);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-10, 10);
        for (int i = 0; i < dimensions; ++i) {
            position[i] = dis(gen);
            velocity[i] = dis(gen);
            best_position[i] = position[i];
        }
    }

    void update_velocity(const std::vector<double>& global_best, double inertia, double cognitive, double social) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0, 1);
        for (int i = 0; i < velocity.size(); ++i) {
            double r1 = dis(gen);
            double r2 = dis(gen);
            velocity[i] = inertia * velocity[i] + cognitive * r1 * (best_position[i] - position[i]) + social * r2 * (global_best[i] - position[i]);
        }
    }

    void update_position() {
        for (int i = 0; i < position.size(); ++i) {
            position[i] += velocity[i];
        }
    }

    void update_best_position(double (*objective_function)(const std::vector<double>&)) {
        double current_fitness = objective_function(position);
        double best_fitness = objective_function(best_position);
        if (current_fitness < best_fitness) {
            best_position = position;
        }
    }
};

class Swarm {
public:
    std::vector<Particle> particles;
    std::vector<double> global_best;
    double (*objective_function)(const std::vector<double>&);

    Swarm(int dimensions, int num_particles, double (*objective_function)(const std::vector<double>&)) {
        particles.resize(num_particles);
        global_best.resize(dimensions);
        this->objective_function = objective_function;
        for (int i = 0; i < num_particles; ++i) {
            particles[i] = Particle(dimensions);
        }
        global_best = particles[0].position;
    }

    void update_global_best() {
        for (const auto& particle : particles) {
            double current_fitness = objective_function(particle.position);
            double global_best_fitness = objective_function(global_best);
            if (current_fitness < global_best_fitness) {
                global_best = particle.position;
            }
        }
    }

    void optimize(double inertia, double cognitive, double social) {
        while (true) {
            for (auto& particle : particles) {
                particle.update_velocity(global_best, inertia, cognitive, social);
                particle.update_position();
                particle.update_best_position(objective_function);
            }
            update_global_best();
        }
    }
};

double objective_function(const std::vector<double>& x) {
    double sum = 0;
    for (double xi : x) {
        sum += xi * xi;
    }
    return sum;
}

int main() {
    int dimensions = 2;
    int num_particles = 30;
    double inertia = 0.7;
    double cognitive = 1.5;
    double social = 1.5;
    Swarm swarm(dimensions, num_particles, objective_function);
    swarm.optimize(inertia, cognitive, social);
    return 0;
}